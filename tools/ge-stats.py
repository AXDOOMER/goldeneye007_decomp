import re
import os

# --------------------------
# Read Map File and return
# all function lenghts
# --------------------------
def parse_map():
    
    infile = False
    prevromaddr = 0
    lengths = {}

    p1 = re.compile(r"^ \.text\s+0x00000000([0-9a-f]{8})\s+0x([0-9a-f]+)\s+build\/u\/(.*)\/\S+.\w$")
    p2 = re.compile(r"\s+0x00000000([0-9a-f]{8})\s+(\S+)$")

    map_file = open('build/ge007.u.map', 'r')
    lines = map_file.readlines()

    for line in lines:

        m1 = p1.findall(line)
        m2 = p2.findall(line)

        if m1:
            filestart = int(m1[0][0], 16)
            filelen = int(m1[0][1], 16)
            segment = m1[0][2]
            infile = True
            prevromaddr = 0
            prevfuncname = None

            if segment not in lengths.keys():
                lengths[segment] = {}

        elif infile and m2:
            romaddr = int(m2[0][0], 16)
            funcname = m2[0][1]

            if prevfuncname:
                lengths[segment][prevfuncname] = romaddr - prevromaddr

            prevromaddr = romaddr
            prevfuncname = funcname

        elif infile:
            infile = False

            if prevfuncname:
                lengths[segment][prevfuncname] = (filestart + filelen) - prevromaddr

    return lengths

# --------------------------
# Find and return all
# ASM Function names that still
# exists in Source Files 
# --------------------------
def find_asm_functions():
    
    p = re.compile(r"^glabel (\S+)$")
    asm_functions = []

    for root, dirs, files in os.walk('src'):
        for file in files:
            with open(os.path.join(root, file)) as _file:
                for i, line in enumerate(_file.readlines()):
                    m = p.findall(line)
                    if m:
                        asm_functions.append(m[0])

    return asm_functions

# --------------------------
# Calculate the decomp stats
# on each folder
# --------------------------
def do_stats(map_file, analyse_folders):

    asm_functions = find_asm_functions()
    segments = {}

    for folder in analyse_folders:

        segments[folder] = {}
        segments[folder]['done'] = 0
        segments[folder]['left'] = 0
        segments[folder]['total'] = 0
        
        num_done = 0
        num_left = 0

        for function in map_file[folder]:
            if function in asm_functions:
                num_left += map_file[folder][function]
            else:
                num_done += map_file[folder][function]
        
        segments[folder]['done'] = num_done / 4
        segments[folder]['left'] = num_left / 4
        segments[folder]['total'] = segments[folder]['done'] + segments[folder]['left']

    return segments

def main():

    map_file = parse_map()

    folders = ['src', 'src/game', 'src/inflate', 'src/libultra']

    segments = do_stats(map_file, folders)

    totals = {}
    totals['done'] = 0
    totals['total'] = 0

    for key in segments.keys():
        print('{:10}\t{:10,} / {:,} \t{:.2f}%'.format(key, int(segments[key]['done']), int(segments[key]['total']), (segments[key]['done'] / segments[key]['total'] * 100)))
        totals['done'] += segments[key]['done']
        totals['total'] += segments[key]['total']

    print('TOTAL\t\t{:10,} / {:,} \t{:.2f}%'.format(int(totals['done']), int(totals['total']), (totals['done'] / totals['total'] * 100)))

if __name__ == '__main__':
    main()
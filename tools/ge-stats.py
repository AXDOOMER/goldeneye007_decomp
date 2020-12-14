import re
import os
import sys
import subprocess
import shlex


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
# Find and return the number of completed files
# Only scans for C and S files
# --------------------------
def find_files_completed():
    
    p = re.compile(r"^glabel (\S+)$")
    files_complete = {}

    files_complete['completed'] = 0
    files_complete['total'] = 0

    for root, dirs, files in os.walk('src'):
        for file in files:
            if file.endswith(".c") or file.endswith(".s"):
                with open(os.path.join(root, file)) as _file:
                    
                    completed = True
                    files_complete['total'] += 1
                    
                    for i, line in enumerate(_file.readlines()):
                        if p.findall(line):
                            completed = False
                            break
                    
                    if completed:
                        files_complete['completed'] += 1

    return files_complete

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

def main(debug):
    files_completed = find_files_completed()
    
    map_file = parse_map()
    
    folders = ['src', 'src/game', 'src/inflate', 'src/libultra']
    
    segments = do_stats(map_file, folders)
    
    totals = {}
    totals['done'] = 0
    totals['total'] = 0

    if debug == 1:
        print('--------------------------')
        
        print('FILES\t\t{:10,} / {:,} \t{:.2f}%'.format(int(files_completed['completed']), int(files_completed['total']), (files_completed['completed'] / files_completed['total'] * 100)))
    
        print('--------------------------')
        print('WORDS')
        
        for key in segments.keys():
            print('{:10}\t{:10,} / {:,} \t{:.2f}%'.format(key, int(segments[key]['done']), int(segments[key]['total']), (segments[key]['done'] / segments[key]['total'] * 100)))
            totals['done'] += segments[key]['done']
            totals['total'] += segments[key]['total']
        
        print('TOTAL\t\t{:10,} / {:,} \t{:.2f}%'.format(int(totals['done']), int(totals['total']), (totals['done'] / totals['total'] * 100)))
        
        print('--------------------------')
    else:
        for key in segments.keys():
            sys.stdout.write(str(segments[key]['done']) + ' ' + str(segments[key]['total']) + ' ')
            totals['done'] += segments[key]['done']
            totals['total'] += segments[key]['total']
        
        sys.stdout.write(str(totals['done']) + ' ' + str(totals['total']) + ' ')
        sys.stdout.write(str(files_completed['completed']) + ' ' + str(files_completed['total']) + ' ')
        sys.stdout.write('./tools/results/results.html "src/game/bond.c"')
        #subprocess.call(shlex.split("./report/report int(totals['done']) int(totals['total']) int(files_completed['completed']) int(files_completed['total'])"))
        #      1481 15854      12774 232276        564 1312        652 20330      15471 269772         49 336

if __name__ == '__main__':
    if len(sys.argv) > 1:
        if sys.argv[1] == "debug":
            main(1)
        else:
            main(0)
    else:
        main(0)

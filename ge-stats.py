import re
import os

def main():

    # --------------------------
    # PART 1 
    # READ MAP FILE AND FILL lengths
    # --------------------------

    f = open('build/ge007.u.map', 'r')
    lines = f.readlines()
    
    infile = False
    prevromaddr = 0
    lengths = {}

    p1 = re.compile(r"^ \.text\s+0x00000000([0-9a-f]{8})\s+0x([0-9a-f]+)\s+build\/u\/(.*)\/\S+.\w$")
    p2 = re.compile(r"\s+0x00000000([0-9a-f]{8})\s+(\S+)$")

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

    # --------------------------
    # PART 2 
    # GET TODOS FUNCTIONS IN ALL FILES
    # --------------------------

    p3 = re.compile(r"^glabel (\S+)$")
    todos = []

    for root, dirs, files in os.walk('src'):
        for file in files:
            with open(os.path.join(root, file)) as _file:
                for i, line in enumerate(_file.readlines()):
                    m3 = p3.findall(line)
                    if m3:
                        todos.append(m3[0])

    # --------------------------
    # PART 3
    # FIND FUNCTION IS IN TODOs
    # --------------------------

    analyse = ['src', 'src/game', 'src/inflate', 'src/libultra']
    segments = {}

    for key in analyse:

        segments[key] = {}
        segments[key]['done'] = 0
        segments[key]['left'] = 0
        segments[key]['total'] = 0
        
        num_done = 0
        num_left = 0

        for fn in lengths[key]:
            if fn in todos:
                num_left += lengths[key][fn]
            else:
                num_done += lengths[key][fn]
        
        segments[key]['done'] = num_done / 4
        segments[key]['left'] = num_left / 4
        segments[key]['total'] = segments[key]['done'] + segments[key]['left']

    # --------------------------
    # PART 4
    # PRINT ALL
    # --------------------------

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
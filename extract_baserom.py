#!/usr/bin/python

#this should actually be written for goldeneye007.... copied from ootmqd project for now as reminder
#i know crap about python so anyone can feel free to tackle this...
#TBH, n64 split can handle this task just fine....


import os;
import sys;
import struct;


ROM_FILE_NAME = 'baserom.z64'
FILE_TABLE_OFFSET = 0x12F70
FILE_COUNT = 1532

FILE_NAMES = [
    'makerom',
]


def read_uint32_be(offset):
    return struct.unpack('>I', romData[offset:offset+4])[0]

def write_output_file(name, offset, size):
    try:
        with open(name, 'wb') as f:
            f.write(romData[offset:offset+size])
    except IOError:
        print('failed to write file ' + name)


try:
    os.mkdir('baserom')
except:
    pass

# read baserom data
try:
    with open(ROM_FILE_NAME, 'rb') as f:
        romData = f.read()
except IOError:
    print('failed to read file' + ROM_FILE_NAME)
    sys.exit(1)

# extract files
for i in range(0, 1532):
    filename = 'baserom/' + FILE_NAMES[i]
    entryOffset = FILE_TABLE_OFFSET + 16 * i

    virtStart = read_uint32_be(entryOffset + 0)
    virtEnd   = read_uint32_be(entryOffset + 4)
    physStart = read_uint32_be(entryOffset + 8)
    physEnd   = read_uint32_be(entryOffset + 12)

    if physEnd == 0:  # uncompressed
        compressed = False
        size = virtEnd - virtStart
    else:             # compressed
        compressed = True
        size = physEnd - physStart
    
    print('extracting ' + filename + " (0x%08X, 0x%08X)" % (virtStart, virtEnd))
    write_output_file(filename, physStart, size)
    if compressed:
        os.system('tools/yaz0 -d ' + filename + ' ' + filename)

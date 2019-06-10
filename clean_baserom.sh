#!/bin/bash
echo "cleaning up files created by extract_baserom.sh"
true="1"
while IFS=, read -r offset size name compressed extract
do
    if [ "$extract" == "$true" ]; then
        if [ "$compressed" == "$true" ]; then
            echo "removing $name.bin"
            rm -f $name.bin
        else
        echo "removing $name"
            rm -f $name
        fi
    else
        echo "skip $name"
    fi
done < filelist.u.csv



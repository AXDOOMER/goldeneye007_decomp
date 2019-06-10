#!/bin/bash
echo "IGNORE gzip errors about crc and end of file"
true="1"
mkdir assets assets/font assets/music assets/ramrom assets/obseg assets/obseg/bg assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop assets/obseg/setup assets/obseg/stan assets/obseg/text
while IFS=, read -r offset size name compressed extract
do
    if [ "$extract" == "$true" ]; then
        if [ "$compressed" == "$true" ]; then
            echo "Extracting compressed $name, $size bytes..."
            dd bs=1 skip=$offset count=$size if=baserom.u.z64 of=$name status=none
	         # Add the gZip Header to a new file using the name given in command
	        echo -n -e \\x1F\\x8B\\x08\\x00\\x00\\x00\\x00\\x00\\x02\\x03 > $name.temp
	         # Add the contents of the compressed file minus the 1172 to the new file
	        cat $name | tail --bytes=+3 >> $name.temp
	         # copy the new file over the old compressed file
	        cat $name.temp > $name.zip
	         # decompress the Z file to the filename given in the command
	        cat $name.zip | gzip --quiet --decompress > $name.bin
	         # remove the compressed Z file
	        rm $name.temp $name.zip $name
	        echo "Successfully Decompressed $name"
        else
            echo "Extracting uncompressed $name, $size bytes..."
            dd bs=1 skip=$offset count=$size if=baserom.u.z64 of=$name status=none
            echo "Successfully Extracted $name"
        fi
    else
        echo "skip $name"
    fi
done < filelist.u.csv
#filelist.u.csv should follow pattern of:
#offset,size,name,compressed,extract
#formatting matters, no comments, no extra lines, unix line endings only
#and always end with no newline


#!/bin/bash
DIRS="bg
brief
chr
g_items
props
setup
Tbg
text"
 
for DIRNAME in $DIRS ; do
	rm $DIRNAME.inc
	rm $DIRNAME.rz.asm
	echo "base origin()" >> $DIRNAME.rz.asm
	echo "seg_"$DIRNAME"_rom_start:" >> $DIRNAME.rz.asm
	echo "" >> $DIRNAME.rz.asm
	for FILENAME in $DIRNAME/*.asm ; do
		echo "parsing $FILENAME"
		FILENAME=$(echo "$FILENAME" | cut -d "." -f1)
		bass -sym $FILENAME.sym $FILENAME.asm

		#TODO compress $FILENAME.bin here to $FILENAME.rz to include

		#make include and asm for .rz
		BASENAME=$(echo "$FILENAME" | cut -d "/" -f2)
		echo "insert $BASENAME, \"$FILENAME.rz\"">>$DIRNAME.rz.asm


		rm $FILENAME.inc
		declare -i LINENUM=1
		while read CURRENTLINE ; do
			let "LINENUM  += 1"
			OFFSET=$(echo "$CURRENTLINE" | cut -d " " -f1)
			NAME=$(echo "$CURRENTLINE" | cut -d " " -f2)
			echo "define "$NAME"($"$OFFSET")" >> $FILENAME.inc
		done <"$FILENAME.sym"
		echo "include \"$FILENAME.inc\"" >>$DIRNAME.inc
		rm $FILENAME.sym
		rm $FILENAME.bin
	done
	echo "" >> $DIRNAME.rz.asm
	echo "seg_"$DIRNAME"_rom_end:" >> $DIRNAME.rz.asm
done

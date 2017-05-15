#!/bin/bash
shopt -s extglob
DIRS="text"
for DIRNAME in $DIRS ; do
	rm $DIRNAME.inc

	for FILENAME in $DIRNAME/!(*.rz).asm ; do
		echo "parsing $FILENAME"
		FILENAME=$(echo "$FILENAME" | cut -d "." -f1)
		rm $FILENAME.rz.asm
		bass -sym $FILENAME.sym $FILENAME.asm
		#compress to zlib headerless format,
		#gotta love *nix and pipes
        cat $FILENAME.bin| gzip --no-name | tail --bytes=+11 | head --bytes=-8 > $FILENAME.rz
		#make include and asm for .rz
		BASENAME=$(echo "$FILENAME" | cut -d "/" -f2)

		#theres no 1172 header so lets fix that
		echo "seg_"$BASENAME"_rom_start:">>$FILENAME.rz.asm
		echo "db 0x11, 0x72">>$FILENAME.rz.asm
		echo "insert $BASENAME, \"$BASENAME.rz\"">>$FILENAME.rz.asm
		#nor is data aligned
		echo "align(16)">>$FILENAME.rz.asm
		echo "seg_"$BASENAME"_rom_end:">>$FILENAME.rz.asm
		echo "">>$FILENAME.rz.asm

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
done

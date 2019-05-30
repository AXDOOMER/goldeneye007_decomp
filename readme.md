This is a working Goldeneye 007 disassembly! 

Due to a bug with gzip, the following is your friend for random sha1 fails
```
make clean && \
git checkout build/assets/obseg/setup/UsetuparchZ.rz && \
git checkout build/assets/obseg/setup/UsetupjunZ.rz && \
git checkout build/assets/obseg/setup/UsetupsevbZ.rz && \
make
```

The only real requirements should be 
```
sudo apt install binutils-mips-linux-gnu make
```
followed by
```
make
```
This repo is getting a big overhaul... expect crap to break till I remove notice


This dissassembly was only made possible thanks to Zoinkity's awesome documentation, and Subdrag's wonderful GEedit.

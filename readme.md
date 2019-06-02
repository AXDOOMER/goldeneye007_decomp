This is a working Goldeneye 007 decompilation! 


The only real requirements should be 
```
sudo apt install binutils-mips-linux-gnu make
```
followed by
```
make
```


Due to a bug with gzip, the following is your friend for random sha1 fails
```
make clean && \
git checkout build/assets/obseg/setup/UsetuparchZ.rz && \
git checkout build/assets/obseg/setup/UsetupjunZ.rz && \
git checkout build/assets/obseg/setup/UsetupsevbZ.rz && \
make
```


This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

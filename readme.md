This is a working Goldeneye 007 decompilation! 


The only real requirements should be 
```
sudo apt install binutils-mips-linux-gnu make
```
Place a USA rom in root named baserom.u.z64
followed by
```
./extract_baserom.sh
make
```

If you are upgrading from an old repo, also run
```
./clean_baserom.sh && ./extract_baserom.sh
```
before building


Due to a bug with gzip, the following is your friend for random sha1 fails
```
make clean && make
```


This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

GE and PD documentation made by Zoinkity

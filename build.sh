#!/bin/bash

#this is mostly a reference for file order, most of these won't compile properly yet
#or don't exist
tools/asmpreproc/compile.sh src/boot.c

tools/asmpreproc/compile.sh src/code/init.c
tools/asmpreproc/compile.sh src/code/scheduler.c
#tools/asmpreproc/compile.sh src/code/osMapTLB.s
tools/asmpreproc/compile.sh src/code/tlb_manage.c
tools/asmpreproc/compile.sh src/code/tlb_random.c
tools/asmpreproc/compile.sh src/code/tlb_resolve.c
tools/asmpreproc/compile.sh src/code/audi.c
tools/asmpreproc/compile.sh src/code/speedgraph.c
tools/asmpreproc/compile.sh src/code/video.c
tools/asmpreproc/compile.sh src/code/deb.c
tools/asmpreproc/compile.sh src/code/debug_getlastRA.c
tools/asmpreproc/compile.sh src/code/ramrom.c
tools/asmpreproc/compile.sh src/code/boss.c
tools/asmpreproc/compile.sh src/code/music.c
tools/asmpreproc/compile.sh src/code/sfx.c
tools/asmpreproc/compile.sh src/code/memp.c
tools/asmpreproc/compile.sh src/code/mema.c
#tools/asmpreproc/compile.sh src/code/random.s
tools/asmpreproc/compile.sh src/code/token.c
tools/asmpreproc/compile.sh src/code/stringhandler.c
tools/asmpreproc/compile.sh src/code/sprintf.c
tools/asmpreproc/compile.sh src/code/pi.c
tools/asmpreproc/compile.sh src/code/vi.c
tools/asmpreproc/compile.sh src/code/debugmenu.c
tools/asmpreproc/compile.sh src/code/joy.c
tools/asmpreproc/compile.sh src/code/joy_rumble.c
tools/asmpreproc/compile.sh src/code/rmon.c

tools/asmpreproc/compile.sh src/rarezip/rarezip.c
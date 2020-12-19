#Compiler directories
MINGWDIR = C:/mingw64/bin/
CC = $(MINGWDIR)gcc

#Source directories
SRCDIR = ./
OBJDIR = $(SRCDIR)obj/
OUTDIR = $(SRCDIR)
EXENAME = finalizer.exe

#Compiler flags
CFLAGS = -shared -ansi -Os -m64 -std=c89
CFLAGSDBG = -shared -ansi -g -m64 -std=c89
WFLAGS = -W -Wall -Wextra -pedantic -Wunreachable-code

#Linker flags
OBJS = $(OBJDIR)main.o $(OBJDIR)puff.o $(OBJDIR)fread_csv_line.o
LIBS = -lmingw32 -static-libgcc
LFLAGS = $(OBJS) -o $(EXENAME) $(LIBS) -m64 -s
LFLAGSDBG = $(OBJS) -o $(EXENAME) $(LIBS) -m64

#Main recipes
all: clean finalizer

debug: CFLAGS = $(CFLAGSDBG)
debug: LFLAGS = $(LFLAGSDBG)
debug: finalizer

finalizer: $(OBJS)
	$(CC) $(LFLAGS)

clean:
	del $(EXENAME)
	del .\obj\*.o

#Individual recipes
$(OBJDIR)main.o: $(SRCDIR)main.c $(SRCDIR)puff.h
	$(CC) -c $(SRCDIR)main.c -o $(OBJDIR)main.o $(CFLAGS) $(WFLAGS)

$(OBJDIR)puff.o: $(SRCDIR)puff.c $(SRCDIR)puff.h
	$(CC) -c $(SRCDIR)puff.c -o $(OBJDIR)puff.o $(CFLAGS) $(WFLAGS)

$(OBJDIR)fread_csv_line.o: $(SRCDIR)fread_csv_line.c $(SRCDIR)fread_csv_line.h
	$(CC) -c $(SRCDIR)fread_csv_line.c -o $(OBJDIR)fread_csv_line.o $(CFLAGS) $(WFLAGS)
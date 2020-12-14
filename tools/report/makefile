#Compiler
CC = @gcc

#Source directories
SRCDIR = ./
OUTNAME = report
TEMPLATE = template.html
OUTHTML = results.html

#Compiler flags
CFLAGS = -shared -ansi -Os -std=c89
CFLAGSDBG = -shared -ansi -g -std=c89
WFLAGS = -W -Wall -Wextra -pedantic -Wunreachable-code -Wno-implicit-fallthrough -Wno-unused-result

#Linker flags
OBJS = $(SRCDIR)main.o
LFLAGS = $(OBJS) -o $(OUTNAME) -s
LFLAGSDBG = $(OBJS) -o $(OUTNAME)

#Main recipes
all: copy_html report

debug: CC = gcc
debug: CFLAGS = $(CFLAGSDBG)
debug: LFLAGS = $(LFLAGSDBG)
debug: copy_html
debug: report

report: $(OBJS)
	$(CC) $(LFLAGS)

clean:
	@rm $(OUTNAME)
	@rm $(SRCDIR)*.o

copy_html:
	@cp -f $(TEMPLATE) $(OUTHTML)

#Individual recipes
$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) -c $(SRCDIR)main.c -o $(SRCDIR)main.o $(CFLAGS) $(WFLAGS)
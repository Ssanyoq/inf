CC = gcc
CFLAGS = 
DEBUGFLAGS = -g
SOURCES = main.c files.c sorts.c mem.c
EXENAME = e
EXEDIR = build
READFILE = read.txt
WRITEFILE = write.txt

default:
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)

test:
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)
	$(EXEDIR)/$(EXENAME) $(READFILE) $(WRITEFILE)
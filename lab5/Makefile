CC = gcc
CFLAGS = 
DEBUGFLAGS = -g
SOURCES1 = main.c files.c sorts.c mem.c
SOURCES2 = benchmark.c mem.c sorts.c
EXENAME = e
EXENAME2 = e2
EXEDIR = build
READFILE = read.txt
WRITEFILE = write.txt

default:
	$(CC) $(SOURCES1) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)

test:
	$(CC) $(SOURCES1) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)
	$(EXEDIR)/$(EXENAME) $(READFILE) $(WRITEFILE)

db:
	$(CC) $(SOURCES1) $(DEBUGFLAGS) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)


bench:
	$(CC) $(SOURCES2) $(CFLAGS) -o $(EXEDIR)/$(EXENAME2)

bench_db:
	$(CC) $(SOURCES2) $(DEBUGFLAGS) $(CFLAGS) -o $(EXEDIR)/$(EXENAME)
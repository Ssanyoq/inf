1: 
	gcc std/main1.c -c -o build/main1.o
	gcc mem.c -c -o build/mem.o
	gcc build/mem.o build/main1.o -l readline -o build/e1
	rm build/mem.o
	rm build/main1.o
2:
	gcc my/main2.c -c -o build/main2.o
	gcc my/myreadline.c -c -o build/myreadline.o
	gcc my/mystring.c -c -o build/mystring.o
	gcc mem.c -c -o build/mem.o
	gcc build/main2.o build/myreadline.o build/mystring.o build/mem.o -o build/e2
	rm build/main2.o
	rm build/myreadline.o
	rm build/mystring.o
	rm build/mem.o
f1: 
	gcc std/main1.c -c -o build/main1.o
	gcc mem.c -c -o build/mem.o
	gcc build/mem.o build/main1.o -l readline -o build/e1
	rm build/mem.o
	rm build/main1.o
	build/e1
f2:
	gcc my/main2.c -c -o build/main2.o
	gcc my/myreadline.c -c -o build/myreadline.o
	gcc my/mystring.c -c -o build/mystring.o
	gcc mem.c -c -o build/mem.o
	gcc build/main2.o build/myreadline.o build/mystring.o build/mem.o -o build/e2
	rm build/main2.o
	rm build/myreadline.o
	rm build/mystring.o
	rm build/mem.o
	build/e2

vg1: 
	gcc std/main1.c -c -o build/main1.o
	gcc mem.c -c -o build/mem.o
	gcc build/mem.o build/main1.o -l readline -o build/e1
	rm build/mem.o
	rm build/main1.o
	valgrind/e1

vg2:
	gcc my/main2.c -c -o build/main2.o
	gcc my/myreadline.c -c -o build/myreadline.o
	gcc my/mystring.c -c -o build/mystring.o
	gcc mem.c -c -o build/mem.o
	gcc build/main2.o build/myreadline.o build/mystring.o build/mem.o -o build/e2
	rm build/main2.o
	rm build/myreadline.o
	rm build/mystring.o
	rm build/mem.o
	valgrind build/e2

g1: 
	gcc std/main1.c mem.c -g -l readline -o build/e1
g2: 
	gcc my/main2.c mem.c my/mystring.c my/myreadline.c -g -o build/e2
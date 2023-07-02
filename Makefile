run: main
	LD_LIBRARY_PATH=$$PWD ./main

main: main.c libfunctions.so
	gcc main.c -o main -L. -lfunctions 

libfunctions.so: div.o sub.o sum.o mult.o
	gcc -shared div.o sub.o sum.o mult.o -o libfunctions.so 

div.o: div.c
	gcc div.c -fPIC -c

sub.o: sub.c
	gcc sub.c -fPIC -c

sum.o: sum.c
	gcc sum.c -fPIC -c

mult.o: mult.c
	gcc mult.c -fPIC -c

clear:
	rm  *.o *.a *.so main
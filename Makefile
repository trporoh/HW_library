main: main.c libfunctions.a
	gcc main.c -o main -L. -lfunctions 

libfunctions.a: div.o sub.o sum.o mult.o
	ar rc libfunctions.a div.o sub.o sum.o mult.o

div.o: div.c
	gcc div.c -c

sub.o: sub.c
	gcc sub.c -c

sum.o: sum.c
	gcc sum.c -c

mult.o: mult.c
	gcc mult.c -c

clear:
	rm  *.o *.a main
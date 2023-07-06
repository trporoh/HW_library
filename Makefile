DLL := libsum.so libsub.so libdiv.so libmult.so

run: main
	LD_LIBRARY_PATH=$$PWD ./main

main: main.c $(DLL)
	gcc main.c -o main -L. -lsum -lsub -lmult -ldiv -rdynamic -ldl  -g

libsum.so: sum.o
	gcc -shared sum.o -o libsum.so 

libsub.so: sub.o
	gcc -shared sub.o -o libsub.so

libmult.so: mult.o
	gcc -shared mult.o -o libmult.so

libdiv.so: div.o
	gcc -shared div.o -o libdiv.so 

div.o: div.c
	gcc div.c -fPIC -c

sub.o: sub.c
	gcc sub.c -fPIC -c

sum.o: sum.c
	gcc sum.c -fPIC -c

mult.o: mult.c
	gcc mult.c -fPIC -c

main: *.h

clear:
	rm  *.o *.a *.so main
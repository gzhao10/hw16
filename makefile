all:
	gcc -o input input.c
	gcc -o output output.c

clean:
	-rm *.o

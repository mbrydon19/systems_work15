all: fork.o
	gcc -o test fork.c

fork.o: fork.c
	gcc -c fork.c

run:
	./test

clean:
	rm *.o

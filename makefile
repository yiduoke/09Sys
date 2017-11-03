all: something.c
	gcc something.c

clean:
	rm *~
	rm a.out

run: all
	./a.out
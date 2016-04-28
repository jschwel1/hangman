all: hangman.c hangman.h main.c
	gcc -g -Wall hangman.c main.c -o hm
run: all
	./hm
gdb: all
	gdb ./hm
clean:
	rm hm

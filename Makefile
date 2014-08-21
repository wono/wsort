all: src/*.c
	gcc -ansi -pedantic -std=c11 -Wall src/*.c -o wsort

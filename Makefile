wsort: src/*.c
	gcc -ansi -pedantic -std=c11 -Wall src/*.c -o tests/wsort

clean:
	rm tests/wsort

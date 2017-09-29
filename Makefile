%.o: %.c
	gcc -g -c -o $@ $<

debug:	library.o
	gcc -Wall -Werror -g -c -o library library.o

test: library.o test.o
	gcc -Wall -Werror -g -o test test.o library.o

hil: library.c hilbert.c
	gcc -o gfx hilbert.c library.c

driver: library.c driver.c
	gcc -o driver driver.c library.c

drivert: library.o driver.o
	gcc -Wall -Werror -g -o drivert driver.o library.o

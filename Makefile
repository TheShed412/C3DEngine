%.o: %.c
	gcc -g -c -o $@ $<


test: library.o test.o point.o
	gcc -Wall -Werror -g -o test test.o library.o point.o -lm
	


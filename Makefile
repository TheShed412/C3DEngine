%.o: %.c
	gcc -g -c -o $@ $<


test: library.o test.o point.o
	gcc -Wall -Werror -g -o test test.o library.o point.o -lm
	
point: point.o
	gcc -Wall -Werror -g -o point point.o -lm

line: line_segment.o
	gcc -Wall -Werror -g -o line_segment line_segment.o -lm


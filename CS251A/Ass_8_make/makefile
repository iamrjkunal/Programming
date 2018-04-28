all: prog.o thread_function.o
	gcc prog.o thread_function.o -lm -lpthread -o target_bin
prog.o: prog.c common.h
	gcc -I . -c prog.c
thread_function.o: thread_function.c common.h
	gcc -I . -c thread_function.c
clean:
	rm -rf *.o
	rm target_bin

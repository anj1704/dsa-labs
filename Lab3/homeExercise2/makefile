run : postfix.o stack_array.o
	gcc -o run postfix.o stack_array.o
	./run
postfix.o : postfix.c
	gcc -c postfix.c
stack_array.o : stack_array.c
	gcc -c stack_array.c
clean:
	rm -f *.o run

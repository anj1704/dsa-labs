run : computeSpan.o stack_array.o
	gcc -o run computeSpan.o stack_array.o 
	./run
computeSpan.o : computeSpan.c
	gcc -c computeSpan.c
stack_array.o : stack_array.c
	gcc -c stack_array.c
clean :
	rm -f run *.o

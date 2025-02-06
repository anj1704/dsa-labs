runBST : bst.o queue_array.o stack_array.o linkedlist.o
	gcc bst.o queue_array.o stack_array.o linkedlist.o -o runBST
	./runBST
bst.o : bst.c
	gcc -c bst.c
queue_array.o : queue_array.c
	gcc -c queue_array.c
stack_array.o : stack_array.c
	gcc -c stack_array.c
linkedlist.o : linkedlist.c
	gcc -c linkedlist.c
clean :
	rm -f *.o run*

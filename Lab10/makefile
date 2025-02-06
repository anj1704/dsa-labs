runAVL : avl.o queue_array.o stack_array.o
	gcc avl.o queue_array.o stack_array.o -o runAVL
	./runAVL
runAVLWithHeight : avl_with_height.o
	gcc avl_with_height.o -o runAVLWithHeight
	./runAVLWithHeight
avl.o : avl.c
	gcc -c avl.c
queue_array.o : queue_array.c
	gcc -c queue_array.c
stack_array.o : stack_array.c
	gcc -c stack_array.c
avl_with_height.o : avl_with_height.c
	gcc -c avl_with_height.c
clean :
	rm -f *.o run*

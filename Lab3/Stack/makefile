runStackWithArray: stackDriver.o stack_array.o heap_usage.o
	gcc -o runStackWithArray stackDriver.o stack_array.o heap_usage.o
	./runStackWithArray
runStackWithLinkedList: stackDriver.o stack_ll.o linked_list.o heap_usage.o
	gcc -o runStackWithLinkedList stackDriver.o stack_ll.o linked_list.o heap_usage.o
	./runStackWithLinkedList
stackDriver.o: stackDriver.c stack.h 
	gcc -c stackDriver.c
runCgStackWithArray: cgStackDriver.o heap_usage.o stack_array.o
	gcc -o runCgStackWithArray cgStackDriver.o heap_usage.o stack_array.o
	./runCgStackWithArray large.csv
runCgStackWithLinkedList: cgStackDriver.o stack_ll.o linked_list.o heap_usage.o
	gcc -o runCgStackWithLinkedList cgStackDriver.o stack_ll.o linked_list.o heap_usage.o
	./runCgStackWithLinkedList large.csv
cgStackDriver.o: cgStackDriver.c
	gcc -c cgStackDriver.c
stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c
stack_ll.o: stack_ll.c stack.h linked_list.h
	gcc -c stack_ll.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
heap_usage.o: heap_usage.c
	gcc -c heap_usage.c
clean:
	rm -f *.o runStackWithArray runStackWithLinkedList runCgStackWithArray runCgStackWithLinkedList


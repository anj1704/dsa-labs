runQueueWithArray : queueDriver.o queue_array.o heap_usage.o
	gcc -o runQueueWithArray queueDriver.o queue_array.o heap_usage.o
	./runQueueWithArray
runQueueWithLinkedList : queueDriver.o queue_ll.o heap_usage.o linked_list.o
	gcc -o runQueueWithLinkedList queueDriver.o queue_ll.o heap_usage.o linked_list.o
	./runQueueWithLinkedList
queueDriver.o : queueDriver.c
	gcc -c queueDriver.c
queue_array.o : queue_array.c
	gcc -c queue_array.c
queue_ll.o : queue_ll.c
	gcc -c queue_ll.c
heap_usage.o : heap_usage.c
	gcc -c heap_usage.c
linked_list.o : linked_list.c
	gcc -c linked_list.c
clean :
	rm -f *.o run*

run : FCFS.o queue_ll.o linked_list.o
	gcc -o run FCFS.o queue_ll.o linked_list.o
	./run
FCFS.o : FCFS.c
	gcc -c FCFS.c
queue_ll.o : queue_ll.c
	gcc -c queue_ll.c
linked_list.o : linked_list.c
	gcc -c linked_list.c
make clean :
	rm -f *.o run

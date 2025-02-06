runBST : task6.o queue_array.o
	gcc task6.o queue_array.o -o runBST 
	./runBST dat10.csv
task6.o : task6.c
	gcc -c task6.c
queue_array.o : queue_array.c
	gcc -c queue_array.c
clean :
	rm -f *.o runBST

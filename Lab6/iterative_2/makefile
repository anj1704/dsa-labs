runWithMedianOfThree : quicksort.o medianOfThree.o utils.o linked_list.o stack_ll.o
	gcc -o runWithMedianOfThree quicksort.o medianOfThree.o utils.o linked_list.o stack_ll.o
	./runWithMedianOfThree
runWithMedianOfMedians : quicksort.o medianOfMedians.o utils.o linked_list.o stack_ll.o
	gcc -o runWithMedianOfMedians quicksort.o medianOfMedians.o utils.o linked_list.o stack_ll.o
	./runWithMedianOfMedians
runWithQuickSelect : quicksort.o quickSelect.o utils.o linked_list.o stack_ll.o
	gcc -o runWithQuickSelect quicksort.o quickSelect.o utils.o linked_list.o stack_ll.o
	./runWithQuickSelect
runWithRandomPivot : quicksort.o randomPivot.o utils.o linked_list.o stack_ll.o
	gcc -o runWithRandomPivot quicksort.o randomPivot.o utils.o linked_list.o stack_ll.o
	./runWithRandomPivot
quicksort.o : quicksort.c
	gcc -c quicksort.c
medianOfThree.o : medianOfThree.c
	gcc -c medianOfThree.c
medianOfMedians.o : medianOfMedians.c
	gcc -c medianOfMedians.c
quickSelect.o : quickSelect.c
	gcc -c quickSelect.c
randomPivot.o : randomPivot.c
	gcc -c randomPivot.c
utils.o : utils.c
	gcc -c utils.c
linked_list.o : linked_list.c
	gcc -c linked_list.c
stack_ll.o : stack_ll.c
	gcc -c stack_ll.c
clean :
	rm -rf *.o run*

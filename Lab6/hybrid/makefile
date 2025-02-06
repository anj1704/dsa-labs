runWithMedianOfThree : quicksort.o medianOfThree.o utils.o
	gcc -o runWithMedianOfThree quicksort.o medianOfThree.o utils.o
	./runWithMedianOfThree
runWithMedianOfMedians : quicksort.o medianOfMedians.o utils.o
	gcc -o runWithMedianOfMedians quicksort.o medianOfMedians.o utils.o
	./runWithMedianOfMedians
runWithQuickSelect : quicksort.o quickSelect.o utils.o
	gcc -o runWithQuickSelect quicksort.o quickSelect.o utils.o
	./runWithQuickSelect
runWithRandomPivot : quicksort.o randomPivot.o utils.o
	gcc -o runWithRandomPivot quicksort.o randomPivot.o utils.o
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
clean :
	rm -rf *.o run*

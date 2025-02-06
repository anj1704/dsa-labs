runWithItr : intMergeSort.o intMergeAuxItr.o heap_usage.o
	gcc -o runWithItr intMergeSort.o intMergeAuxItr.o heap_usage.o
	./runWithItr
runWithRec : intMergeSort.o intMergeAuxRec.o heap_usage.o
	gcc -o runWithRec intMergeSort.o intMergeAuxRec.o heap_usage.o
	./runWithRec
runWithInsert : intMergeByInsert.o heap_usage.o
	gcc -o runWithInsert intMergeByInsert.o heap_usage.o
	./runWithInsert
intMergeSort.o : intMergeSort.c
	gcc -c intMergeSort.c
intMergeAuxItr.o : intMergeAuxItr.c
	gcc -c intMergeAuxItr.c
intMergeAuxRec.o : intMergeAuxRec.c
	gcc -c intMergeAuxRec.c
intMergeByInsert.o : intMergeByInsert.c
	gcc -c intMergeByInsert.c
heap_usage.o : heap_usage.c
	gcc -c heap_usage.c
clean :
	rm -rf *.o run*

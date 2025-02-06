mainexe : task_10.o readCSVArray.o
	gcc -o mainexe task_10.o readCSVArray.o
run : mainexe
	./mainexe
task_10.o : task_10.c 
	gcc -c task_10.c
readCSVArray.o : readCSVArray.c
	gcc -c readCSVArray.c
clean :
	rm -f *.o
	rm -f *exe

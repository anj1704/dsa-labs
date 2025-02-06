addRow : run.o matrixRowAdd.o
	gcc -o runexe run.o matrixRowAdd.o
addColumn : run.o matrixColumnAdd.o
	gcc -o runexe run.o matrixColumnAdd.o
run : runexe
	./runexe
run.o : run.c
	gcc -c run.c
matrixRowAdd.o : matrixRowAdd.c
	gcc -c matrixRowAdd.c
matrixColumnAdd.o : matrixColumnAdd.c
	gcc -c matrixColumnAdd.c
clean :
	rm -f *exe
	rm -f *.o
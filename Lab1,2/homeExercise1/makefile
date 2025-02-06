checkSetAexe : setA.o quiz.o
	gcc -o checkSetAexe setA.o quiz.o
	./checkSetAexe
checkSetBexe : setB.o quiz.o
	gcc -o checkSetBexe setB.o quiz.o
	./checkSetBexe
checkSetCexe : setC.o quiz.o
	gcc -o checkSetCexe setC.o quiz.o
	./checkSetCexe
checkSetA.o : setA.c
	gcc -c setA.c
checkSetB.o : setB.c
	gcc -c setB.c
checkSetC.o : setC.c
	gcc -c setC.c
quiz.o : quiz.c
	gcc -c quiz.c
clean :
	rm -f *.o
	rm -f *exe

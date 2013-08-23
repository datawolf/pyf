#make file for sort programe

permute_test: permute.o permute_test.o
	gcc -o permute_test permute.o permute_test.o
permute.o: permute.c
	gcc -c permute.c
permute_test.o: permute_test.c
	gcc -c permute_test.c
clean:
	rm permute.o permute_test.o permute_test

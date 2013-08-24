#make file for sort programe

permute_test: permute.o permute_test.o
	gcc -o permute_test permute.o permute_test.o
four_sort_test: four_sort_test.o permute.o insertion_sort.o quik_sort.o merge_sort.o heap_sort.o
	gcc -o four_sort_test four_sort_test.o permute.o insertion_sort.o quik_sort.o merge_sort.o heap_sort.o$
four_sort_test.o: four_sort_test.c
	gcc -c four_sort_test.c
permute.o: permute.c
	gcc -c permute.c
permute_test.o: permute_test.c
	gcc -c permute_test.c
insertion_sort.o: insertion_sort.c
	gcc -c  insertion_sort.c
quik_sort.o: quik_sort.c
	gcc -c quik_sort.c
merge_sort.o: merge_sort.c
	gcc -c merge_sort.c
heap_sort.o: heap_sort.c
	gcc -c  heap_sort.c
001-insertion_sort.o: 001-insertion_sort.c
	gcc -c  001-insertion_sort.c
002-quik_sort.o: 002-quik_sort.c
	gcc -c 002-quik_sort.c
003-merge_sort.o: 003-merge_sort.c
	gcc -c 003-merge_sort.c
004-heap_sort.o: 004-heap_sort.c
	gcc -c 004-heap_sort.c
001-insertion: 001-insertion_sort.o insertion_sort.o
	gcc -o insertion 001-insertion_sort.o insertion_sort.o
002-quiksort: 002-quik_sort.o quik_sort.o permute.o
	gcc -o quik 002-quik_sort.o quik_sort.o permute.o
003-mergesort: 003-merge_sort.o
	gcc -o merge 003-merge_sort.o merge_sort.o permute.o
004-heapsort: 004-heap_sort.o heap_sort.o  permute.o
	gcc -o heap 004-heap_sort.o heap_sort.o permute.o
all: 001-insertion permute_test four_sort_test 001-insertion 002-quiksort 003-mergesort 004-heapsort

clean:
	rm permute_test four_sort_test insertion quik merge heap *.o

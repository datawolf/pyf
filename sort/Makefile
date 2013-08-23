#make file for sort programe

001-insertion: 001-insertion_sort.o insertion_sort.o
	gcc -o insertion 001-insertion_sort.o insertion_sort.o
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
all: 001-insertion permute_test four_sort_test

clean:
	rm permute.o permute_test.o permute_test quik_sort.o \
		insertion_sort.o merge_sort.o heap_sort.o four_sort_test \
		four_sort_test.o 001-insertion_sort.o insertion

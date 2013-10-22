#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


extern int errno;
int bubble_sort(void*, size_t, int, int (*)(void*, void*));
int linear_insertion_sort(void*, size_t, int , int (*)(void*, void*));
int select_sort(void*, size_t, int, int (*)(void*, void*));
int binary_insertion_sort(void*, size_t, int , int (*)(void*, void*));
int shell_sort(void*, size_t, int, int (*)(void*, void*));
int quick_sort(void*, size_t, int ,int, int (*)(void*, void*)); /* This one has FIVE argument*/
int heap_sort(void*, size_t, int, int (*)(void*, void*));
int merge_sort(void*, size_t, int, int (*)(void*, void*));

#endif

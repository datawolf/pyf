#include <sys/times.h>
#include <sys/time.h>
#include <stdio.h>

#include "type.h"
#define NUM 30000


long  start_sec, end_sec, start_usec, end_usec;
struct timeval tv;
struct timezone tz;

int main(int argc, char **argv)
{
    element list[NUM];

    int i;
    for ( i = 0; i < NUM; i++)
        list[i].key = NUM - i;

    gettimeofday(&tv, &tz);
    start_sec = tv.tv_sec;
    start_usec = tv.tv_usec;
    insertion_sort(list, NUM);
    gettimeofday(&tv, &tz);
    end_sec = tv.tv_sec;
    end_usec = tv.tv_usec;
    printf("n = 10000, times =  %7.2fus\n",(end_usec-start_usec) + (end_sec - start_sec)*1000000 );
}

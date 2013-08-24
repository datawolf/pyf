#include <sys/times.h>
#include <sys/time.h>
#include <stdio.h>

#include "type.h"
#define NUM 30000


long  start_sec, end_sec, start_usec, end_usec;
struct timeval tv;
struct timezone tz;
int num[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
200, 300, 400, 500, 600, 700, 800, 900, 1000, 1500, 2000, 3000, 4000, 5000, 10000};
int main(int argc, char **argv)
{
    element list[NUM];
    double duration;
    int i;
    for ( i = 0; i < NUM; i++)
        list[i].key = NUM - i;

    for (i = 0; i < 19; i++)
    {
        permute(list, num[i]);
        gettimeofday(&tv, &tz);
        start_sec = tv.tv_sec;
        start_usec = tv.tv_usec;
        heapsort(list, num[i] - 1);
        gettimeofday(&tv, &tz);
        end_sec = tv.tv_sec;
        end_usec = tv.tv_usec;
        duration = (double) ((end_usec - start_usec) + (end_sec - start_sec)*1000000);
        printf("n = %d, times =  %.2fus\n", num[i],  duration);
    }
}

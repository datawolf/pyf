#include <stdio.h>

unsigned long input = 0x12345678;
unsigned long output, zero;

int main(int argc, char **argv)
{
    //use in 64 bit machine
    asm volatile (  "movw %1,%0\n\t"
            :"=r"(output)
            :"r"(input)
            );

// use in 32 bit machine
/*
    asm volatile (  "movl %1,%0\n\t"
            :"=r"(output)
            :"r"(input)
            );
*/
    printf("output:0x%x\t zero:0x%x\t\n", output, zero);

    return 0;
}

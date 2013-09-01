#include "stdio.h"
#include "sys/syscall.h"

int main(int argc, char **argv)
{
    printf("use syscall, pid is : %d\n", syscall(__NR_getpid));
    return 0;
}

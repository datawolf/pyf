#include "stdio.h"
#include "unistd.h"

int main(int argc, char **argv)
{
    printf("use libc, pid is : %d\n", getpid());
    return 0;
}

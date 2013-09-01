#include "stdio.h"
#define GETPID_SYSCALL_NUM 20

int main(int argc, char **argv)
{
    int pid;

    asm ("int $0x80" \
            :"=a"(pid) \
            :"0"(GETPID_SYSCALL_NUM) \
            );

    printf("pid is %d\n", pid);
    printf("pid is %d\n", getpid());

    return 0;
}

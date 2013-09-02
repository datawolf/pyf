/**
 *子进程打印自身的pid和父进程的pid；
 *子进程打印系统日期
 *父进程等待子进程执行完毕后，打印自身的pid和子进程的pid
 * */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    pid_t   pid;
    
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("in child processing...\n");
        printf("[child] my pid is %d, parent process pid is %d\n", getpid(), getppid());
        execlp("/bin/date", "date", NULL);
    }else
    {
        printf("in parent process, waiting for child processing completing...\n");
        waitpid(pid);
        printf("child complete\n");
        printf("[parent] my pid is %d, child process pid is %d\n", getpid(), pid);
        exit(0);
    }

}

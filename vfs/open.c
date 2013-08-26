#include <stdio.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    int fd;

    fd = open("./a.txt", O_RDWR | O_CREAT, 00700);

    if (fd == -1)
        perror("fail to open");

    close(fd);

    return 0;
}

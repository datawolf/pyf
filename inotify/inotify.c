#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE      (sizeof(struct inotify_event))
#define BUF_LEN         (1024 * (EVENT_SIZE + 16))

int main(int argc, char **argv)
{
    int length;
    int i = 0;
    int fd;
    int wd;
    char buffer[BUF_LEN];

    /* create inotify instance */
    fd = inotify_init();
    if (fd < 0)
        perror("inotify_init");

    /* add a watch */
    wd = inotify_add_watch(fd, "/home/wanglong",
            IN_MODIFY | IN_CREATE | IN_DELETE);

    /* get the filesystem event */
    length = read(fd, buffer, BUF_LEN);
    if (length  < 0)
        perror("read");

    while (i < length){
        struct inotify_event *event = (struct inotify_event*)&buffer[i];
        if (event->len)
        {
            if (event->mask & IN_CREATE)
            {
                if (event->mask & IN_ISDIR)
                    printf("Directory %s was created.\n", event->name);
                else
                    printf("File %s was created\n", event->name);
            }
            else if (event->mask & IN_DELETE)
            {
                if (event->mask & IN_ISDIR)
                    printf("Directory %s was deleted.\n", event->name);
                else
                    printf("File %s was deleted\n", event->name);
            }
            else if (event->mask & IN_MODIFY)
            {
                if (event->mask & IN_ISDIR)
                    printf("Directory %s was modified.\n", event->name);
                else
                    printf("File %s was modified.\n", event->name);
            }
        }
        i += EVENT_SIZE + event->len;
    }

    (void) inotify_rm_watch(fd, wd);
    (void) close(fd);
    
    exit(0);
}

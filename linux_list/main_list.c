#include <stdio.h>

#include "list.h"

int main(int argc, char **argv)
{
    struct demo {
        int     data;
        struct  list_head   list;
    };

    struct demo tmp;
    tmp.data = 1;
    (tmp.list).next = &tmp.list;
    (tmp.list).prev = &tmp.list;

    struct demo tmp1;
    tmp1.data = 1;
    list_add(&tmp1.list, &tmp.list);

    struct demo tmp2;
    tmp2.data = 2;
    list_add(&tmp2.list, &tmp.list);

    struct list_head *pos = &tmp.list;

//    list_entry(pos, struct demo, list);

    list_for_each(pos, &tmp.list)
          printf("the data = %d\n", list_entry(pos, struct demo, list)->data);

}

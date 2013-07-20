

struct list_head {
    struct list_head    *next, *prev;
};


#define LIST_HEAD_INIT(name)    { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head  name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr)     do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
}while(0)


/**
 * __list_add 在两个已知的节点中间插入新的节点
 * 
 * 只在内部使用
 */
static void  __list_add(struct list_head *new,
            struct list_head *prev,
            struct list_head *next)
{
    //以下四句没有顺序
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}


/**
 * list_add 增加一个新的节点
 *
 * 在head之后增加一个新的节点
 *
 */
static void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

/**
 * list_add_tail 增加一个新的节点
 *
 * 在head之前增加一个新的节点
 *
 */
static void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}



/**
 * __list_del 从链表中删除一个节点
 *
 * 只在内部使用
 *
 */
static void __list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}


/**
 * list_del 从链表中删除一个节点
 * 
 */

static void list_del(struct list_head *entry)
{
   __list_del(entry->prev, entry->next); 
}


/**
 * list_empty 测试链表是否为空
 *
 */
static int list_empty(const struct list_head *head)
{
    return head->next == head;
}

/**
 * list_empty_careful 测试链表是否为空
 *
 */
static int list_empty_careful(const struct list_head *head)
{
    struct list_head    *next = head->next;
    return (next == head) && (next == head->prev);
}
/**
 * list_del_init 从list中删除一个节点，并重新初始化该节点
 *
 *
 */
static void list_del_init(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    INIT_LIST_HEAD(entry);
}


/**
 * list_move  从list删除节点，并添加到另一个head中
 *
 */
static void list_move(struct list_head *list, struct list_head *head)
{
    __list_del(list->prev, list->next);
    list_add(list, head);
}


/**
 * list_move_tail 从list删除一个节点，并添加到另一head之前
 *
 */
static void list_move_tail(struct list_head *list, 
            struct list_head *head)
{
    __list_del(list->prev, list->next);
    list_add_tail(list, head);
}


/**
 * 连接两个链表
 *
 */
static void __list_splice(struct list_head *list,
            struct list_head *head)
{
    struct  list_head *first = list->next;
    struct  list_head *last = list->prev;
    struct  list_head *at = head->next;

    first->prev = head;
    head->next = first;

    last->next = at;
    at->prev = last;
}


/**
 * 连接两个链表
 *
 */
static void list_splice(struct list_head *list, struct list_head *head)
{
    if (!list_empty(list))
      __list_splice(list, head);
}


/**
 * 连接两个链表,并重新初始化空链表
 *
 */
static void list_splice_init(struct list_head *list, struct list_head *head)
{
    if (!list_empty(list))
    {
      __list_splice(list, head);
      INIT_LIST_HEAD(list);
    }

}


#define offsetof(TYPE,MEMBER)   ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({  \
            const typeof( ((type *)0)->member) *__mptr = (ptr); \
            (type *)( (char *)__mptr - offsetof(type, member) );})


#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); \
                pos = pos->next)

#define list_for_each_prev(pos, head) \
    for (pos = (head)->prev, pos != (head); \
                pos = pos->prev)

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member);  \
                &pos->member != (head); \
                pos = list_entry(pos->member.next, typeof(*pos), member))




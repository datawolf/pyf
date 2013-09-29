题目：
    给一个单链表作为输入：L0,L1,L2,L3,L4,... Ln-1,Ln.
    算法给出经处理后的链表：L0,Ln,L1,Ln-1,L2,Ln-2.....

要求：空间复杂度O(1).


这是微软2014年校园招聘的笔试题.


结构体：
struct Node {
    int int_;
    struct Node *next;
}

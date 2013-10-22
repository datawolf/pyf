#include "sort.h"

/**
 * All the sorting functions put the biggest number in the last position!
 * 
 */

/**
 * Bubble sort
 *
 * Notice: Bubble sort is bad, beacuse it is O(n^2). Avoid using it
 *
 * */
int bubble_sort(void* a, size_t len, int num, int (*comp)(void*, void*))
{
    int i, j;
    void *temp;

    // I just detect whethe a is NULL, but I don't make sure that num
    // is in the right arrage!
    if (a == NULL){
        errno = EINVAL;
        return -1;
    }

    if ((temp = malloc(len)) == NULL){
        errno = ENOMEM;
        return -1;
    }

    for (i = 0; i < num; i++)
        for (j = i+1; j < num; j++)
            if (comp(a+len*j, a+len*i) < 0){
                memcpy(temp, a+len*i, len);
                memcpy(a+len*i, a+len*j, len);
                memcpy(a+len*j, temp, len);
            }

    free(temp);
    return 0;
}

/**
 * Linear_insertion sort
 *
 * Notice: Linear_insertion  sort is bad, beacuse it is O(n^2). Avoid using it
 *
 * */
int linear_insertion_sort(void* a, size_t len, int num , int (*comp)(void*, void*))
{
    int i, j;
    void *temp;

    // I just detect whethe a is NULL, but I don't make sure that num
    // is in the right arrage!
    if (a == NULL){
        errno = EINVAL;
        return -1;
    }

    if ((temp = malloc(len)) == NULL){
        errno = ENOMEM;
        return -1;
    }

    for (i = 0; i < num; i++)
        for (j = i; j > 0 && comp(a+len*(j-1), a+len*j) < 0; j--){
                memcpy(temp, a+len*(j-1), len);
                memcpy(a+len*(j-1), a+len*j, len);
                memcpy(a+len*j, temp, len);
        }

    free(temp);
    return 0;

}

static int max_key(void* a, size_t len, int f, int e, int (*comp)(void*, void*))
{
    int i, m = f;
    for (i = f; i <= e; i++)
        if (comp(a+len*i, a+len*m) > 0)
            m = i;

    return m;
}
/**
 * Select sort
 *
 * Notice: Select sort is bad, beacuse it is O(n^2). Avoid using it
 *
 * */
int select_sort(void* a, size_t len, int num, int (*comp)(void*, void*))
{
    int i, mm;
    void *temp;

    // I just detect whethe a is NULL, but I don't make sure that num
    // is in the right arrage!
    if (a == NULL){
        errno = EINVAL;
        return -1;
    }

    if ((temp = malloc(len)) == NULL){
        errno = ENOMEM;
        return -1;
    }

    for (i = num - 1; i >= 0; i--){
        mm = max_key(a, len, 0, i, comp);
        memcpy(temp, a+len*i, len);
        memcpy(a+len*i, a+len*mm, len);
        memcpy(a+len*mm, temp, len);
    }

    free(temp);
    return 0;
}
int binary_insertion_sort(void*, size_t, int , int (*)(void*, void*));
int shell_sort(void*, size_t, int, int (*)(void*, void*));

/**
 * Quick sort
 *
 * Warning: Maybe 'end' isn't N if you want to sort N items!(N-1 may be right!)
 * */
int quick_sort(void* a, size_t len, int start, int end, int (*comp)(void*, void*)) /* This one has FIVE argument*/
{
    int loc;

    // I just detect whethe a is NULL, but I don't make sure that num
    // is in the right arrage!
    if (a == NULL){
        errno = EINVAL;
        return -1;
    }
   
    if (start < end)
    {
        int i = start, j = end;
        void *tmp;
        void *pivot = NULL;

        if ((pivot = malloc(len)) == NULL){
            errno = ENOMEM;
            return -1;
        }
        memcpy(pivot, a+len*start, len);
        if ((tmp = malloc(len)) == NULL){
            free(pivot);
            errno = ENOMEM;
            return -1;
        }

        for(;;)
        {
            while(comp(a+len*j, pivot) >= 0 && j > start)
                j--;
            while(comp(a+len*i, pivot) < 0 && i < end)
                i++;

            if (i < j){
                memcpy(tmp, a+len*i, len);
                memcpy(a+len*i, a+len*j, len);
                memcpy(a+len*j, tmp, len);
            }
            else{
                loc = j;
                memcpy(a+len*start, a+len*j, len);
                memcpy(a+len*j, pivot, len);
                break;
            }
        }

        free(pivot);
        free(tmp);
        quick_sort(a, len, start, loc-1, comp);
        quick_sort(a, len, loc+1, end, comp);
    }
    return 0;
}

/**
 * Heap sorting is good sorting algorithm
 *
 * */
#define LEFT_CHILD(i)   (2*(i)+1)
static void perc_down(void* a, size_t len, int i, int n, int (*comp)(void*, void*))
{
    int child;
    void *temp;

    if ((temp = malloc(len)) == NULL)
    {
        errno = ENOMEM;
        return ;
    }

    memcpy(temp, a+len*i, len);

    child = LEFT_CHILD(i);
    while( child < n)
    {
        if (child != n-1 && comp(a+len*(child+1),a+len*child) > 0)
            child++;
        
        
        if (comp(temp, a+len*child) < 0)
        {
            memcpy(a+len*((child-1)/2), a+len*child, len);
            child = LEFT_CHILD(child);
        }
        else
        {
            break;
        }
    }

    memcpy(a+len*((child-1)/2), temp, len);
    
    free(temp);
}
int heap_sort(void* a, size_t len , int n , int (*comp)(void*, void*))
{
    int i;
    void *temp;
    
    // I just detect whethe a is NULL, but I don't make sure that 'n'
    // is in the right arrage!
    if (a == NULL){
        errno = EINVAL;
        return -1;
    }

    if ((temp = malloc(len)) == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    // build heap
    for (i = n/2; i >= 0; i--)
        perc_down(a, len, i, n, comp);

    //delete max
    for(i=n-1; i > 0; i--)
    {
        memcpy(temp, a, len);
        memcpy(a, a+len*i, len);
        memcpy(a+len*i, temp, len);

        perc_down(a, len, 0, i, comp);
    }

    free(temp);

    return 0;

}


/**
 * Merge sort is also good.
 *
 * */
static int merge(void* a, int l_pos, int r_pos, int r_end, size_t len, int (*comp)(void*, void*))
{
    int i, l_end = r_pos -1;
    int num = r_end - l_pos + 1;
    int temppos = l_pos;

    void * tmp;
    tmp = malloc(num*len);

    if (tmp == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    while(l_pos <= l_end && r_pos <= r_end)
    {
        if (comp(a+len*l_pos, a+len*r_pos) <= 0)
            memcpy(tmp+len*(temppos++), a+len*(l_pos++),len);
        else
            memcpy(tmp+len*(temppos++), a+len*(r_pos++),len);
    }

    while(l_pos <= l_end)
        memcpy(tmp+len*(temppos++), a+len*(l_pos++),len);
    while(r_pos <= r_end)
        memcpy(tmp+len*(temppos++), a+len*(r_pos++),len);

    for (i = 0; i < num; i++, r_end--)
        memcpy(a+len*r_end, tmp+len*r_end, len);

    free(tmp);
    return 0;
}
static int msort(void* a, int left, int right,size_t len, int (*comp)(void*, void*))
{
    int center;
    if (left < right)
    {
        center = (left+right)/2;
        msort(a, left, center, len, comp);
        msort(a, center+1, right, len, comp);

        if (merge(a, left, center+1, right, len, comp) == -1)
            return -1;
    }

    return 0;
}
int merge_sort(void* a, size_t len, int n, int (*comp)(void*, void*))
{
    if (a == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    return msort(a, 0, n-1, len, comp);
}


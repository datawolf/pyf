typedef struct {
    int key;
    int link;
    int linkb;
} element;

#define  SWAP(a, b, element)     { \
    (temp)=(a); (a) = (b); (b) = (temp); \
}
#define MAX_SIZE    1050

void permute(element list[], int n);
void insertion_sort(element list[], int n);
void quiksort(element list[], int left, int right);
void merge_sort(element list[], int n);
void heapsort(element list[], int n);

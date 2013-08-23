typedef struct {
    int key;
    int link;
    int linkb;
} element;

#define  SWAP(a, b, element)     { \
    (temp)=(a); (a) = (b); (b) = (temp); \
}

void permute(element list[], int n);

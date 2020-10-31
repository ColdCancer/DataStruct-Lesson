# include <stdlib.h>
# include <stdio.h>

# define InitSize 100
typedef int ElemType;

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

void InitList(SeqList &L) {
    L.data = new ElemType[InitSize];
    L.MaxSize = InitSize;
    L.length = 0;
}

int Length(SeqList L) {
    return L.length;
}

int LocateElem(SeqList L, ElemType e) {
    int x = 0;
    while(x < L.length && L.data[x] != e) x++;
    return x < L.length ? L.data[x] : 0;
}

int GetElem(SeqList L, int x) {
    if(x < 1 || L.length < x) return 0;
    return L.data[x - 1];
}

bool ListInsert(SeqList &L, int x, ElemType e) {
    if(x < 1 || L.length + 1 < x) return false;
    if(L.MaxSize <= L.length) return false;
    for(int i = L.length; x <= i; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[x - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int x, ElemType &e) {
    if(x < 1 || L.length < x) return false;
    e = L.data[x - 1];
    for(int i = x; i < L.length; i++) {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}

void PrintList(SeqList L) {
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool Empty(SeqList L) {
    return L.length == 0;
}

void DestroyList(SeqList &L) {
    delete L.data;
    L.MaxSize = 0;
    L.length = 0;
}
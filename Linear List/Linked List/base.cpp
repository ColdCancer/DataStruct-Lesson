# include <stdio.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = new LNode();
    L->next = NULL;
    while(scanf("%d", &x), x != -1) {
        s = new LNode();
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    L = new LNode();
    LNode *s, *r = L;
    int x;
    while(scanf("%d", &x), x != -1) {
        s = new LNode();
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int x) {
    if(x == 0) return L;
    if(x < 1) return NULL;
    int i = 1;
    LNode *p = L->next;
    while(p && i < x) {
        p = p->next;
        i++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while(p && p->data != e) {
        p = p->next;
    }
    return p;
}

void List_insertNode(LinkList &L, int x, ElemType e) {
    LNode *s = new LNode();
    s->data = e;
    LNode *p = GetElem(L, x - 1);
    s->next = p->next;
    p->next = s;
}

void List_deleteNode(LinkList &L, int x) {
    LNode *p = GetElem(L, x - 1);
    LNode *q = p->next;
    p->next = q->next;
    delete q;
}

int List_getLength(LinkList L) {
    int count = 0;
    LNode *p = L->next;
    while(p) {
        p = p->next;
        count++;
    }
    return count;
}
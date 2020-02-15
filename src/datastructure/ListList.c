//
// Created by 周树义 on 2020/2/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
    // 结点数据
    DataType data;
    // 结点指针域
    struct node *next;
}ListNote;

typedef ListNote *LinkList;


ListNote * genListNote(int n);

void printListNot(ListNote *p);

//DataType get(LinkList head, int i){
//    ListNote *p = head->next;
//
//    int j = 1;
//
//    while (j < i && p != NULL) {
//        p = p->next;
//    }
//
//    if (i ==j)
//        return p->data;
//     else
//        return 0;
//}



ListNote* subtract(ListNote *a, ListNote *b) {
    ListNote *p = NULL, *q;

    ListNote *per = a;
    p = a->next;
    q = b->next;

    while (p != NULL && q != NULL) {
        if (p->data > q->data){
            q = q->next;
        } else if (p->data < q->data) {
            p = p->next;
            per = per->next;
        } else {
            free(p);
            p = per->next = per->next->next;
            q = q->next;
        }
    }

    if (p == NULL){
        a->next = q;
    }else{
        a->next = p;
    }

    return a;
}

int main(void){
    ListNote *a = genListNote(10);
    printListNot(a);

    ListNote *b = genListNote(4);
    printListNot(b);


    ListNote *pNode = subtract(a, b);

    printListNot(pNode);

}

ListNote * genListNote(int n){
    ListNote *head = (ListNote *) malloc(sizeof(ListNote *));
    ListNote *next = head;

    for (int i = 1; i < n; i++) {
        ListNote *s = (ListNote *) malloc(sizeof(ListNote));
        s->data = i;
        next->next = s;
        next = s;
    }

    return head;
}

void printListNot(ListNote *p){

    ListNote *c = p;

    while (c != NULL) {
        printf("%d ", c->data);
        c = c->next;
    }

    printf("\n");
}
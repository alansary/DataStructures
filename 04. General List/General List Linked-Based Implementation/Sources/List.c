#include <stdlib.h>
#include "List.h"
void CreateList(List *pl) {
    pl->head = NULL;
    pl->size = 0;
}
int ListEmpty(List *pl) {
    return !pl->size;
}
int ListFull(List *pl) {
    return 0;
}
int ListSize(List *pl) {
    return pl->size;
}
void DestroyList(List *pl) {
    ListNode *pn = pl->head;
    while (pn) {
        pn = pn->next;
        free(pl->head);
        pl->head = pn;
    }
    pl->size = 0;
}
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    for (ListNode *pn = pl->head; pn; pn = pn->next)
        (*pf)(pn->entry);
}
void ReplaceList(int p, ListEntry e, List *pl) {
    ListNode *pn;
    int x;
    for (pn = pl->head, x = 0; x < p; pn = pn->next, x++);
    pn->entry = e;
}
void RetrieveList(int p, ListEntry *pe, List *pl) {
    ListNode *pn;
    int x;
    for (pn = pl->head, x = 0; x < p; pn = pn->next, x++);
    *pe = pn->entry;
}
int InsertList(int pos, ListEntry e, List *pl) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (p) {
        p->entry = e;
        if (pos == 0) {
            p->next = pl->head;
            pl->head = p;
        }
        else {
            ListNode *q = pl->head;
            for (int x = 0; x < pos-1; x++)
                q = q->next;
            p->next = q->next;
            q->next = p;
        }
        pl->size++;
        return 1;
    }
    else return 0;
}
void DeleteList(int p, ListEntry *pe, List *pl) {
    ListNode *pn;
    int x;
    if (p == 0) {
        pn = pl->head;
        pl->head = pl->head->next;
        *pe = pn->entry;
        free(pn);
    }
    else {
        for (pn = pl->head, x = 0; x < p-1; x++, pn = pn->next);
        ListNode *qn = pn->next;
        *pe = qn->entry;
        pn->next = pn->next->next;
        free(qn);
    }
    pl->size--;
}


#include "List.h"
#ifdef LIMITED_MEMORY_
// Big-Theta(1)
void CreateList(List *pl) {
    pl->size = 0;
    pl->head = NULL;
}
// Big-Theta(n)
int InsertList(int p, ListEntry e, List *pl) {
    ListNode *qn = (ListNode *)malloc(sizeof(ListNode));
    if (qn) {
	qn->entry = e;
	if (!p) {
	    ListNode *pn;
            int x; 
	    for (pn = pl->head, x = 0; x < p-1; x++)
		pn = pn->next;
	    qn->next = pn->next;
	    pn->next = qn;
	}
	else {
	    qn->next = pl->head;
	    pl->head = qn;
	}
	pl->size++;
        return 1;
    }
    else {
	else return 0;
    }
}
// Big-Theta(n)
void DeleteList(int p, ListEntry *pe, List *pl) {
    if (p) {
        ListNode *pn;
        int x;
        for (pn = pl->head, x = 0; x < p-1; pn = pn->next, x++);
        *pe = pn->next->entry;
        ListNode *qn = pn->next;
        pn->next = pn->next->next;
        free(qn);
    }
    else {
	*pe = pl->head->entry;
	ListNode *pn = pl->head;
	pl->head = pl->head->next;
	free(pn);
    }
    pl->size--;
}
// Big-Theta(1)
int ListEmpty(List *pl) {
    return !pl->size;
}
// Big-Theta(1)
int ListFull(List *pl) {
    return 0;
}
// Big-Theta(1)
int ListSize(List *pl) {
    return pl->size;
}
// Big-Theta(n)
void RetrieveList(int p, ListEntry *pe, List *pl) {
    ListNode *pn;
    int x;
    for (pn = pl->head, x = 0; x < p; x++, pn = pn->next);
    *pe = pn->entry;
}
// Big-Theta(n)
void DestroyList(List *pl) {
    ListNode *pn = pl->head;
    while (pn) {
	pn = pn->next;
	free(pl->head);
	pl->head = pn;
    }
    pl->size = 0;
}
// Big-Theta(n)
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    for (ListNode *pn = pl->head; pn; pn = pn->next)
	(*pf)(pn->entry);
}
// Big-Theta(n)
void ReplaceList(int p, ListEntry e, List *pl) {
    ListNode *pn;
    int x = 0;
    for (pn = pl->head, x = 0; x < p; x++, pn = pn->next);
    pn->entry = e; 
}
#else
// Big-Theta(1)
void CreateList(List *pl) {
    pl->size = 0;
}
// Big-Theta(n)
int InsertList(int pos, ListEntry e, List *pl) {
    for (int x = pl->size; x > pos; x--)
	pl->entry[x] = pl->entry[x-1];
    pl->entry[pos] = e;
    pl->size++;
    return 1;
}
// Big-Theta(n)
void DeleteList(int pos, ListEntry *pe, List *pl) {
    *pe = pl->entry[pos];
    for (int x = pos; x < (pl->size)-1; x++)
	pl->entry[x] = pl->entry[x+1];
    pl->size--;
}
// Big-Theta(1)
int ListFull(List *pl) {
    return pl->size == MAXLIST;
}
// Big-Theta(1)
int ListEmpty(List *pl) {
    return !pl->size;
}
// Big-Theta(1)
int ListSize(List *pl) {
    return pl->size;
}
// Big-Theta(1)
void RetrieveList(int pos, ListEntry *pe, List *pl) {
    *pe = pl->entry[pos];
}
// Big-Theta(1)
void DestroyList(List *pl) {
    pl->size = 0;
}
// Big-Theta(n)
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    for (int x = 0; x < pl->size; x++)
	(*pf)(pl->entry[x]);
}
// Big-Theta(1)
void ReplaceList(int pos, ListEntry e, List *pl) {
    pl->entry[pos] = e;
}
#endif //LIMITED_MEMORY_

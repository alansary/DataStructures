#include <stdio.h>
#include <stdlib.h>
#include "List.h"
void CreateList(List *pl) {
    pl->size = 0;
    pl->head = NULL;
}
int InsertList(int pos, ListEntry e, List *pl) {
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode));
    if (pn) {
	pn->entry = e;
	if (pos) {
	    if (pos <= pl->currentpos) {
		pl->currentpos = 0;
		pl->current = pl->head;
	    }
	    for (; pl->currentpos < pos-1; pl->currentpos++)
		pl->current = pl->current->next;
	    pn->next = pl->current->next;
	    pl->current->next = pn;
	}
	else {
	    pn->next = pl->head;
	    pl->head = pn;
	    pl->currentpos = 0;
	    pl->current = pl->head;
	}
	pl->size++;
	return 1;
    }
    else
	return 0;
}
void DeleteList(int pos, ListEntry *pe, List *pl) {
    if (pos) {
        if (pos <= pl->currentpos) {
	    pl->currentpos = 0;
	    pl->current = pl->head;
        }
        for (; pl->currentpos < pos-1; pl->currentpos++)
	    pl->current = pl->current->next;
        *pe = pl->current->next->entry;
        ListNode *pn = pl->current->next;
        pl->current->next = pl->current->next->next;
        free(pn);
    }
    else {
	*pe = pl->head->entry;
	pl->current = pl->head->next;
	free(pl->head);
	pl->head = pl->current;
	pl->currentpos = 0;
    }
    pl->size--;
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
void RetrieveList(int pos, ListEntry *pe, List *pl) {
    if (pos <= pl->currentpos) {
	pl->currentpos = 0;
	pl->current = pl->head;
    }
    for (; pl->currentpos < pos; pl->currentpos++)
	pl->current = pl->current->next;
    *pe = pl->current->entry;
}
void DestroyList(List *pl) {
    for (ListNode *pn = pl->head; pn;) {
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
void ReplaceList(int pos, ListEntry e, List *pl) {
    if (pos <= pl->currentpos) {
	pl->currentpos = 0;
	pl->current = pl->head;
    }
    for (; pl->currentpos < pos; pl->currentpos++)
	pl->current = pl->current->next;
    pl->current->entry = e;
}


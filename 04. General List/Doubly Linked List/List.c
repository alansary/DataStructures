#include <stdlib.h>
#include "List.h"
void CreateList(List *pl) {
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
    pl->currentpos = -1;
    pl->current = NULL;
}
int InsertList(int pos, ListEntry e, List *pl) {
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode));
    if (pn) { //pn allocated successfully
	pn->entry = e;
	if (!pl->size) { //First node
	    pl->head = pn;
	    pl->tail = pn;
	    pl->current = pn;
	    pl->currentpos = 0;
	    pn->next = NULL;
	    pn->prev = NULL;
	}
	else { //Not the first node
	    if (!pos) { //head insertion
		pn->next = pl->head;
		pl->current = pn;
		pl->currentpos = 0;
		pl->head = pn;
		pn->prev = NULL;
	    }
	    else if (pos == pl->size) { //tail insertion
		pl->tail->next = pn;
		pn->next = NULL;
		pn->prev = pl->tail;
		pl->tail = pn;
		pl->current = pn;
		pl->currentpos = pl->size;
	    }
	    else { //current insertion
		if (pl->currentpos < pos) { //currentpos < pos
		    while (pl->currentpos < pos-1) {
			pl->current = pl->current->next;
			pl->currentpos++;
		    }
		    pn->next = pl->current->next;
		    pn->prev = pl->current;
		    pl->current->next = pn;
		    pl->current->next->prev = pn;
		    pl->current = pn;
		    pl->currentpos++;
		}
		else if (pl->currentpos > pos) { //currentpos > pos
		    while (pl->currentpos > pos) {
			pl->current = pl->current->prev;
			pl->currentpos--;
		    }
		    pn->next = pl->current;
		    pn->prev = pn->next->prev;
		    pl->current->prev = pn;
		    pn->prev->next = pn;
		    pl->current = pn;
		    pl->currentpos--;
		}
		else { //currentpos == pos
		    pn->prev = pl->current->prev;
		    pn->next = pl->current;
		    pn->prev->next = pn;
		    pn->next->prev = pn;
		    pl->current = pn;
		}
	    }
	}
	pl->size++;
	return 1;
    }
    else return 0;
}
void DeleteList(int pos, ListEntry *pe, List *pl) {
    if (pl->size == 1) { //The only node exists
	*pe = pl->head->entry;
	pl->head = NULL;
	pl->tail = NULL;
	pl->current = NULL;
	pl->currentpos = -1;
    }
    else { //There exist more than one node
	ListNode *pn;
	if (pos == 0) { //head deletion
	    *pe = pl->head->entry;
	    pn = pl->head;
	    pl->head = pl->head->next;
	    pl->head->prev = NULL;
	    free(pn);
	    pl->current = pl->head;
	    pl->currentpos = 0;
	}
	else if (pos == pl->size-1) { //tail deletion
	    pn = pl->tail;
	    *pe = pn->entry;
	    pl->tail = pl->tail->prev;
	    pl->tail->next = NULL;
	    free(pn);
	    pl->current = pl->tail;
	    pl->currentpos = pl->size-2;
	}
	else { //current deletion
	    if (pl->currentpos < pos) { //currentpos < pos
		while (pl->currentpos < pos-1) {
		    pl->current = pl->current->next;
		    pl->currentpos++;
		}
		pn = pl->current->next;
		*pe = pn->entry;
		pl->current->next = pn->next;
		pn->next->prev = pl->current;
		free(pn);
	    }
	    else if (pl->currentpos > pos) { //currentpos > pos
		while (pl->currentpos > pos-1) {
		    pl->currentpos--;
		    pl->current = pl->current->prev;
		}
		pn = pl->current->next;
		*pe = pn->entry;
		pl->current->next = pn->next;;
		pn->next->prev = pl->current;
		free(pn);
	    }
	    else { //currentpos == pos
		pn = pl->current;
		pn->prev->next = pn->next;
		pn->next->prev = pn->prev;
		pl->current = pn->prev;
		pl->currentpos--;
		*pe = pn->entry;
		free(pn);
	    }
	}
    }
    pl->size--;
}
int ListFull(List *pl) {
    return 0;
}
int ListEmpty(List *pl) {
    return !pl->size;
}
int ListSize(List *pl) {
    return pl->size;
}
void DestroyList(List *pl) {
    pl->tail = pl->head;
    while (pl->tail) {
	pl->tail = pl->tail->next;
	free(pl->head);
	pl->head = pl->tail;
    }
    pl->size = 0;
    pl->currentpos = -1;
    pl->current = NULL;
}
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    ListNode *pn = pl->head;
    while (pn) {
	(*pf)(pn->entry);
	pn = pn->next;
    }
}
void RetrieveList(int pos, ListEntry *pe, List *pl) {
    if (pos == 0)
	*pe = pl->head->entry;
    else if (pos == pl->size-1)
	*pe = pl->tail->entry;
    else {
	if (pl->currentpos > pos) {
	    while (pl->currentpos != pos) {
		pl->currentpos--;
		pl->current = pl->current->prev;
	    }
	}
	else if (pl->currentpos < pos) {
	    while (pl->currentpos !=pos) {
		pl->currentpos++;
		pl->current = pl->current->next;
	    }
	}
	*pe = pl->current->entry;
    }	
}
void ReplaceList(int pos, ListEntry e, List *pl) {
    if (pos == 0)
	pl->head->entry = e;
    else if (pos == pl->size-1)
	pl->tail->entry = e;
    else {
	if (pl->currentpos > pos) {
	    while (pl->currentpos != pos) {
		pl->currentpos--;
		pl->current = pl->current->prev;
	    }
	}
	else if (pl->currentpos < pos) {
	    while (pl->currentpos != pos) {
		pl->currentpos++;
		pl->current = pl->current->next;
	    }
	}
	pl->current->entry = e;
    }
}

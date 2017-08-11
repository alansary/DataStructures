#include "List.h"
void CreateList(List *pl) {
    pl->size = 0;
}
void InsertList(int p, ListEntry e, List *pl) {
    for (int x = (pl->size)-1; x >= p; x--)
        pl->entry[x+1] = pl->entry[x];
    pl->entry[p] = e;
    pl->size++;
}
void DeleteList(int p, ListEntry *pe, List *pl) {
    *pe = pl->entry[p];
    for (int x = p+1; x < (pl->size); x++)
        pl->entry[x-1] = pl->entry[x];
    pl->size--;
}
int ListFull(List *pl) {
    return pl->size == MAXLIST;
}
int ListEmpty(List *pl) {
    return !pl->size;
}
void DestroyList(List *pl) {
    pl->size = 0;
}
int ListSize(List *pl) {
    return pl->size;
}
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    for (int x = 0; x < pl->size; x++)
        (*pf)(pl->entry[x]);
}
void RetrieveList(int p, ListEntry *pe, List *pl) {
    *pe = pl->entry[p];
}
void ReplaceList(int p, ListEntry e, List *pl) {
    pl->entry[p] = e;
}


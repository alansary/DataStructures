#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int ListEntry;
//#define LIMITED_MEMORY_
#ifdef LIMITED_MEMORY_
#include <stdlib.h>
typedef struct listnode {
    ListEntry entry;
    struct listnode *next;
}ListNode;
typedef struct list {
    ListNode *head;
    int size;
}List;
#else
#define MAXLIST 100
typedef struct list {
    ListEntry entry[MAXLIST];
    int size;
}List;
#endif //LIMITED_MEMORY_

void CreateList(List *);
int InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
int ListFull(List *);
int ListEmpty(List *);
void DestroyList(List *);
int ListSize(List *);
void RetrieveList(int, ListEntry *, List *);
void TraverseList(List *, void(*)(ListEntry));
void ReplaceList(int, ListEntry, List *);

#endif //LIST_H_INCLUDED

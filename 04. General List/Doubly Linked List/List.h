#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int ListEntry;
typedef struct listnode {
    struct listnode *next, *prev;
    ListEntry entry;
}ListNode;
typedef struct list {
    int size, currentpos;
    ListNode *head, *tail, *current;
}List;

void CreateList(List *);
int InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
int ListFull(List *);
int ListEmpty(List *);
int ListSize(List *);
void RetrieveList(int, ListEntry *, List *);
void DestroyList(List *);
void TraverseList(List *, void(*)(ListEntry));
void ReplaceList(int, ListEntry, List *);

#endif //LIST_H_INCLUDED

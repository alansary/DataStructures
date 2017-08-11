#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
typedef int ListEntry;
typedef struct listnode {
    ListEntry entry;
    struct listnode *next;
}ListNode;
typedef struct list {
    ListNode *head;
    int size;
}List;
void CreateList(List *);
int InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
int ListFull(List *);
int ListEmpty(List *);
int ListSize(List *);
void TraverseList(List *, void(*)(ListEntry));
void DestroyList(List *);
void RetrieveList(int, ListEntry *, List *);
void ReplaceList(int, ListEntry, List *);
#endif

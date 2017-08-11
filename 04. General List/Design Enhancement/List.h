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
    ListNode *current;
    int currentpos;
}List;
void CreateList(List *);
int InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
int ListFull(List *);
int ListEmpty(List *);
int ListSize(List *);
void DestroyList(List *);
void TraverseList(List *, void(*)(ListEntry));
void RetrieveList(int, ListEntry *, List *);
void ReplaceList(int, ListEntry, List *);

#endif //LIST_H_INCLUDED

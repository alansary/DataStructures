#include <stdio.h>
#include <stdlib.h>
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

void Display(ListEntry);
void main(void) {
    List l;
    CreateList(&l);
    ListEntry e;
    int p;
    for (int x = 0; x <= 11; x++) {
        printf("%s", "Enter the position p and the element e: ");
        scanf("%d%d", &p, &e);
        if (!ListFull(&l)) {
            if (InsertList(p, e, &l))
                printf("%s", "Successfully inserted\n");
            else
                printf("%s", "Problem allocating memory\n");
        }
        else {
            printf("%s", "The list is full\n");
            break;
        }
    }
    printf("The size of the list is %d\n", ListSize(&l));
    printf("%s", "The elements of the list are:\n");
    TraverseList(&l, &Display);
    printf("%s", "\n");
    for (int x = 0; x < 2; x++) {
        printf("%s", "Enter the position to retrieve the element: ");
        scanf("%d", &p);
        RetrieveList(p, &e, &l);
        printf("The element %d is at the position %d\n", e, p);
    }
    for (int x = 0; x < 2; x++) {
        printf("%s",
        "Enter the position p and the element e to replace the value: ");
        scanf("%d%d", &p, &e);
        ReplaceList(p, e, &l);
    }
    printf("%s", "The elements of the list are:\n");
    TraverseList(&l, &Display);
    puts("");
    for (int x = 0; x < 5; x++) {
        printf("%s", "Enter the position p to delete from the list: ");
        scanf("%d", &p);
        if (!ListEmpty(&l)) {
            DeleteList(p, &e, &l);
            printf("The element %d has been removed from the index %d\n",
                   e, p);
        }
        else {
            printf("%s", "The list is empty\n");
            break;
        }
    }
    printf("%s", "The elements of the list are:\n");
    TraverseList(&l, &Display);
    puts("");
    printf("The size of the list now is %d\n", ListSize(&l));
    printf("%s", "Destroying the list...\n");
    DestroyList(&l);
    printf("The size of the list now is %d\n", ListSize(&l));
}
void Display(ListEntry e) {
    printf("%d  ", e);
}

// Big-Theta(1)
void CreateList(List *pl) {
    pl->head = NULL;
    pl->size = 0;
}
// Big-Theta(1)
int ListEmpty(List *pl) {
    return !pl->size;
    // return !pl->head
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
    int x;
    for (pn = pl->head, x = 0; x < p; pn = pn->next, x++);
    pn->entry = e;
}
// Big-Theta(n)
void RetrieveList(int p, ListEntry *pe, List *pl) {
    ListNode *pn;
    int x;
    for (pn = pl->head, x = 0; x < p; pn = pn->next, x++);
    *pe = pn->entry;
}
// Big-Theta(n)
int InsertList(int pos, ListEntry e, List *pl) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (p) {
        p->entry = e;
        if (pos == 0) { //will work also for head equals NULL
	    p->next = pl->head;
	    pl->head = p;
        }
        else {
            //q points to the prev ListNode (pos-1)
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
/*
We should make sure that the memory is not full when we call malloc
(as we did previously). We have to design the function to return int
not void and we modify the contiguous implementation accordingly to
return 1 always.
*/
// Big-Oh(n) but without shifting elements.
void DeleteList(int p, ListEntry *pe, List *pl) {
    ListNode *pn;
    int x;
    if (p == 0) {
	pn = pl->head;
	pl->head = pl->head->next;
	*pe = pn->entry;
	free(pn);
    } //it works also for one node
    else {
	//pn points to pos-1
	for (pn = pl->head, x = 0; x < p-1; x++, pn = pn->next);
        ListNode *qn = pn->next;
        *pe = qn->entry;
        pn->next = pn->next->next;
        free(qn);
    }
    pl->size--;
}

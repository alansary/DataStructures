#include <stdio.h>
typedef int ListEntry;
#define MAXLIST 10
typedef struct list {
    int size;
    ListEntry entry[MAXLIST];
}List;
/*Postcondition:
    - The list has been initialized.
*/
void CreateList(List *);
/*Precondition:
    1- The list l has been created.
    2- not full.
    3- 0 <= p <= size.
  Postcondition:
    1- e has been inserted at position p.
    2- all elements at old positions p, p+1, ..., size-1 are incremented
       by 1.
    3- size increases by 1.
*/
void InsertList(int, ListEntry, List *);
/*Precondition:
    - The list l has been created, not empty, and 0 <= p <= size-1
  Postcondition:
    - e has been retrieved from position p, and all elements at old
      positions p+1, ..., size-1 are decremented by 1. size decreases by 1.
*/
void DeleteList(int, ListEntry *, List *);
/*Precondition:
    - The list has been created.
  Postcondition:
    - Returns whether the list if full or not.
*/
int ListFull(List *);
/*Precondition:
    - The list has been created.
  Postcondition:
    - Returns whether the list is empty or not.
*/
int ListEmpty(List *);
/*Precondition:
    - The list has been created.
  Postcondition:
    - The list has been cleared and looks like initialized.
*/
void DestroyList(List *);
/*Precondition:
    - The list has been created.
  Postcondition:
    - Returns the number of elements of the list.
*/
int ListSize(List *);
/*Precondition:
    - The list has been created.
  Postcondition:
    - The passed function traverses each element of the list.
*/
void TraverseList(List *, void(*)(ListEntry));
/*Precondition:
    - The list has been created and not empty.
    - The position 0 <= p <= size-1.
  Postcondition:
    - The element at position p has been retrieved in e.
*/
void RetrieveList(int, ListEntry *, List *);
/*Precondition:
    - The list has been created and not empty.
    - The position 0 <= p <= size-1.
  Postcondition:
    - The element at index p has been replaced by the passed ListEntry.
*/
void ReplaceList(int, ListEntry, List *);

/*Issues at the user level:

  How to insert at the beginning of the list?
  InsertList(0, e, &l);

  How to insert at the end of the list?
  InsertList(ListSize(&l), e, &l);

  How to use it as a stack?
  Insert and Delete from the same side (start/end).

  How to use it as a queue?
  Insert from one side and Delete from the other side.
*/
void Display(ListEntry);
void main(void) {
    List l;
    CreateList(&l);
    ListEntry e;
    int p;
    for (int x = 0; x <= 11; x++) {
	printf("%s", "Enter the position p and the element e: ");
	scanf("%d%d", &p, &e);
	if (!ListFull(&l))
	    InsertList(p, e, &l);
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
// Big-Theta(1)
void CreateList(List *pl) {
    pl->size = 0;
}
// Big-Theta(n)
// Inserting one element requires too many shifting!!
void InsertList(int p, ListEntry e, List *pl) {
    /*The loop shifts up all the elements in
    the range [p, size-1] to free the pth
    location*/
    for (int x = pl->size-1; x >= p; x--)
	pl->entry[x+1] = pl->entry[x];
    pl->entry[p] = e;
    pl->size++;
}
// Big-Theta(n)
// Deleting one element requires too many shifting!!
void DeleteList(int p, ListEntry *pe, List *pl) {
    *pe = pl->entry[p];
    /*The loop shifts down all the elements in
    the range [p+1, size-1] to free the pth
    location*/
    for (int x = p+1; x < pl->size; x++)
	pl->entry[x-1] = pl->entry[x];
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
void DestroyList(List *pl) {
    pl->size = 0;
}
// Big-Theta(1)
int ListSize(List *pl) {
    return pl->size;
}
// Big-Theta(n)
void TraverseList(List *pl, void(*pf)(ListEntry)) {
    for (int x = 0; x < pl->size; x++)
	(*pf)(pl->entry[x]);
}
// Big-Theta(1)
void RetrieveList(int p, ListEntry *pe, List *pl) {
    *pe = pl->entry[p];
}
// Big-Theta(1)
void ReplaceList(int p, ListEntry e, List *pl) {
    pl->entry[p] = e;
}

void Display(ListEntry e) {
    printf("%d  ", e);
}


#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

#endif //LIST_H_INCLUDED

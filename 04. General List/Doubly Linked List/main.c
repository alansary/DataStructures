#include <stdio.h>
#include "List.h"
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
            if (InsertList(p, e, &l)) {
		printf("%s", "Successfully inserted\n");
		TraverseList(&l, &Display);
		printf("%s", "\n");
	    }
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
	    TraverseList(&l, &Display);
	    puts("");
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


#include <stdio.h>
#include "Stack.h"
#include <stdlib.h> //to use free
typedef int StackEntry;
void Display(void *);
void main(void) {
    Stack s;
    CreateStack(&s);
    StackEntry e;
    void *ptr;
    char c; //to see the output on the screen step by step
    for (int x = 0; x < 6; x++) {
        if (!StackFull(&s)) {
            printf("%s", "Enter an element to push onto the top of the stack: ");
            scanf("%d", &e);
	    if (Push((void *)&e, &s, sizeof(e))) {
	        printf("The element %d has been pushed successfully\n", e);
		puts("The elements of the stack are:");
		TraverseStack(&s, &Display);
		puts("");
		printf("The size of the stack is %d\n", StackSize(&s));
		StackTop(&ptr, &s, sizeof(e));
		printf("The top of the stack is %d\n", *((int *)ptr));
		free(ptr);
		scanf("%c", &c);
	    }
	    else {
	        printf("%s", "There is an error allocating memory space\n");
		scanf("%c", &c);
	        break;
	    }
        }
        else {
	    puts("The stack is already full");
	    scanf("%c", &c);
        }
    }
    for (int x = 0; x < 6; x++) {
	if (!StackEmpty(&s)) {
	    puts("");
	    Pop(&ptr, &s, sizeof(e));
	    printf("The element %d has been popped of the stack\n",
		   *((int *)ptr));
	    puts("The elements of the stack are:");
	    TraverseStack(&s, &Display);
	    free(ptr);
	    printf("The size of the stack is %d\n", StackSize(&s));
	    scanf("%c", &c);
	}
	else {
	    puts("The stack is already empty");
	    scanf("%c", &c);
	    break;
	}
    }
    for (int x = 0; x < 6; x++) {
        if (!StackFull(&s)) {
            printf("%s", "Enter an element to push onto the top of the stack: ");
            scanf("%d", &e);
            if (Push((void *)&e, &s, sizeof(e))) {
                printf("The element %d has been pushed successfully\n", e);
                puts("The elements of the stack are:");
                TraverseStack(&s, &Display);
                puts("");
                printf("The size of the stack is %d\n", StackSize(&s));
                StackTop(&ptr, &s, sizeof(e));
                printf("The top of the stack is %d\n", *((int *)ptr));
		free(ptr);
		scanf("%c", &c);
            }   
            else {
                printf("%s", "There is an error allocating memory space\n");
		scanf("%c", &c);
                break;
            }   
        }   
        else {
            puts("The stack is already full");
	    scanf("%c", &c);
        }   
    }   
    puts("Clearing the stack");
    ClearStack(&s);
    printf("The stack size now is %d\n", StackSize(&s));
    scanf("%c", &c);
    puts("The elements of the stack are:");
    TraverseStack(&s, &Display);
    puts("");
}
void Display(void *ptr) {
    printf("%d  ", *((int *)ptr));
}

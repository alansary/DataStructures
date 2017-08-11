/*
#############################################################
#               Stack Array Based Implementation            #
#                   Author: Mohamed Alansary                #
#                Department Of Computer Science             #
#                       Tanta University                    #
#                   Created on: Nov 16, 2016                #
#############################################################
*/

#include <stdio.h>
#include "Stack.h"

static int maxnum = 0; //for Maximum function
int num = 0; //for Search function
void Display(StackEntry e);
void Search(StackEntry e);
void Maximum(StackEntry e);
void main(void) {
    //User Level
    Stack s;
    CreateStack(&s);
    StackEntry e;
    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d has been pushed\n", e);
    }

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d has been pushed\n", e);
    }

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }

    //Pop
    if(!StackEmpty(&s))
        Pop(&e, &s);
    printf("Popped element is: %d\n", e);

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }

    //Pop
    if(!StackEmpty(&s))
        Pop(&e, &s);
    printf("Popped element is: %d\n", e);

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }
    else
        printf("Stack is empty...\n");

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //StackTop
    if(!StackEmpty(&s)){
        StackTop(&e, &s);
        printf("Top element is %d\n", e);
    }
    else
        printf("Stack is empty...\n");
    //StackSize
    int x;
    x = StackSize(&s);
    printf("The size of the stack is %d\n", x);

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }

    //StackSize
    x = StackSize(&s);
    printf("The size of the stack is %d\n", x);

    //ClearStack
    ClearStack(&s);

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }
    else
        printf("Stack is already empty...\n");

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //Push
    printf("Enter an element to push into the stack:\n");
    scanf("%d", &e);
    if(!StackFull(&s)) {
        Push(e, &s);
        printf("%d is pushed\n", e);
    }

    //Display
    if(!StackEmpty(&s)){
        printf("Elements of the stack are:\n");
        TraverseStack(&s, &Display);
        printf("\n");
    }

    //Search
    if(!StackEmpty(&s)){
        printf("Enter a number to search for:\n");
        scanf("%d", &num);
        TraverseStack(&s, &Search);
    }

    //Maximum
    if(!StackEmpty(&s)){
        TraverseStack(&s, &Maximum);
        printf("Maximum number is %d\n", maxnum);
    }
}
void Display(StackEntry e) {
    printf("%d  ", e);
}
void Search(StackEntry e) {
    if(num == e) printf("Found\n");
}
void Maximum(StackEntry e) {
    if(e >= maxnum) maxnum = e;
}

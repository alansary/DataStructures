#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//#define LIMITED_MEMORY_
typedef int StackEntry;
#ifdef LIMITED_MEMORY_
#include <stdlib.h>
typedef struct stacknode {
    StackEntry entry;
    struct stacknode *next;
}StackNode;
typedef struct stack {
    int size;
    StackNode *top;
}Stack;
#else
#define MAXSTACK 100
typedef struct stack {
    StackEntry entry[MAXSTACK];
    int top;
}Stack;
#endif //LIMITED_MEMORY_
void CreateStack(Stack *);
int Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
int StackSize(Stack *);
void StackTop(StackEntry *, Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void(*)(StackEntry));
#endif //STACK_H_INCLUDED

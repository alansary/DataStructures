#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stackentry {
    short int etype;
    char infixToPostfix;
    double evaluatePostfix;
}StackEntry;

//#define LIMITED_MEMORY_
#ifdef LIMITED_MEMORY_
typedef struct stacknode {
    StackEntry entry;
    struct stacknode *next;
}StackNode;

typedef struct stack {
    StackNode *top;
    int size;
}Stack;
#else
#define MAXSTACK 100
typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
}Stack;
#endif //LIMITED_MEMORY_

void CreateStack(Stack *);
void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
int StackSize(Stack *);
void StackTop(StackEntry *, Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void(*)(StackEntry));

#endif //STACK_H_INCLUDED

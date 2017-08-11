#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//#define LIMITED_MEMORY_
#ifdef LIMITED_MEMORY_
typedef struct stacknode {
    struct stacknode *next;
    void *entry; //void pointer to some datatype
}StackNode;
typedef struct stack {
    StackNode *top;
    int size;
}Stack;
#else
#define MAXSTACK 5
typedef struct stack {
    int top;
    void *entry[MAXSTACK]; //array of void pointers to some datatype
}Stack;
#endif //LIMITED_MEMORY_ 
void CreateStack(Stack *);
int Push(void *, Stack *, int);
void Pop(void **, Stack *, int);
int StackFull(Stack *);
int StackEmpty(Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void(*)(void *));
void StackTop(void **, Stack *, int);
int StackSize(Stack *);

#endif //STACK_H_INCLUDED

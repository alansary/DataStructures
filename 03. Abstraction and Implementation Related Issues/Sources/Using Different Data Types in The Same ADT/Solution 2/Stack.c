#include "Stack.h"
#ifdef LIMITED_MEMORY_
#include <stdlib.h>
void CreateStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}
void Push(StackEntry e, Stack *ps) {
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->top->entry;
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}
int StackEmpty(Stack *ps) {
    return !ps->top;
}
int StackFull(Stack *ps) {
    return 0;
}
void ClearStack(Stack *ps) {
    StackNode *pn = ps->top;
    while (pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for(StackNode *pn = ps->top; pn; pn = pn->next)
        (*pf)(pn->entry);
}
int StackSize(Stack *ps) {
    return ps->size;
}
void StackTop(StackEntry *pe, Stack *ps) {
    *pe = ps->top->entry;
}
#else
void CreateStack(Stack *ps) {
    ps->top = 0;
}
void Push(StackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}
int StackFull(Stack *ps) {
    return ps->top == MAXSTACK;
}
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}
int StackEmpty(Stack *ps) {
    return !ps->top;
}
void StackTop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[ps->top-1];
}
int StackSize(Stack *ps) {
    return ps->top;
}
void ClearStack(Stack *ps) {
    ps->top = 0;
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for(int i = ps->top; i > 0; i--)
        (*pf)(ps->entry[i-1]);
}
#endif //LIMITED_MEMORY_

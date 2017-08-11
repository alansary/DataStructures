#include "Stack.h"
#ifdef LIMITED_MEMORY_
void CreateStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}
int Push(StackEntry e, Stack *ps) {
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    if (pn) {
	pn->entry = e;
	pn->next = ps->top;
	ps->top = pn;
	ps->size++;
	return 1;
    }
    else return 0;
}
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->top->entry;
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}
int StackFull(Stack *ps) {
    return 0;
}
int StackEmpty(Stack *ps) {
    return !ps->top;
}
void StackTop(StackEntry *pe, Stack *ps) {
    *pe = ps->top->entry;
}
int StackSize(Stack *ps) {
    return ps->size;
}
void ClearStack(Stack *ps) {
    for (StackNode *pn = ps->top; pn; ) {
	pn = pn->next;
	free(ps->top);
	ps->top = pn;
    }
    ps->size = 0;
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for (StackNode *pn = ps->top; pn; pn = pn->next)
	(*pf)(pn->entry);
}
#else
void CreateStack(Stack *ps) {
    ps->top = 0;
}
int Push(StackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
    return 1;
}
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}
int StackFull(Stack *ps) {
    return ps->top == MAXSTACK;
}
int StackEmpty(Stack *ps) {
    return !ps->top;
}
int StackSize(Stack *ps) {
    return ps->top;
}
void ClearStack(Stack *ps) {
    ps->top = 0;
}
void StackTop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[ps->top - 1];
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for (int x = ps->top; x > 0; x--)
	(*pf)(ps->entry[x - 1]);
}
#endif //LIMITED_MEMORY_

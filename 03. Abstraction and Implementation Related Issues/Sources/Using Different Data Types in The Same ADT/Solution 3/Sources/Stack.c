#include "Stack.h"
#include <stdlib.h> //to use free
#include <string.h> //to use memcpy
#ifdef LIMITED_MEMORY_
void CreateStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}
int Push(void *pe, Stack *ps, int z) {
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    void *ptr = malloc(z);
    if (pn && ptr) {
        pn->next = ps->top;
        ps->top = pn;
        memcpy(ptr, pe, z);
        pn->entry = ptr;
        ps->size++;
	return 1;
    }
    else
	return 0;
}
//the user has to free pe himself
void Pop(void **ppe, Stack *ps, int s) {
    *ppe = malloc(s);
    memcpy(*ppe, ps->top->entry, s);
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn->entry);
    free(pn);
    ps->size--;
}
int StackFull(Stack *ps) {
    return 0;
}
int StackEmpty(Stack *ps) {
    return !ps->size;
}
void ClearStack(Stack *ps) {
    StackNode *pn = ps->top;
    while (pn) {
	pn = pn->next;
	free(ps->top->entry);
	free(ps->top);
	ps->top = pn;
    }
    ps->size = 0;
}
void TraverseStack(Stack *ps, void(*pf)(void *)) {
    for (StackNode *pn = ps->top; pn; pn = pn->next)
	(*pf)(pn->entry);
}
//the user has to free pe himself
void StackTop(void **ppe, Stack *ps, int s) {
    *ppe = malloc(s);
    memcpy(*ppe, ps->top->entry, s);
}
int StackSize(Stack *ps) {
    return ps->size;
}
#else
void CreateStack(Stack *ps) {
    ps->top = 0;
}
int Push(void *pe, Stack *ps, int z) {
    void *ptr = malloc(z);
    if (ptr) {
        memcpy(ptr, pe, z);
        ps->entry[ps->top++] = ptr;
	return 1;
    }
    else
	return 0;
}
//the user has to free pe himself
void Pop(void **ppe, Stack *ps, int s) {
    *ppe = malloc(s);
    memcpy(*ppe, ps->entry[--ps->top], s);
    free(ps->entry[ps->top]);
}
int StackFull(Stack *ps) {
    return ps->top == MAXSTACK;
}
int StackEmpty(Stack *ps) {
    return !ps->top;
}
void ClearStack(Stack *ps) {
    for (int x = ps->top; x > 0; x--)
	free(ps->entry[x-1]);
    ps->top = 0;
}
void TraverseStack(Stack *ps, void(*pf)(void *)) {
    for (int x = ps->top; x > 0; x--)
	(*pf)(ps->entry[x-1]);
}
//the user has to free pe himself
void StackTop(void **ppe, Stack *ps, int s) {
    *ppe = malloc(s);
    memcpy(*ppe, ps->entry[ps->top -1], s);
}
int StackSize(Stack *ps) {
    return ps->top;
}
#endif //LIMITED_MEMORY_

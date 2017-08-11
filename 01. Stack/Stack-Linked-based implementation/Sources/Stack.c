/*
#############################################################
#               Stack Array Based Implementation            #
#                   Author: Mohamed Alansary                #
#                Department Of Computer Science             #
#                       Tanta University                    #
#                   Created on: Nov 16, 2016                #
#############################################################
*/

#include "Stack.h"
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

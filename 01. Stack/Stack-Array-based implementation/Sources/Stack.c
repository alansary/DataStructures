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

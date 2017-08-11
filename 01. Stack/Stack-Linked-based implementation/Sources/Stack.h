/*
#############################################################
#               Stack Array Based Implementation            #
#                   Author: Mohamed Alansary                #
#                Department Of Computer Science             #
#                       Tanta University                    #
#                   Created on: Nov 16, 2016                #
#############################################################
*/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define StackEntry int

typedef struct stacknode {
    StackEntry entry;
    struct stacknode *next;
}StackNode;

typedef struct stack {
    StackNode *top;
    int size;
}Stack;

void CreateStack(Stack *);
/*
 *Pre: The stack exists and is initialized.
 *Post: The argument item has been stored at the top of the stack
 */
void Push(StackEntry, Stack *);
/*Pre: The stack exists and it is not empty.
 *Post: The item at the top of the stack has been removed and returned.
 */
void Pop(StackEntry *, Stack *);
/*Pre: The stack exists
 *Post: returns the status, 1 or 0
 */
int StackEmpty(Stack *ps);
int StackFull(Stack *ps);
/*Pre: The stack exists
 *Post: All the elements freed
 */
void ClearStack(Stack *ps);
/*Pre: The stack exists
 *Post: Function is passed to process every element
 */
void TraverseStack(Stack *ps, void(*pf)(StackEntry));
/*Pre: The stack exists
 *Post: Returns the number of elements
 */
int StackSize(Stack *ps);
/*
 *Pre: The stack is initialized and not empty.
 *Post: The top element of the stack is returnd in the element.
 */
void StackTop(StackEntry *, Stack *);
#endif //STACK_H_INCLUDED

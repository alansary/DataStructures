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
#define MAXSTACK 100

typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

/*
 *Post: The stack is initialized.
 */
void CreateStack   (Stack *);
/*
 *Pre: The stack is initialized and not full.
 *Post: The element has been stored at the top of the stack
 */
void Push          (StackEntry, Stack *);
/*
 *Pre: The stack is initialized
 *Post: Rturns whether the stack is full or not
 */
int  StackFull     (Stack *);
/*
 *Pre: The stack is initialized and not empty
 *Post: The last element entered is returned
 */
void Pop           (StackEntry *, Stack *);
/*
 *Pre: The stack is initialized
 *Post: Returnes whether the stack is empty or not
 */
int  StackEmpty    (Stack *);
/*
 *Pre: The stack is initialized and not empty
 *Post: The last element entered is copyied
 */
void StackTop      (StackEntry *, Stack *);
/*
 *Pre: The stack is initialized
 *Post: Returns how many elements exist
 */
int  StackSize     (Stack *);
/*
 *Pre: The stack is initialized
 *Post: Destroy all elements; the stack looks initialized
 */
void ClearStack    (Stack *);
/*
 *Pre: The stack is initialized
 *Post: The function traverses each element of the stack
 */
void TraverseStack (Stack *, void(*)(StackEntry));
#endif // STACK_H_INCLUDED

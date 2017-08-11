#include <stdio.h>
#include <stdlib.h>

//Linked Stacks (to overcome fixed size limitations)
//Dynamic Memory Allocation
typedef int StackEntry;

typedef struct stacknode {
    StackEntry entry;
    struct stacknode *next;
}StackNode;

typedef struct stack {
    StackNode *top;
    //Added section
    int size;
}Stack;
/*
 *Why not:
 *typedef StackNode *Stack;
 *1. To make logical distinction between the stack itself and its top,
 *   which points to a node.
 *2. To be consistent with the definitions of other DS.
 *3. For upgradability (adding more functions) that may need pieces of
 *   information to be saved than top, (we will see).
*/
void CreateStack(Stack *);
void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
int StackFull(Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void(*)(StackEntry));
int StackSize(Stack *);

void Display(StackEntry e) {
    printf("%d  ", e);
}
void main(void) {
    Stack s; //Creation of the Stack
    StackEntry e;
    CreateStack(&s); //Initialization occured here
    if (!StackFull(&s))
        Push(e, &s);
    if (!StackEmpty(&s))
        Pop(&e, &s);
    ClearStack(&s);
    TraverseStack(&s, &Display);
    int x = StackSize(&s);
}
//Always take care of special cases (boundary conditions)
/*
 *For any function that does not change the stack there is no problem
 *in passing the stack itself s rather than a pointer to it ps. This
 *will not copy the elements as opposed to the array-based
 *implementation. However, of course, we do not do that to keep the
 *code at the user level unchanged (same interface "accessing mechanism").
 */
//The execution time does not depend on anything, therefore the
//complexity is: Big-Theta(1)
void CreateStack(Stack *ps) {
    ps->top = NULL; //(*ps).top = NULL;
    //NULL is defined in <stdlib.h>
    //Added Section
    ps->size = 0;
}
/*
 *Pre: The stack exists and is initialized.
 *Post: The argument item has been stored at the top of the stack
 */
// Complexity is: Big-Theta(1)
void Push(StackEntry e, Stack *ps) {
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    //malloc returns a void pointer
    //We typecast it with a StackNode*
    //Fragmanted memory allocation
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    //Added section
    ps->size++;
}
/*Pre: The stack exists and it is not empty.
 *Post: The item at the top of the stack has been removed and returned
 *in *pe.
 */
//Complexity is: Big-Theta(1)
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->top->entry; //This would be the only code for StackTop.
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    //Added section
    ps->size--;
}
/*Pre: The stack exists
 *Post: returns the status, 1 or 0
 */
//Complexity is: Big-Theta(1)
int StackEmpty(Stack *ps) {
    return !ps->top; //ps->top == NULL;
    //Added section
    //return !ps->size;
}
//For backward compitablity of different versions (same interface)
//Preserving all accessing mechanisms
//Complexity is: Big-Theta(1)
int StackFull(Stack *ps) {
    return 0;
}
/*Pre: The stack exists
 *Post: All the elements freed
 */
//Complexity is: Big-Theta(n)
//Total time = N * time of one loop
void ClearStack(Stack *ps) {
    StackNode *pn = ps->top;
    while (pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    //Added section
    ps->size = 0;
/*My Solution
    StackNode *pn;
    while(ps->top) {
        pn = ps->top;
        ps->top = ps->top->next;
        free(pn);
    }
    ps->size = 0;
 *Or
    for(pn = ps->top; pn; pn = pn->next) {
        ps->top = pn->next; //ps->top->next;
        free(pn);
    }
    ps->size = 0;
*/
/*
 *The wrong code is:
 *ps->top = NULL;
*/
/*
 *StackNode *pn = ps->top
 *StackNode *qn = ps->top
 *while (pn) { //while (pn != NULL)
 *    pn = pn->next;
 *    free(qn);
 *    qn = pn;
 *}
 *ps->top = NULL;
*/
}
/*Pre: The stack exists
 *Post: Function is passed to process every element
 */
//Complexity is: Big-Theta(n)
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for(StackNode *pn = ps->top; pn; pn = pn->next)
        (*pf)(pn->entry);
/*
    StackNode *pn = ps->top;
    while (pn) {
        (*pf)(pn->entry);
        pn = pn->next;
    }
*/
}
/*Pre: The stack exists
 *Post: Returns the number of elements
 */
int StackSize(Stack *ps) {
/*
 *This function is Big-Theta(n), i.e., the execution time is proportional
 *to the size! Because, we have to traverse the stack node-by-node to
 *count (this statement is not precise).
 *Can we modify the structure to decrease the complexity of this
 *algorithm?
 *We add extra field, called, size in struct stack. Then, we need to add
 *just one statement to: CreateStack, Pop, Push, ClearStack.
 *What happened is that, we added extra field in the data structure,
 *which is size (2 bytes). But, this saves us time by reducing the
 *complexity of the algorithm of the function StackSize. From Big-Theta(n)
 *to Big-Theta(1).
 *This is a typical trade-off between time and space
*/
    return ps->size;
/*
    StackNode *pn = ps->top;
    for (int x = 0; pn; pn = pn->next)
        x++;
    return x;
*/
/*
    for (int x = 0, StackNode *pn = ps->top; pn; pn = pn->next)
        x++;
    return x;
*/
}

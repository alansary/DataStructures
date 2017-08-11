#include <stdio.h>

/*
 *Arrays are sequences of homogeneous data types that are contiguously
 *allocated within the memory. Arrays are of fixed size.
 *The name of the array is a pointer to the first element.
 */
typedef int StackEntry;
#define MAXSTACK 100
typedef struct stack {
    int top; //is the index of the first available place.
    StackEntry entry[MAXSTACK];
}Stack;
void CreateStack(Stack *);
void Push(StackEntry, Stack *);
int StackFull(Stack *);
void Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);
void Display(StackEntry e) {
    printf("e is: %d\n", e);
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry));
/*
Why interface, Pre, Post are crucial:
Pop takes a pointer to the element and pointer to the stack.
Pre: The stack is initialized and not empty
Post: The last element entered is returned
Push takes the element itself and a pointer to the stack
Pre: The stack is initialized and not full
Post: The element e has been stored at the top of the stack; and e does
not change
*/
//This is slower than implementing it in the implementation level
/*
void StackTop(StackEntry *pe, Stack *ps) {
    Pop(pe, ps);
    Push(*pe, ps);
}
*/
/*StackEntry and MAXSTACK should be defined in the User Level, because
 *they concern the user.
 *
 *Also, they have to be defined in the implementation level, because
 *they are refrenced in Stack.c
 *
 *Therefore, they have to be defined in Stack.h which included in both
 *Stack.c and the user main file.
 *
 *So, the main file will compile even if Stack.c is not compiled yet.
 */
void main()
{
    StackEntry e;
    Stack s; //Creation of the stack
    int x;
    CreateStack(&s); //Initializing the stack
    if (!StackFull(&s))
        Push(e, &s);
    if (!StackEmpty(&s))
        Pop(&e, &s);
    StackTop(&e, &s);
    x = StackSize(&s);
    ClearStack(&s);
    TraverseStack(&s, &Display); //&s only for efficiency as said before.
    /*
        The user knows the type of the element e but not the implementor
        and the implementor knows how to traverse the elements but does
        not know their type or what to do with them.
        Solution that preserve data encapsulation:
            The user parses just one element with a function and pass
            it to the implementor to make this function traverse through
            the elements.
    */
    /*
    Exercise: How to write the function StackTop in the user level?
    (e,g., if you do not have the source code of the implementation)
    */
    //Pop(&e, &s);
    //Push(e, &s);
}
//The execution time does not depend on n; therefore the complexity is:
//Big-Theta(1)
void CreateStack(Stack *ps) {
    ps->top = 0; //*ps.top = 0;
}
/*Pre: The stack is initialized and not full
  Post: The element e has been stored at the top of the stack; and e
does not change*/
//To save more space we can implement it using &e (passing e by
//reference) and not passing e by value each time
void Push(StackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}
/* The user has to check before calling Push other ways (no percondition)
   are:
if (ps->top==MAXSTACK)
    printf("Stack is full");
else ps->entry[ps-top++] = e;
//but this is not professional
*/
/*
int push(...) {
    if (ps->top == MAXSTACK)
        return 0;
    else {
        ps-entry[ps-top++] = e;
        return 1;
    }
}
//This is fine
//Calling will be
//if(!Push(e, &s))
//  ...
*/
int StackFull(Stack *ps) { //It could be: StackFull(s) but this wastes
//memory and time of copying
    return ps->top == MAXSTACK;
/*
if (ps->top == MAXSTACK)
    return 1;
else
    return 0;
*/
//return ps-top == MAXSTACK ? 1 : 0;
}
/*Pre: The stack is initialized and not empty
  Post: The last element entered is returned*/
//The user has to check before calling Pop
void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
/*
ps->top--;
*pe = ps->entry[ps->top];
*/
/*Other ways (no precondition) are:
if (ps->top == 0)
    printf("Stack is Empty");
else *pe = ps->entry[--ps->top];
//but this is not professional
*/
/*
int Pop(...) {
    if (ps->top == 0)
        return 0;
    else {
        *pe = ps->entry[--ps->top];
        return 1;
    }
}
*/
//This is fine
/*Calling will be
if (!Pop(&e, &s))
    ...
*/
}
//It could be: StackEmpty(s) but this wastes memory and time of copying.
int StackEmpty(Stack *ps) {
    return !ps->top;
/*
if (ps->top == 0)
    return 1;
else
    return 0;
*/
// return ps->top == 0;
}
//Same preconditions of Pop.
//It could be: StackTop(&e, s) but this wastes memory and time of copying.
void StackTop(StackEntry *pe, Stack *ps) {
    *pe = ps->entry[ps->top-1];
}
/*Pre: Stack is initialized.
  Post: returns how many elements exist.*/
//It could be: StackSize(s) but this wastes memory and time of copying.
int StackSize(Stack *ps) {
    return ps->top;
}
/*Pre: Stack is initialized.
  Post: destroy all elements; stack looks initialized.*/
/*Same code as CreateStack; why new function then?
1- conceptually (for the user they are not the same)
2- to have a persistent interface (linked-list implementation)
*/
void ClearStack(Stack *ps) {
    ps->top = 0;
}
//Preconditions: The stack is initialized
//It could be: TraverseStack(s, &function) but this wastes memory
//and time of copying
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    for(int i = ps->top; i > 0; i--)
        (*pf)(ps->entry[i-1]);
//(*pf) is the function
}

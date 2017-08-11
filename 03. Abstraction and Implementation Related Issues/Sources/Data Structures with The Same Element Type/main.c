#include <stdio.h>
#include "Global.h"
#include "Stack.h"
#include "Queue.h"
void Display(ElementType);
void main(void) {
    Stack s;
    Queue q;
    CreateStack(&s);
    CreateQueue(&q);
    StackEntry es;
    QueueEntry eq;
    es.fName = "Mohamed";
    es.lName = "Alansary";
    es.id = 1;
    if (!StackFull(&s))
        Push(es, &s);
    es.fName = "Nour";
    es.lName = "Eldien";
    es.id = 2;
    if (!StackFull(&s))
        Push(es, &s);
    eq.fName = "Mahmoud";
    eq.lName = "Taha";
    eq.id = 3;
    if (!QueueFull(&q))
        Append(eq, &q);
    eq.fName = "Mohamed";
    eq.lName = "Salah";
    eq.id = 4;
    if (!QueueFull(&q))
	Append(eq, &q);
    TraverseStack(&s, &Display);
    puts("******************************************");
    TraverseQueue(&q, &Display);
    puts("******************************************");
}
void Display(ElementType e) {
    printf("%20s %10s\n%20s %10s\n%20s %d\n\n",
           "First Name:", e.fName, "Last Name:", e.lName, "Id:", e.id);
}

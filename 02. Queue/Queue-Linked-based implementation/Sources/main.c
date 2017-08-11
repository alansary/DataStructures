#include <stdio.h>
#include "Queue.h"

void Display(QueueEntry);

void main(void) {
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    printf("Enter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        if(!Append(e, &q))
	    printf("%s", "Error appending the element\n");
	else
            printf("%d is appended\n", e);
    }
    printf("Enter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        if(!Append(e, &q))
	    printf("%s", "Error appending the element\n");
	else
            printf("%d is appended\n", e);
    }
    printf("Elements of the queue are:\n");
    TraverseQueue(&q, &Display);
    if(!QueueEmpty(&q)){
        Serve(&e, &q);
        printf("\n%d is served from the queue", e);
    }
    printf("\nNow the elements of the queue are:\n");
    TraverseQueue(&q, &Display);
        printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
	if(!Append(e, &q))
	    printf("%s", "Error appending the element\n");
	else
            printf("%d is appended\n", e);
    }
        printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        if(!Append(e, &q))
	    printf("%s", "Error appending the element\n");
	else
            printf("\n%d is appended\n", e);
    }
        printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        if(!Append(e, &q))
	    printf("%s", "Error appending the element\n");
	else
            printf("\n%d is appended\n", e);
    }
    printf("\nElements of the queue are:\n");
    TraverseQueue(&q, &Display);
    int size;
    size = QueueSize(&q);
    printf("\nThe size of the queue is %d\n", size);
    QueueFront(&e, &q);
    printf("\nThe first element in the queue is %d\n", e);
    ClearQueue(&q);
    size = QueueSize(&q);
    printf("\nCleared...\nNow the size of the queue is %d\n", size);
}
void Display(QueueEntry e) {
    printf("%d  ", e);
}


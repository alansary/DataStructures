#include <stdio.h>
#include <stdlib.h>
/*
Error Handling Tip:
Very important note for all linked structures. E.g., in Queues:
In Push and Append We have to check for exhausted memory.
The code can be modified to:
int Append(QueueEntry e, Queue *pq) {
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if (!pn)
	return 0; // Unsuccessful allocation
	// This is much better than the Error message of
        // the book because this is more flexible. Also,
	// the same function for contiguous implementation
	// has to return 1 always to have consistent
	// interface
    else { // Successful allocation
	//Put here exactly all of the remaining code
	return 1;
    }
}
// calling: if (!Append(e, &q)) { Do Whatever! }
*/
/*
You should never print error message or any other message from
a function, give the user the accessing mechanism and let him
handle it.
*/
typedef int QueueEntry;
typedef struct queuenode {
    struct queuenode *next;
    QueueEntry entry;
}QueueNode;
typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;
void CreateQueue(Queue *);
void Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
void QueueFront(QueueEntry *, Queue *);
int QueueSize(Queue *);
int QueueFull(Queue *);
int QueueEmpty(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void(*)(QueueEntry));
void main(void) {

}
void CreateQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void Append(QueueEntry e, Queue *pq) {
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    if (!pq->rear) // The first node
	pq->front = pn;
    else
	pq->rear->next = pn; // runtime error for empty queue
    pq->rear = pn;
    pq->size++;
}
void Serve(QueueEntry *pe, Queue *pq) {
    QueueNode *pn = pq->front;
    *pe = pn->entry;
    pq->front = pq->front->next;
    free(pn);
    // Only one node
    if (!pq->front)
	pq->rear = NULL;
    pq->size--;
}
int QueueFull(Queue *pq) {
    return 0;
}
int QueueEmpty(Queue *pq) {
    return !pq->rear;
}
int QueueSize(Queue *pq) {
    return pq->size;
}
void QueueFront(QueueEntry *pe, Queue *pq) {
    *pe = pq->front->entry;
}
void ClearQueue(Queue *pq) {
   while (pq->front) {
	pq->rear = pq->front->next;
	free(pq->front);
	pq->front = pq->rear;
   }
   pq->size = 0;
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)) {
    for (QueueNode *pn = pq->front; pn; pn = pn->next)
	(*pf)(pn->entry);
}

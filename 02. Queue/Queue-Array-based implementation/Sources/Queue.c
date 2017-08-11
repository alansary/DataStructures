/********************************************
* Purpose: Queue Array-based Implementation *
* Author : Mohamed Alansary                 *
* Date   : 27 November 2016                 *
********************************************/
#include "Queue.h"
void CreateQueue(Queue *pq) {
    pq->size = 0;
    pq->rear = -1;
    pq->front = 0;
}
void Append(QueueEntry e, Queue *pq) {
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Serve(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
int QueueEmpty(Queue *pq) {
    return !pq->size;
}
int QueueFull(Queue *pq) {
    return (pq->size == MAXQUEUE);
}
int QueueSize(Queue *pq) {
    return pq->size;
}
void ClearQueue(Queue *pq) {
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)) {
    int pos, s;
    for (pos=pq->front, s = 0; s < pq->size; s++) {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
void QueueFront(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
}
 

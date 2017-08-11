#include "Queue.h"
#ifdef LIMITED_MEMORY_
void CreateQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
int Append(QueueEntry e, Queue *pq) {
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if (pn) {
	pn->entry = e;
	pn->next = NULL;
	if (!pq->size)
	    pq->front = pn;
	else
	    pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
	return 1;
    }
    else return 0;
}
void Serve(QueueEntry *pe, Queue *pq) {
    *pe = pq->front->entry;
    QueueNode *pn = pq->front;
    pq->front = pq->front->next;
    free(pn);
    if (!pq->front)
	pq->rear = NULL;
    pq->size--;
}
int QueueFull(Queue *pq) {
    return 0;
}
int QueueEmpty(Queue *pq) {
    return !pq->size;
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
#else
void CreateQueue(Queue *pq) {
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}
int Append(QueueEntry e, Queue *pq) {
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
    return 1;
}
void Serve(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
int QueueFull(Queue *pq) {
    return pq->size == MAXQUEUE;
}
int QueueEmpty(Queue *pq) {
    return !pq->size;
}
int QueueSize(Queue *pq) {
    return pq->size;
}
void ClearQueue(Queue *pq) {
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}
void QueueFront(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)) {
    int pos, s;
    for (pos=pq->front, s = 0; s < pq->size; s++) {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
#endif //LIMITED_MEMORY_

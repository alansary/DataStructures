#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef int QueueEntry;
//#define LIMITED_MEMORY_
#ifdef LIMITED_MEMORY_
#include <stdlib.h>
typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;
typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;
#else
#define MAXQUEUE 100
typedef struct queue {
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;
#endif //LIMITED_MEMORY_
void CreateQueue(Queue *);
int Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
int QueueFull(Queue *);
int QueueEmpty(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void QueueFront(QueueEntry *, Queue *);
void TraverseQueue(Queue *, void(*)(QueueEntry));
#endif //QUEUE_H_INCLUDED

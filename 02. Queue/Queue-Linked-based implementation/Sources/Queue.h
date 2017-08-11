#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
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
int Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
void QueueFront(QueueEntry *, Queue *);
int QueueSize(Queue *);
int QueueFull(Queue *);
int QueueEmpty(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void(*)(QueueEntry));
#endif //QUEUE_H_INCLUDED

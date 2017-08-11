#include <stdio.h>
typedef int QueueEntry;
#define MAXQUEUE 100
typedef struct queue {
    int size;
    int front;
    int rear;
    QueueEntry entry[MAXQUEUE];
}Queue;
/*Pre:
  Post: The queue is initialized
*/
void CreateQueue(Queue *);
/*Pre: The queue is initialized and not full
  Post: The element is appended onto the top of the queue
*/
void Append(QueueEntry, Queue *);
/*Pre: The queue is initialized and not empty
  Post: The top element of the queue is returned into QueueEntry and then
        served of the queue
*/
void Serve(QueueEntry *, Queue *);
/*Pre: The queue is initialized
  Post: Returns whether the queue is empty or not
*/
int QueueEmpty(Queue *);
/*Pre: The queue is initialized
  Post: Returns whether the queue is full or not
*/
int QueueFull(Queue *);
/*Pre: The queue is initialized
  Post: Returns the number of elements in the queue
*/
int QueueSize(Queue *);
/*Pre: The queue is initialized
  Post: The queue is cleared and looks initialized
*/
void ClearQueue(Queue *);
/*Pre: The queue is initialized
  Post: The passed function traverses each element of the queue
*/
void TraverseQueue(Queue *, void(*)(QueueEntry));
/*Pre: The queue is initialized and not empty
  Post: The top element of the queue is returned into the QueueEntry
*/
void QueueFront(QueueEntry *, Queue *);

void Display(QueueEntry);

void main(void) {
/*
    Queue q;
    CreateQueue(&q);
    QueueEntry e;
    scanf("%d", &e);
    if (!QueueFull(&q))
        Append(e, &q);
    if (!QueueEmpty(&q))
        Serve(&e, &q);
    int size = QueueSize(&q);
    ClearQueue(&q);
    TraverseQueue(&q, &Display);
    QueueFront(&e, &q);
*/
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    char c;
    printf("Enter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        Append(e, &q);
        printf("%d is appended\n", e);
    }
    printf("Enter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        Append(e, &q);
        printf("%d is appended\n", e);
    }
    printf("Elements of the queue are:\n");
    TraverseQueue(&q, &Display);
    scanf("%c", &c);
    if(!QueueEmpty(&q)){
        Serve(&e, &q);
        printf("\n%d is served from the queue", e);
    }
    printf("\nNow the elements of the queue are:\n");
    TraverseQueue(&q, &Display);
    printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
       Append(e, &q);
       printf("%d is appended\n", e);
    }
        printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        Append(e, &q);
        printf("\n%d is appended\n", e);
    }
    printf("\nEnter a number to be appended:\n");
    scanf("%d", &e);
    if(!QueueFull(&q)){
        Append(e, &q);
        printf("\n%d is appended\n", e);
    }
    printf("\nElements of the queue are:\n");
    TraverseQueue(&q, &Display);
    scanf("%c", &c);
    int size;
    size = QueueSize(&q);
    printf("\nThe size of the queue is %d\n", size);
    QueueFront(&e, &q);
    printf("\nThe first element in the queue is %d\n", e);
    ClearQueue(&q);
    size = QueueSize(&q);
    printf("\nCleared...\nNow the size of the queue is %d\n", size);
    scanf("%c", &c);
    printf("The elements of the queue are:\n");
    TraverseQueue(&q, &Display);
    scanf("%c", &c);
}
/*
  Initializing front = 5 and rear = 4 will wok if MAXQUEUE >= 6. But since,
  MAXQUEUE can be 1 we initialize as above.
*/
void CreateQueue(Queue *pq) {
    pq->size = 0;
    pq->rear = -1;
    pq->front = 0;
}
void Append(QueueEntry e, Queue *pq) {
    /*
    if (pq->rear == MAXQUEUE - 1)
        pq->rear = 0;
    else
        pq->rear++;
    */
    // if pq->rear == MAXQUEUE - 1, then pq->rear + 1 == MAXQUEUE,
    // MAXQUEUE % MAXQUEUE == 0
    // if pq->rear < MAXQUEUE - 1, then pq->rear + 1 < MAXQUEUE,
    // ((pq->rear + 1) < MAXQUEUE) % MAXQUEUE == pq->rear + 1
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Serve(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
    /*
    if (pq->front == MAXQUEUE - 1)
        pq->front = 0;
    else
        pq->front++;
    */
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
// Same as CreateQueue, no nodes to free.
void ClearQueue(Queue *pq) {
    pq->size = 0;
    pq->front = 0;
    pq->rear = -1;
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)) {
    /*
    //The following code loops forever if the queue is empty
    int x;
    for (x = pq->front; x != pq->rear; x = (x+1) % MAXQUEUE)
        (*pf)(pq->entry[x]);
    (*pf)(pq->entry[x]);
    */
    int pos, s;
    for (pos=pq->front, s = 0; s < pq->size; s++) {
	(*pf)(pq->entry[pos]);
	pos = (pos + 1) % MAXQUEUE;
    }
}
void QueueFront(QueueEntry *pe, Queue *pq) {
    *pe = pq->entry[pq->front];
}

void Display(QueueEntry e) {
    printf("%d  ", e);
}

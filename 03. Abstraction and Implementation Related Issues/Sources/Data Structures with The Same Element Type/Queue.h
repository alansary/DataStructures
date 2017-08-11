/********************************************
* Purpose: Queue Array-based Implementation *
* Author : Mohamed Alansary		    *
* Date   : 27 November 2016		    *
********************************************/
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Global.h"

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


#endif //QUEUE_H_INCLUDED

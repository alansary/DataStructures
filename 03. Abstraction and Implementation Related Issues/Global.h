			/******Global.h******/

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

typedef struct elementtype{
    int year;
    float age;
    int tmp;
}ElementType;

#define MAXELEMENTS 100

typedef ElementType QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef ElementType StackEntry;
#define MAXSTACK MAXELEMENTS

#endif //GLOBAL_H_INCLUDED

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

typedef struct elementtype {
    char *fName;
    char *lName;
    long long int id;
}ElementType;
#define MAXELEMENTS 1000

typedef ElementType QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef ElementType StackEntry;
#define MAXSTACK MAXELEMENTS

#endif //GLOBAL_H_INCLUDED

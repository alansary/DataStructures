#include <stdio.h>
/*
The last statement in TowersOfHanoiWithTailRecursion is a recursive call
to it self MoveDisks(count-1, temp, finish, start);
therefore, it can be removed and replaced with an iterative version.
Removing Tail Recursion
*/
void MoveDisks(int, int, int, int);
void main(void) {
    MoveDisks(7, 1, 3, 2);
}
void MoveDisks(int count, int start, int finish, int temp) {
    int swap;
    while (count > 0) { // instead of if condition
        MoveDisks(count-1, start, temp, finish);
	printf("Move disk %d from %d to %d\n", count, start, finish);
	count--;
	swap = start;
	start = temp;
	temp = swap;
    }
}

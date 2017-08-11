/* Towers of Hanoi, a game of 19th century
Write a computer function that writes down steps needed to move the disks
from tower 1 to tower 3 using tower 2 with the restrictions that:
    1- Only one disk should be removed at a time.
    2- No disk should be placed on top of a smaller disk.
*/
/*
 * Solution:
 * 1- To move the largest disk from 1 to 3, we have to move first all
      others from 1 to 2 !!!
 * 2- Move the largest from 1 to 3.
 * 3- Move all others from 2 to 3.
 * This is the idea of recursion; define a base step then do the same thing
 * again.
 * This is the same concept of divide and conquer. To solve a problem, we
 * split it into smaller and smaller parts.
 * Every recursive process consists of two parts:
 *     1- A smallest, base case that is processed without recursion.
 *     2- A general method that reduces a particular case to one or more of
 *        the smaller cases, thereby making progress toward eventually
 *        reducing the problem all the way to the base case.
 */
/* Convince yourself that MoveDisks really writes down the steps of moving
   count from start to finish using temp.
*/
/*
 * Every call to MoveDisks creates a new set of formal parameters with
 * pushing the upper level to the stack.
*/
#include <stdio.h>
void MoveDisks(int, int, int , int);
void main(void) {
    MoveDisks(7, 1, 3, 2);
    //move 7 disks from disk 1 to disk 3 using disk 2
}
void MoveDisks(int count, int start, int finish, int temp){
/*
Pre:
    - There are at least count disks on the tower start.
    - The top disk on each of towers temp and finish is larger than any
      of the top count disks on tower start.

Post:
    - The top count disks on start have been moved to finish;
    - temp (used for temporary storage) has been returned to its starting
      position.
*/
    if (count > 0) {
        MoveDisks(count-1, start, temp, finish);
        printf("Move Disk %d from %d to %d\n", count, start, finish);
        //This step of printf is the base condition.
        MoveDisks(count-1, temp, finish, start);
    }
}
/*
  - Space Complexity depends upon the depth of the recursion.
  - Time Complexity depends upon the number of function calls.
  - Tracing 3 disks with a parsing tree, we found that number of function
    calls is 1 + 2 + 4 + 8
    The number of steps to solve the problem is
    1 + 2 + 4 = 2^0 + 2^1 + ... + 2 ^ (count-1)
    which is a geometric series = (2 ^ count) - 1
  - If count = 64, there will be no stack overflow problem. But the number
    of steps to solve the problem will be approximately 1.6E19 step.
  - Assuming the computer will compute each call in 10E-10, it will take
    (10E-12 * 1.6E19) / (60 * 60 * 24 * 365) = 5.073566717402334 years to
    execute.
*/
/*
  Can we write the function Move iteratively?
  We will find that we really need to build a stack. We will find that the
  nature of the problem necessitates that we first solve the problem at
  size count-1 then return back to the original problem. To return back
  we had to save it in a stack!
  In such cases defining the problem recursively is much better, since
  you let the OS build the stack itself which is much more efficient than
  your stack.
  However, there are some cases in which solving the problem iteratively is
  better if the iterative algorithm does not need a stack. Hence, solving
  it recursively builds an unnecessarily stack, which waster memory and
  time consumed in function return.
*/

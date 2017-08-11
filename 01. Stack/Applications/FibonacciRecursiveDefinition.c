/*
  F(n) = 0 if n = 0 (base condition)
  F(n) = 1 if n = 1 (base condition)
  F(n - 1) + F(n - 2) if n >= 2
*/
/*
  Recursion Tree helps determining whether the recursion is necessary or
  not.
  The complexity is O(c ^ n) (Exponential Growth)
  1- The common problems with unnecessarily stack building are:
     - waste of time
     - waste of memory
  2- For this particular function we have another serious problem, which is
     needlessly repeating the Fibonacci of many numbers.
*/
#include <stdio.h>
long int F(int);
void main(void) {
    for (int x = 0; x < 10; x++)
        printf("F(%d) = %ld\n", x, F(x));
}
long int F(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
	return 1;
    else
	return (F(n - 1) + F(n - 2));
}

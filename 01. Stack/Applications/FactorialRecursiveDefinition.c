/* n! = 1 if n = 0 (base condition)
   n! = n * (n - 1)! if n > 0
*/
/*
  - What is the nedd of this built stack?
    Why do we exhaust the memory with all these formal parameter?
  - Also. Why do we waste the time of function calls and returns. In this
    case, absolutely the iterative version is faster and more economic in
    memory utilization.
  - The recursion tree is simply a chain, which means that designing the
    algorithm does not need recursion.
*/
#include <stdio.h>
long int factorial(int);
void main(void) {
    for (int x = 0; x < 10; x++)
        printf("%d! = %ld\n", x, factorial(x));
}
long int factorial(int n) {
    return (n == 0) ? 1 : (n * factorial(n - 1));
}

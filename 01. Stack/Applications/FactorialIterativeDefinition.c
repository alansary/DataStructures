// n! = n * (n-1) * ... * 1
#include <stdio.h>
long int factorial(int);
void main(void) {
    for (int x = 0; x < 10; x++)
        printf("%d! = %ld\n", x, factorial(x));
}
/* Iterative Algorithm */
long int factorial(int n) {
    long int fact = 1;
    for (; n >= 1; n--)
        fact *= n;
    return fact;
}

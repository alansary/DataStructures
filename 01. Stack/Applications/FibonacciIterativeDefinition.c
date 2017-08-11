/*
Although the mathematical form of the function itself is recursive
(this what tempts some people to code it recursively), however we can find
iterative algorithm for solving it.
0	1	2	3...
twoback oneback current
        twoback oneback current
The complexity is O(n) (Linear Growth)
*/
#include <stdio.h>
long int F(int);
void main(void) {
    for (int x = 0; x < 10; x++)
	printf("F(%d) = %ld\n", x, F(x));
}
long int F(int n) {
    int twoback; // second previous number, F_i-2
    int oneback; // previous number, F_i-1
    int current; // current number, F_i
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else { // n >= 2
        /*
	twoback = 0;
	oneback = 1;
	int counter = 1;
        while(counter != n) {
	    current = twoback + oneback;
	    twoback = oneback;
	    oneback = current;
	    counter++;
        }
	return oneback;
        */
	twoback = 0; //fibonacci 0
	oneback = 1; //fibonacci 1
        for (int counter = 2; counter <= n; counter++) {
	    current = twoback + oneback; //fibonacci from 2 to n
	    twoback = oneback;
	    oneback = current;
	}
	return current;
    }
}

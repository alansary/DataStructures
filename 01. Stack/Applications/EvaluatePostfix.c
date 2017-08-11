#include <stdio.h>
#include "StackEvaluatePostfix.h"
double pow(double, double);
int IsDigit(char);
double Oper(char, double, double);
double EvaluatePostfix(char*);
void main(void) {
    char expr[100];
    // "354*+2$"
    scanf("%s", &expr);
    double val = EvaluatePostfix(expr);
    printf("\n%f\n\n", val);
}
int IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
double Oper(char c, double op1, double op2) {
    switch(c) {
	case '+': return(op1+op2);
	case '-': return(op1-op2);
	case '*': return(op1*op2);
	case '/': return(op1/op2);
	case '$': return(pow(op1, op2));
    }
}
double pow(double a, double b) {
    double val = 1.0;
    for (double x = 1; x <= b; x++)
	val *= a;
    return val;
}
double EvaluatePostfix(char expr[]) {
    char c;
    double op1, op2, val;
    Stack s;
    CreateStack(&s);
    for (int i = 0; (c=expr[i])!='\0'; i++) {
	if (IsDigit(c)) {
	    if (!StackFull(&s))
	        Push((double)(c-'0'), &s);
        }
	else {
	    Pop(&op2, &s);
	    Pop(&op1, &s);
	    val = Oper(c, op1, op2);
	    Push(val, &s);
	}
    }
    Pop(&val, &s);
    return val;
}
/*
  Obvious Limitations:
  1. only single digit integers.
  2. only positive integers.
  3. no unary operators allowed.
  4. no brackets !!!
  5. no handling for invalid expr.
     - extra operators.
     - invalid ordering.
       ...
*/

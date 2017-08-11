#include <stdio.h>
#include "Stack.h"
#define CHARACTER 0
#define DOUBLE 1
double pow(double, double);
int IsDigit(char);
double Oper(char, double, double);
double EvaluatePostfix(char*);
void InfixToPostfix(char*, char*);
int Precedent(char, char);
void Display(StackEntry);
void main(void) {
    // Evaluate Postfix (same Stack.h and different types)
    char expr[100];
    // "354*+2$"
    scanf("%s", &expr);
    double val = EvaluatePostfix(expr);
    printf("\n%f\n\n", val);

    // Infix To Postfix (same Stack.h and different types)
    char infix[100];
    // "1+2+3$4/5+6"
    scanf("%s", &infix);
    char postfix[100];
    InfixToPostfix(infix, postfix);
    printf("\n%s\n\n", postfix);

    // Stack with different data types
    Stack s;
    CreateStack(&s);
    StackEntry e;
    e.infixToPostfix = 'a';
    e.etype = CHARACTER;
    Push(e, &s);
    e.evaluatePostfix = 1.0;
    e.etype = DOUBLE;
    Push(e, &s);
    TraverseStack(&s, &Display); 
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
    for (int x = 1; x <= b; x++)
        val *= a;
    return val;
}
double EvaluatePostfix(char expr[]) {
    char c;
    double val;
    StackEntry op1, op2;
    Stack s;
    CreateStack(&s);
    StackEntry e;
    for (int i = 0; (c=expr[i])!='\0'; i++) {
        if (IsDigit(c)) {
            if (!StackFull(&s)) {
		e.evaluatePostfix = (double)(c-'0');
		e.etype = DOUBLE;
                Push(e, &s);
	    }
        }
        else {
            Pop(&op2, &s);
            Pop(&op1, &s);
            val = Oper(c, op1.evaluatePostfix, op2.evaluatePostfix);
            e.evaluatePostfix = val;
	    e.etype = DOUBLE;
            Push(e, &s);
        }
    }
    Pop(&e, &s);
    return e.evaluatePostfix;
}
void InfixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char c;
    StackEntry op;
    Stack s;
    CreateStack(&s);
    StackEntry e;
    for (i=0, j=0; (c=infix[i])!='\0'; i++) {
        if(IsDigit(c)) // Limitation: Operand is a single digit
            postfix[j++] = c;
        else {
            if(!StackEmpty(&s)) {
                StackTop(&op, &s);
                while(!StackEmpty(&s) && Precedent(op.infixToPostfix, c)) {
                    Pop(&op, &s);
                    postfix[j++] = op.infixToPostfix;
                    if(!StackEmpty(&s)) StackTop(&op, &s);
                }
            }
	    e.infixToPostfix = c;
	    e.etype = CHARACTER;
            Push(e, &s);
        }
    }
    while(!StackEmpty(&s)) {
        Pop(&op, &s);
        postfix[j++] = op.infixToPostfix;
    }
    postfix[j] = '\0';
}
int Precedent(char op1, char op2) {
    if (op1 == '$') return 1;
    if((op1 == '*') || (op1 == '/'))
        return (op2 != '$');
    if((op1 == '+') || (op1 == '-'))
        return ((op2 != '$') && (op2 != '*') && (op2 != '/'));
    return 0;
}
int IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
void Display(StackEntry e) {
    switch(e.etype) {
	case CHARACTER:
	    printf("\'%c\' is a character element within the stack\n",
		   e.infixToPostfix);
	    break;
	case DOUBLE:
	    printf("%lf is a double element within the stack\n",
		   e.evaluatePostfix);
	    break;
	default:
	    printf("Unknown type\n");
    }
}

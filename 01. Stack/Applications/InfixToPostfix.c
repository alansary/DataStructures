/*
  Polish Notation: Application on stacks
  Example:			Example
  Prefix : +ab			Prefix : +axbc
  Infix  : a+b			Infix  : a+bxc
  Postfix: ab+			Postfix: abcx+
  - We read and write in Infix, however we compute in Postfix!!!
  Example:
  A^B*C-D+E/F/(G+H) == AB^C*D-EF/GH+/+
  How do we really do it?
  A + B * C ^ D / E - F
  A
  A			+ // We wait for + second operand of + to appear
  AB			+
  // As long as there exist an operator that has higher precedence than +,
  // we will evaluate it first, then evaluate + when we encounter an
  // operator that has the same precedence or lower than +
  AB			+* // We wait for second operand of * to appear
			   // This is a stack
  ABC			+*
  ABC			+*^ // we wait for second operand of ^ to appear
  ABCD			+*^
  // Division has precedence less that power, ^ must be evaluated first
  ABCD^			+*	/
  // * has the same precedence as /
  ABCD^*		+	/
  ABCD^*		+/ // we wait for second operand of / to appear
  ABCD^*E		+/
  ABCD^*E		+/	-
  ABCD^*E/		+	-
  ABCD^*E/+		-
  ABCD^*E/+F		-
  ABCD^*E/+F-
*/
#include <stdio.h>
#include "StackInfixToPostfix.h"
void InfixToPostfix(char*, char*);
int IsDigit(char);
int Precedent(char, char);
void main(void) {
    // "1+2+3$4/5+6"
    char infix[100];
    printf("%s", "Infix: ");
    scanf("%s", &infix);
    char postfix[100];
    InfixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
}
void InfixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char op, c;
    Stack s;
    CreateStack(&s);
    for (i=0, j=0; (c=infix[i])!='\0'; i++) {
	if(IsDigit(c)) // Limitation: Operand is a single digit
	    postfix[j++] = c;
	else {
	    if(!StackEmpty(&s)) {
		StackTop(&op, &s);
		while(!StackEmpty(&s) && Precedent(op, c)) {
		    Pop(&op, &s);
		    postfix[j++] = op;
		    if(!StackEmpty(&s)) StackTop(&op, &s);
		}
	    }
	    Push(c, &s);
	}
    }
    while(!StackEmpty(&s)) {
	Pop(&op, &s);
	postfix[j++] = op;
    }
    postfix[j] = '\0';
}
int IsDigit(char c) {
    return (c>='0' && c<='9');
}
int Precedent(char op1, char op2) {
    if (op1 == '$') return 1;
    if((op1 == '*') || (op1 == '/'))
	return (op2 != '$');
    if((op1 == '+') || (op1 == '-'))
	return ((op2 != '$') && (op2 != '*') && (op2 != '/'));
    return 0;
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
  6. No characters allowed.
*/

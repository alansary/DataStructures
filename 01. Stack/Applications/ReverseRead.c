//main.c
/*
#############################################################
#               Stack Array Based Implementation            #
#                   Author: Mohamed Alansary                #
#                Department Of Computer Science             #
#                       Tanta University                    #
#                   Created on: Apr 13, 2015                #
#############################################################
*/
#include <stdio.h>
#include "StackReverseRead.h"
void ReverseRead(void){
    Stack s;
    StackEntry e;
    CreateStack(&s);
    while(!StackFull(&s) && (e = getchar()) != '\n')
    	Push(e, &s);
    while(!StackEmpty(&s)){
    	Pop(&e, &s);
    	putchar(e);
    }
    putchar('\n');
}
int main(void){
    printf("Enter a line of text to reverse it\n");
    ReverseRead();
    return 0;
}

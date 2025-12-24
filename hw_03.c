#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c);
char pop();
int getPriority(char c);

int main(void) {
    char exp[100];
    int i; 
    
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    printf("Postfix: ");
    
    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        } 
        else if (exp[i] == '(') {
            push('(');
        } 
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); 
        } 
        else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }
    
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    
    return 0;
}

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    char val = stack[top];
    top--;
    return val;
}

int getPriority(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

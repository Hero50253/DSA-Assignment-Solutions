#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1)
        return '\0'; 
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char expr[]) {
    int i;
    char ch;

    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push(expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty()) {
                return 0;
            } else {
                pop();
            }
        }
    }

    return isEmpty();
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");

    return 0;
}

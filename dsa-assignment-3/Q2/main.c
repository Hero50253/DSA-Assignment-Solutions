#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX], reversed[MAX];
    int i, len;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;

    len = strlen(str);

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        reversed[i] = pop();
    }
    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}

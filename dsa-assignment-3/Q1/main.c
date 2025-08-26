#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

int isFull() {
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int value) {
    if (isFull()) {
        printf("Stack is FULL! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to remove element from stack
void pop() {
    if (isEmpty()) {
        printf("Stack is EMPTY! Cannot pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is EMPTY! No top element.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4: 
                if (isEmpty())
                    printf("Stack is EMPTY.\n");
                else
                    printf("Stack is NOT EMPTY.\n");
                break;
            case 5: 
                if (isFull())
                    printf("Stack is FULL.\n");
                else
                    printf("Stack is NOT FULL.\n");
                break;
            case 6: 
                display();
                break;
            case 7: 
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 7);

    return 0;
}

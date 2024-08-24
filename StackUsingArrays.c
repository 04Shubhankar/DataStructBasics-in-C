// Implementation of stack using Arrays in C.

#include <stdio.h>
#define max 100

// Global variable to keep track of the top element in the stack
int top = -1;

// Function prototypes
void push(int stack[]);
void pop(int stack[]);
void display(int stack[]);

int main() {
    int stack[max];
    int flag = 1;

    while (flag == 1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int stack[]) {
    if (top == max - 1) {
        printf("Stack overflow\n");
    } else {
        int value;
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop(int stack[]) {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}

void display(int stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

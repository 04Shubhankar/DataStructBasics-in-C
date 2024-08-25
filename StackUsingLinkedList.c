// Implimentation of stack using Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function prototypes
void push();
void pop();
void display();

// Global pointer to track the top of the stack
struct node *top = NULL;

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to push a value onto the stack
void push() {
    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter the value to push: ");
    scanf("%d", &new_node->data);
    new_node->next = top; // Link the new node to the current top
    top = new_node;       // Update top to the new node
}

// Function to pop a value from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct node *temp = top;
    top = top->next; // Move top to the next node
    printf("Popped value: %d\n", temp->data);
    free(temp); // Free the popped node
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

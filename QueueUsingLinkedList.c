//Implimentation of Queue Using Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function prototypes
void push();  // Enqueue
void pop();   // Dequeue
void display();

// Global pointers to track the front and rear of the queue
struct node *front = NULL;
struct node *rear = NULL;

int main() {
    int choice;
    while (1) {
        printf("\n1. Push (Enqueue)\n2. Pop (Dequeue)\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();  // Enqueue
                break;
            case 2:
                pop();   // Dequeue
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

// Function to add a value to the queue (enqueue)
void push() {
    struct node *new_node = malloc(sizeof(struct node));

    printf("Enter the value to push: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        front = rear = new_node;
    } else {
        // Otherwise, link the new node to the end of the queue and update the rear
        rear->next = new_node;
        rear = new_node;
    }
}

// Function to remove a value from the queue (dequeue)
void pop() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct node *temp = front;
    front = front->next;

    if (front == NULL) {
        // If the queue is now empty, set rear to NULL as well
        rear = NULL;
    }

    printf("Popped value: %d\n", temp->data);
    free(temp); // Free the dequeued node
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

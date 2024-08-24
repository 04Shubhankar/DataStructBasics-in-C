//Implementation of Queue using Arrays
#include <stdio.h>
#define max 100

// Global variables to keep track of front and rear pointers of the queue
int front = -1;
int rear = -1;

// Function prototypes
void push(int queue[]);
void pop(int queue[]);
void display(int queue[]);

int main() {
    int queue[max];
    int flag = 1;

    while (flag == 1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(queue);
                break;
            case 2:
                pop(queue);
                break;
            case 3:
                display(queue);
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

void push(int queue[]) {
    if (rear == max - 1) {
        printf("Queue overflow\n");
    } else {
        int value;
        printf("Enter the value to push: ");
        scanf("%d", &value);

        if (front == -1) { // If inserting the first element
            front = 0;
        }

        rear++;
        queue[rear] = value;
    }
}

void pop(int queue[]) {
    if (front == -1 || front > rear) { // Check if queue is empty
        printf("Queue underflow\n");
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front++;

        if (front > rear) { // Queue becomes empty
            front = rear = -1;
        }
    }
}

void display(int queue[]) {
    if (front == -1 || front > rear) { // Check if queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) { // Display from front to rear
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

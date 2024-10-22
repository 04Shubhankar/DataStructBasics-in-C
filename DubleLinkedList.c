#include <stdio.h>

#define MAX 100

// Define a structure to represent a doubly linked list node
struct Node {
    int data;
    int prev; // Index of the previous node in the array
    int next; // Index of the next node in the array
};

struct Node list[MAX];
int head = -1;   // Start of the list
int tail = -1;   // End of the list
int size = 0;    // Size of the list

// Function to insert an element at the end
void insertAtEnd(int value) {
    if (size == MAX) {
        printf("List is full!\n");
        return;
    }

    list[size].data = value;
    list[size].next = -1; // As it will be the last node, next is -1
    if (head == -1) { // First element being added
        list[size].prev = -1;
        head = tail = size;
    } else {
        list[size].prev = tail;
        list[tail].next = size;
        tail = size;
    }

    size++;
    printf("Element inserted.\n");
}

// Function to delete an element from the end
void deleteFromEnd() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    if (head == tail) { // Only one element in the list
        head = tail = -1;
    } else {
        int newTail = list[tail].prev;
        list[newTail].next = -1;
        tail = newTail;
    }

    size--;
    printf("Element deleted from the end.\n");
}

// Function to display the list
void displayList() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int current = head;
    printf("Doubly Linked List: ");
    while (current != -1) {
        printf("%d ", list[current].data);
        current = list[current].next;
    }
    printf("\n");
}

// Main function with menu-driven options
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete from End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                displayList();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

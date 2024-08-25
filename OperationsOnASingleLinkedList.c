//Operationa on a single linked list 
    // 1 -Insert a new element at the beginning of the list
    // 2 - Insert a new element at the end of the list
    // 3 - Delete the first element from the list
    // 4 - Delete the last element from the list
    // 5 - Display the elements of the list
    

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function prototypes
void insertAtstart(int data);
void insertAtend(int data);
void deleteFirst();
void deleteLast();
void display();

// Global pointers
struct node *first = NULL, *last = NULL;

int main() {
    int choice, data;

    while (1) {
        printf("\n1 - Insert at the beginning\n");
        printf("2 - Insert at the end\n");
        printf("3 - Delete the first element\n");
        printf("4 - Delete the last element\n");
        printf("5 - Display the list\n");
        printf("6 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the start: ");
                scanf("%d", &data);
                insertAtstart(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtend(data);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to insert a node at the beginning
void insertAtstart(int data) {
    struct node *newNode =  malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = first;
    first = newNode;
}

// Function to insert a node at the end
void insertAtend(int data) {
    struct node *newNode =  malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (last == NULL) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

// Function to delete the first node
void deleteFirst() {
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = first;
    first = first->next;
    if (first == NULL) {
        last = NULL;
    }
    free(temp);
}

// Function to delete the last node
void deleteLast() {
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (first == last) {
        free(first);
        first = last = NULL;
        return;
    }

    struct node *temp = first;
    while (temp->next != last) {
        temp = temp->next;
    }
    free(last);
    last = temp;
    last->next = NULL;
}

// Function to display the linked list
void display() {
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

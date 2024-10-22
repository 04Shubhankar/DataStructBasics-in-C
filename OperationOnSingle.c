#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *new_node = newNode(data);
    new_node->next = head;
    head = new_node;
}

// Function to insert a node after a given node
void insertAfter(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node *new_node = newNode(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node *last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to delete the first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Function to delete the last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Function to delete a node after a given node
void deleteAfter(struct Node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("Previous node or node to be deleted cannot be NULL\n");
        return;
    }

    struct Node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to search for a node by value
struct Node *search(int key) {
    struct Node *current = head;
    while (current != NULL && current->data != key)
        current = current->next;

    return current;
}

// Function to print the linked list
void printList() {
    struct Node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAfter(head->next, 5);

    printList();

    deleteFirst();
    deleteLast();
    deleteAfter(head);

    printList();

    struct Node *result = search(5);
    if (result != NULL)
        printf("Element found at index: %d\n", result->data);
    else
        printf("Element not found\n");

    return 0;
}

// Creation of a Linked List in C

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *first , *last , *current;

int main(){
    int num;
    printf("Enter the number of nodes to create ");
    scanf("%d",&num);

    // Create first Node 
    first =  malloc(sizeof(struct node));
    printf("Enter the data for the first node ");
    scanf("%d",&first->data);
    first->next = NULL;
    last = first;

    // Create remaining nodes
    for(int i=1; i<num; i++){
        current =  malloc(sizeof(struct node));
        printf("Enter the data for the %d node ",i+1);
        scanf("%d",&current->data);
        current->next = NULL;
        last->next = current;
        last = current;
    }

    // Display the Linked List
    printf("\nLinked List: ");
    current = first;
    while(current!= NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");



}

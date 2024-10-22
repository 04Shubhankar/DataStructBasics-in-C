#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int x) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Function to pop an element from the stack
int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    int i, value;
    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (postfix[i]) {
                case '+':
                    value = op2 + op1;
                    break;
                case '-':
                    value = op2 - op1;
                    break;
                case '*':
                    value = op2 * op1;
                    break;
                case '/':
                    value = op2 / op1;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            push(value);
        }
    }
    return pop();
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}

// Checking Wellformedness of Brackets

#include <stdio.h>

#define MAX 100

int main() {
    char brackets[MAX];
    char stack[MAX];
    int top = -1;

    printf("Enter Expression: ");
    scanf("%s", brackets);  // Read the entire line of input

    // Iterate over each character in the input expression
    for (int i = 0; brackets[i] != '\0'; i++) {
        char ch = brackets[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            if (top < MAX - 1) {
                stack[++top] = ch;
            } else {
                printf("Stack overflow\n");
                return 1;
            }
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {
                printf("Unbalanced brackets\n");
                return 1;
            } 
            else {
                char opening = stack[top--];
                // Directly check for valid bracket pairs
                if (opening == '(' && ch != ')' ||
                    opening == '[' && ch != ']' ||
                    opening == '{' && ch != '}') {
                    printf("Unbalanced brackets\n");
                    return 1;
                }
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    if (top == -1) {
        printf("Brackets are balanced\n");
    } else {
        printf("Unbalanced brackets\n");
    }

    return 0;
}

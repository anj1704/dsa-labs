#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int main() {
    printf("Enter the string to be evaluated in postfix notation:\n");

    Stack *stack = newStack();
    char input[100]; // Assuming a maximum input length of 100 characters
    char *token;

    fgets(input, sizeof(input), stdin);
    token = strtok(input, " "); // Tokenize input string by space

    while (token != NULL) {
        if (isdigit(*token)) {
            push(stack, atoi(token)); // Convert token to integer and push onto stack
        } else {
            int b = *pop(stack);
            int a = *pop(stack);
            int ans;
            switch (*token) {
                case '+':
                    ans = a + b;
                    break;
                case '-':
                    ans = a - b;
                    break;
                case '*':
                    ans = a * b;
                    break;
                case '/':
                    ans = a / b;
                    break;
                default:
                    printf("Invalid operator: %c\n", *token);
                    freeStack(stack);
                    return 1;
            }
            push(stack, ans);
        }
        token = strtok(NULL, " "); // Get next token
    }

    printf("The value of the expression is %d\n", *pop(stack));
    freeStack(stack);
    return 0;
}

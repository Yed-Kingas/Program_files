#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators and operands
char stack[MAX];
int top = -1;

// Stack for evaluation
int evalStack[MAX];
int evalTop = -1;

// Push function for operator stack
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop function for operator stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Push function for evaluation stack
void evalPush(int x) {
    if (evalTop == MAX - 1) {
        printf("Evaluation stack overflow\n");
        return;
    }
    evalStack[++evalTop] = x;
}

// Pop function for evaluation stack
int evalPop() {
    if (evalTop == -1) {
        printf("Evaluation stack underflow\n");
        return -1;
    }
    return evalStack[evalTop--];
}

// Function to return precedence of operators
int precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;
    while (infix[i] != '\0') {
        if (isalpha(infix[i])) {
            // If operand (variable), add to postfix expression
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            // Pop until left parenthesis is found
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            // Operator is encountered
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators from stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null terminate postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix, int values[]) {
    int i = 0, a, b;
    while (postfix[i] != '\0') {
        if (isalpha(postfix[i])) {
            // Push the value of the variable to evaluation stack
            evalPush(values[postfix[i] - 'A']); // Index based on 'A'-'Z'
        } else {
            // Pop two operands
            b = evalPop();
            a = evalPop();
            switch (postfix[i]) {
                case '+':
                    evalPush(a + b);
                    break;
                case '-':
                    evalPush(a - b);
                    break;
                case '*':
                    evalPush(a * b);
                    break;
                case '/':
                    evalPush(a / b);
                    break;
            }
        }
        i++;
    }
    return evalPop(); // Result will be the last element in the evaluation stack
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];
    int values[26]; // For storing values of variables A-Z

    printf("Enter an infix expression (with variables): ");
    scanf("%s", infix);

    // Convert to postfix
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    // Take values for variables from the user
    for (int i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i])) {
            if (values[infix[i] - 'A'] == 0) { // To avoid asking for value multiple times
                printf("Enter the value of %c: ", infix[i]);
                scanf("%d", &values[infix[i] - 'A']);
            }
        }
    }

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix, values);
    printf("Result of Evaluation: %d\n", result);

    return 0;
}

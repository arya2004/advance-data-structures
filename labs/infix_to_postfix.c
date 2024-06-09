#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Global stack for storing operators during infix to postfix conversion
char Stack[100];
int top = -1;

// Function to determine precedence of operators
int precedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return -1; // Invalid operator
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main()
{
    // Input infix expression
    char equation[100] = "a+b*(c^d-e)^(f+g*h)-i";

    // Iterate through each character in the infix expression
    for (int i = 0; equation[i] != '\0'; i++)
    {
        if (equation[i] == '(')
        {
            top++;
            Stack[top] = equation[i];
        }
        else if (equation[i] == ')')
        {
            // Pop operators from the stack until a '(' is encountered
            while (top > -1 && Stack[top] != '(')
            {
                printf("%c", Stack[top]);
                top--;
            }
            top--; // Discard the '(' from the stack
        }
        else if (isOperator(equation[i]))
        {
            // Pop operators with higher or equal precedence from the stack
            while (top > -1 && precedence(Stack[top]) >= precedence(equation[i]))
            {
                printf("%c", Stack[top]);
                top--;
            }
            top++;
            Stack[top] = equation[i]; // Push the current operator onto the stack
        }
        else
        {
            printf("%c", equation[i]); // Output operands directly
        }
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Global stack and top index declaration
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
        return -1;
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

    // Processing the infix expression
    for (int i = 0; equation[i] != '\0'; i++)
    {
        if (equation[i] == '(')
        {
            top++;
            Stack[top] = equation[i];
        }
        else if (equation[i] == ')')
        {
            // Pop and print operators until '(' is encountered
            while (top > -1 && Stack[top] != '(')
            {
                printf("%c", Stack[top]);
                top--;
            }
            top--; // Discard '('
        }
        else if (isOperator(equation[i]))
        {
            // Pop and print operators with higher or equal precedence
            while (top > -1 && precedence(Stack[top]) >= precedence(equation[i]))
            {
                printf("%c", Stack[top]);
                top--;
            }
            top++;
            Stack[top] = equation[i]; // Push current operator onto stack
        }
        else
        {
            printf("%c", equation[i]); // Output operand directly
        }
    }

    // Pop and print remaining operators from stack
    while (top > -1)
    {
        printf("%c", Stack[top]);
        top--;
    }

    return 0;
}

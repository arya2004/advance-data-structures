

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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
    char equation[100] = "x+y*z/w+u";

    // Reversing the input infix expression
    int len = strlen(equation);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = equation[i];
        equation[i] = equation[len - i - 1];
        equation[len - i - 1] = temp;
    }

    // Performing the conversion to prefix expression
    for (int i = 0; equation[i] != '\0'; i++)
    {
        if (equation[i] == '(')
        {
            equation[i] = ')';
        }
        else if (equation[i] == ')')
        {
            equation[i] = '(';
        }
    }

    for (int i = 0; equation[i] != '\0'; i++)
    {
        if (equation[i] == '(')
        {
            top++;
            Stack[top] = equation[i];
        }
        else if (equation[i] == ')')
        {
            while (top > -1 && Stack[top] != '(')
            {
                printf("%c", Stack[top]);
                top--;
            }
            // Remove the '(' from stack
            top--;
        }
        else if (isOperator(equation[i]))
        {
            while (top > -1 && precedence(Stack[top]) > precedence(equation[i]))
            {
                printf("%c", Stack[top]);
                top--;
            }
            top++;
            Stack[top] = equation[i];
        }
        else
        {
            printf("%c", equation[i]);
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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>


char Stack[100];
int top = -1;


int precedence(char operator)
{
    if(operator == '+' || operator == '-' )
        return 1;
    else if(operator == '*' || operator == '/' )
        return 2;
    else if(operator == '^' )
        return 3;
    else
        return -1;
                
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^');
}
 


int main(){

    char equation[100]  = "x+y*z/w+u";

    for (int i = 0; equation[i] != '\0'; i++) {
 
        if (equation[i] == '(') {
            equation[i] = ')';
        }
        else if (equation[i] == ')') {
            equation[i] = '(';
        }
    }
    int a = strlen(equation);

    for (int i = a; i >= 0; i--)
    {
       if (equation[i] == '(')
        {
            top++;
            Stack[top] = equation[i];
        }
        else if(equation[i] == ')')
        {
            while (top > -1 && Stack[top] != '(')
            {
               printf("%c", Stack[top]);
               top--;
            }
            //remove bracket
            top--;
        }

        else if(isOperator(equation[i])){
            while (top > -1 && precedence(Stack[top]) > precedence(equation[i]))
            {
                printf("%c", Stack[top]);
                top--;
            }
            top++;
            Stack[top] = equation[i];
            
        }

       
       else{
        printf("%c", equation[i]);
       }
    }
      //pop all
    while (top > -1)
    {
        printf("%c", Stack[top]);
                top--;
    }

    
    return 0;
}
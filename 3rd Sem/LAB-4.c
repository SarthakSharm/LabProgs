#define SIZE 55 /* Size of Stack */
#include <ctype.h>
#include <stdio.h>
#include<conio.h>


char s[SIZE];
int top = -1; /* Global declarations */

int push(char elem) /* Function for PUSH operation */
{
    s[++top] = elem;
    return 0;
}

char pop() /* Function for POP operation */
{
    return (s[top--]);
}

int pr(char elem) /* Function for precedence */
{
    switch (elem)
    {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
    }
    return 0;
}

int main() /* Main Program */
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    printf("\n\nEnter the Infix Expression ");
    scanf("%s", infix);
    push('#');
    
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
            postfix[k++] = pop();
            pop(); /* Remove ( */
        }
        else /* Operator */
        {
            while (pr(s[top]) >= pr(ch))
            postfix[k++] = pop();
            push(ch);
        }
    }
    
    while (s[top] != '#') /* Pop from stack till empty */
        postfix[k++] = pop();
    postfix[k] = '\0'; /* Make pofx as valid string */
    printf("\n\nGiven Infix Expn: %s \nPostfix Expn: %s\n", infix, postfix);
    getch();
    return 0;
    getch();
}
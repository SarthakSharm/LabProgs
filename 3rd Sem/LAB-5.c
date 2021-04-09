#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

double compute(char symbol, double op1, double op2)
{
    switch(symbol)
    {
        case'+': return op1 + op2;
        case'-': return op1 - op2;
        case'*': return op1 * op2;
        case'/': return op1 / op2;
        case'$':
        case'^': return pow(op1,op2);
        default: return 0;
    }


}


void main()
{
    double stack[20],res,op1,op2;
    int top =-1;
    int i;
    char postfix[30],symbol;
    printf("Enter expression:\n");
    gets(postfix);
    for(i=0;i<strlen(postfix);++i)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            stack[++top]=symbol-'0';
        else
        {
            op2=stack[top--];
            op1=stack[top--];
            res=compute(symbol,op1,op2);
            stack[++top]=res;
        }
    }
    res=stack[top];
    printf("\nThe result is : %f",res);
    getch();
}
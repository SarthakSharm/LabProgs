#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 10
int stack[MAX],item;
int ch, top=-1, count = 0 ;

void push(char symb){
    stack[++top]  = symb;
}

int pop(){
    return stack[top--];
}

int p(char symbol)
{
	switch(symbol)
	{
		case '+' :
		case '-':
			return 1;
            break;

		case '*':
		case '/':
        case '%':
			return 2;
            break;

		case '^':
		case '$': 
			return 3;
            break;

		case '(':
        case ')':
            return 0;

		case '#': 
            return -1;		
	}
    
}

/*int G(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 3;

		case '^':
		case '$': 
			return 6;

	    case '(': return 9;

        case ')': return 0;

        default: return 7;
    }
}*/

/*void i_p(char infix[], char postfix[]){
    int top, i , j;
    char s[30], symbol;
    top=-1;
    s[++top]='#';
    for( i = 0 ; i < strlen(infix); i++){
        symbol=infix[i];
        while(F(s[top])>G(symbol)){
            postfix[j]=s[top--];
            j++;
        }
        if(F(s[top])!= G(symbol))
            s[++top] = symbol;
        else
            top--;
    }
}*/

void inf_to_pos(char infix[],char postfix[]){
    int i , j =0 ;
    char symb, temp;
    push('#');
    for(i=0; infix[i]!='\0';++i){
        symb=infix[i];
        switch(symb){
            case '(' : push(symb);
              break;
            case ')' : temp=pop();
                while(temp!='('){
                    postfix[j++]=temp;
                    temp=pop();
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
            case '$':
                while(p(stack[top>=p(symb)]))
                {
                    temp=pop();
                    postfix[j++]=temp;
                }
                push(symb);
                break;
            default: postfix[j++]=symb;

        }
    }
    while(top>0){
        temp=pop();
        postfix[j++]=temp;
    }
    postfix[j]='\0';
}


void main()
{
    char infix[20],postfix[20];
    printf("Enter infix\n");
    gets(infix);
    inf_to_pos(infix,postfix);
    printf("Infix:%s\nPostfix:%s\n",infix,postfix);
    getch();
}
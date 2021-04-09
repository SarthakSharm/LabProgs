#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX],item;
int ch, top=-1, count = 0 ;

void push(){
    if( top == MAX-1)
        printf("Over flow\n");
    else
        stack[++top]=item;    
}

void pop(){
    printf("%d",top);
    if( top == -1)
        printf("Unerflow\n");
    else
        printf("Popped element is : %d",stack[top--]);
}

void palindrome(){
    int i, j, f =0 ;
    for ( i = 0 , j = top ; i<j ; i++, j--){
        if(stack[i]!=stack[j]){
            f = 1;
            break;
        }
    }
    if ( f == 0 )
        printf("Plindroeme");
    else
        printf("not palindrome");

}

void display(){
    int i;
    printf("STACK IS :\n");
    for( i = top ; i>=0 ; i--)
        printf("\n------\n|%d|\n",stack[i]);

}

void main()
{
    do{
        printf("\n\n----MAIN MENU----\n");
        printf("\n1. PUSH (Insert) in the Stack");
        printf("\n2. POP (Delete) from the Stack");
        printf("\n3. PALINDROME check using Stack");
        printf("\n4. Exit (End the Execution)");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {   
            case 1: printf("\nEnter a element to be pushed: ");
                    scanf("%d", &item);
                    push( );
                    display( );
                    break;

            case 2:
                    pop( ); 
                    display();
                    break;
            case 3:
                    palindrome( );
                    break;
            case 4:
                    display();
                    break;
            default:
                    printf("\nEND OF EXECUTION");
        }
    }while (ch != 5);
getch();
}


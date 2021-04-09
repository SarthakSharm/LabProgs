#include<stdio.h>
#include<conio.h>
#define MAX 15

int a[MAX],n,elem,i,pos ;

void create(){
    printf("size: ");
    scanf("%d",&n);
    for ( i=0 ; i <n ; ++i)
        scanf("%d",&a[i]);
}

void display(){
    for ( i = 0 ; i < n ; ++i)
        printf("%d\t",a[i]);
}

void insert(){
    printf("Enter POS and Number :\n");
    scanf("%d%d",&pos,&elem);
    pos=pos-1;
    for(i=n-1; i>=pos ; --i)
        a[i+1]=a[i];
    a[pos]=elem;
    n+=1;
}

void delete(){
    printf("Enter pos: ");
    scanf("%d",&pos);
    pos-=1;
    elem = a[pos];
    for(i=pos; i <= n-1 ; ++i)
        a[i]=a[i+1];
    n-=1;
}

void main(){
    int ch;
    do{
        printf("Enter choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: exit(0); break;
            default: printf("Invalid!\n"); break;
        }
    }while(ch!=5);
    getch();
}

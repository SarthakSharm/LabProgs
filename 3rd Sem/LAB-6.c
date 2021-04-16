#include<stdio.h>
#include<conio.h>
#define MAX 4

int ch, front = 0 , rear = -1, count = 0;
char q[MAX], item; 

int insert(){
	if(count==MAX)
		printf("Queue is full");
	else{
		printf("Enter value to be entered : \n");
		item = getche();
		rear=(rear+1) % MAX;
		q[rear]=item;
		count++;
	}
	return 0;
}

int deletee(){
	if(count==0)
		printf("Underflow\n");
	else
	{
		if (front > rear && rear == MAX-1)
		{
			front =0 ; rear =-1; count =0 ;
		}
		else
		{
			count--;
			printf("Deleted item is : %c\n",q[front]);
			front = (front+1)%MAX;
		}
	}
	return 0;
}

int display(){
	int i;
	if( count == 0 )
		printf("Empty\n");
	else
	{
		printf("Queue is : \n");
		for ( i = front; i != rear; i = (i +1)%MAX)
			putch(q[i]);
		printf("%c\t",q[i]);
	}
	return 0;
}


int main(){

	do{
		printf("\nEnter Choice:\n1.)Insert\n2.)Delete\n3.)Display:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:insert();
			break;
			case 2:deletee();
			break;
			case 3:display();
			break;
		}
	}while(ch!=4);
	getch();
	return 0;
}
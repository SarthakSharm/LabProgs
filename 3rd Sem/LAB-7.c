#include<stdio.h>
#include<conio.h>
#include<cstdlib>
int max = 4;
int count;

struct student{
	char usn[10];
	char name[10];
	char branch[10];
	int sem;
	char phno[10];
	struct student *next;
} *first = NULL, *temp = NULL, *last = NULL;

int new_node(){
	temp=(struct student *)malloc(sizeof(struct student));
	printf("Enter USN, Name, Branch, Sem, Ph.no\n");
	fflush(stdin);
	//flushall();
	gets(temp->usn);
	fflush(stdin);
	//flushall();
	gets(temp->name);
	fflush(stdin);
	//flushall();
	gets(temp->branch);
	scanf("%d",&(temp->sem));
	fflush(stdin);
	//flushall();
	gets(temp->phno);
	temp->next = NULL;
	return 0;
}

int countnodes(){
	count = 0 ;
	temp = first;
	while(temp==NULL){
		temp=temp->next;
		count++;
	}
	return count;
}



int create(){
	if (first==NULL){
		new_node();
		first = temp;
		last = first;
	}
	else
		printf("Already created ");
	return 0;
}

int insert_front(){
	new_node();
	temp->next=first;
	first = temp;
	return 0;
}

int insert_rear(){
	new_node();
	last->next = temp;
	last = temp;
	return 0;
}

int insert(){
	int ch;
	do{
		printf("\n1.front\n2.end\nEnter choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_front();
			break;
			case 2: insert_rear();
			break;

		}
	}while(ch!=3);	
	return 0;
}

int delete_front(){
	if(first==NULL)
		printf("Underflow\n");
	else
	{
		temp = first;
		first = first->next ;
		free(temp);
	}
	return 0;
}

int delete_rear(){
	if(first==NULL){
		printf("Underflow\n");
		return 0;
	}
	if(first->next==NULL){
		delete_front();
		return 0;
	}
	temp=first;
	while(temp->next!=last){
		temp=temp->next;
	}
	temp->next=NULL;
	free(last);
	last=temp;
	return 0;
}

int deletee(){
	int ch;
	do{
		printf("\n1.front\n2.end\nEnter choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: delete_front();
			break;
			case 2: delete_rear();
			break;

		}
	}while(ch!=3);	
	return 0;
}

int display(){
	temp = first;
	if ( first ==NULL)
		printf("NO DATA");
	else
	{
		printf("\n-----------Student Data------------\n\nUSN\tName\tBranch\tSem\tph\n");
		while(temp!=NULL){
			printf("\n%s\t%s\t%s\t%d\t%s",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
			temp=temp->next ;
		}
	}
	return 0;
}

int main(){
	int ch, i, n;
	do{
		printf("\n1.)Create\n2.)Display\n3.)Insert\n4.)Delete\n5.)Stack\n6.)Queue\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:create();
			break;
			case 2:display();
			break;
			case 3:insert();
			break;
			case 4:deletee();
			break;
		}
	}while(ch!=7);
	return 1;
}
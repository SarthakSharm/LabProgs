#include<stdio.h>
#include<stdlib.h>

struct BST{
	int data;
	struct BST *left;
	struct BST *right;
} *temp= NULL, *root = NULL;

typedef struct BST NODE;

NODE* create(NODE* root ,int info){
	if(root == NULL){
		temp = (struct BST *)malloc(sizeof(struct BST));
		temp->data = info;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if(info < (root->data))
		root->left = create(root->left,info);
	if(info > (root->data))
		root->right = create(root->right,info);
	return root;
}

NODE* search( NODE*root ,int info){
	if ( root == NULL)
		printf("Not Found\n");
	else if( info < root->data )
		search(root->left, info);
	else if( info > root->data )
		search(root->right, info);
	else
		printf("Element found ");
	return root;
}

NODE* inorder(NODE*root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
	return root;
}

NODE* preorder(NODE*root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);		
		preorder(root->right);
	}
	return root;
}

NODE* postorder(NODE*root){
	if(root!=NULL){		
		postorder(root->left);		
		postorder(root->right);
		printf("%d",root->data);
	}
	return root;
}

int main()
{
	int info , i , ch, n;
	do{
		printf("\n1.)Insert\n2.)Search\n3.)in\n4.)pre\n5.)post\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			printf("How many values : \n");
			scanf("%d",&n);
			for( i = 0 ; i < n ; ++i){
				scanf("%d",&info);
				root=create(root,info);
			}
			break;
			
			case 2:
			printf("Enter element to search \n");
			scanf("%d",&info);
			search(root,info);
			break;

			case 3:inorder(root);
			break;
			
			case 4:preorder(root);
			break;
			
			case 5:postorder(root);
			break;


		}
	}while(ch!=6);
	return 0;
}
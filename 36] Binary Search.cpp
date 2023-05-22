#include<stdio.h>
#include<stdlib.h>

struct BTNode
{
	int data;
	BTNode *left;
	BTNode *right;	
};

BTNode *root;

void place_node(BTNode *root,BTNode *node)
{
	if(root->data<node->data)
	{
		if(root->right==NULL)
		{
			root->right=node;
		}
		else
		{
			place_node(root->right,node);
		}
	}
	else
	{
		if(root->left==NULL)
		{
			root->left=node;
		}
		else
		{
			place_node(root->left,node);
		}
	}
}

void inorder(BTNode *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d\t",r->data);
		inorder(r->right);
	}
}

main()
{
	int i,sz;
	BTNode *temp;
	printf("Enter Number of elements : ");
	scanf("%d",&sz);
	
	printf("\nEnter Array elements:\n");
	int a[sz];
	for(i=0;i<sz;i++)
	{
		scanf("%d",&a[i]);
	}
	
	root = (BTNode*)malloc(sizeof(BTNode));
	root->data=a[0];
	root->left=NULL;
	root->right=NULL;
	
	for(i=1;i<sz;i++)
	{
		temp=(BTNode*)malloc(sizeof(BTNode));
		temp->data=a[i];
		temp->left=NULL;
		temp->right=NULL;
		
		place_node(root,temp);
		
	}
	printf("\n\n\nSorted \n\n");
	inorder(root);
}

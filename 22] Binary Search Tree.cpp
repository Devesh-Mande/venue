#include<stdio.h>
#include<stdlib.h>

struct BTNode
{
	BTNode *P;
	BTNode *L;
	int ele;
	BTNode *R;
};

BTNode *root;

main()
{
	int a[100],i,s;
	BTNode *nn;
	root=NULL;
	
	printf("Enter Size of Tree ");
	scanf("%d",&s);
	
	printf("Enter Tree \n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	
	nn=(BTNode*)malloc(sizeof(BTNode));
	nn->P=NULL;
	nn->L=NULL;
	nn->R=NULL;
	nn->ele=a[0];
	root=nn;
	
	for(i=1;i<s;i++)
	{
		nn=(BTNode*)malloc(sizeof(BTNode));
		nn->P=NULL;
		nn->L=NULL;
		nn->R=NULL;
		nn->ele=a[i];
		
		place_node(root,nn);
		
	}	
}

void place_node(BTNode *p,BTNode *nn)
{
	if(nn->ele>p->ele)
	{
		if(p->R==NULL)
		{
			p->R=p;
			nn->P=p;
		}
	}	
	
	
}


















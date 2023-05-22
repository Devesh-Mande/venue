#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	Node* next;
};

Node* first;
void array_to_LL(int t[])
{
	int i;
	Node *nn,*t1;
	
	for(i=0;i<10;i++)
	{
		nn=(Node*) malloc (sizeof(Node));
		nn->ele=t[i];
		
		if(first==NULL)
		{
			nn->next=NULL;
			first=nn;
			t1=nn;
		}
		else
		{
			t1->next=nn;
			nn->next=NULL;
			t1=nn;
		}
	}
}
void display()
{
	Node *t1;
	printf("\n\n+++++SLLL+++++\n\nNodes:");
	t1=first;
	while(t1!=NULL)
	{
		printf("\t|%d|%d|",t1->ele,t1->next);
		t1=t1->next;
	}
	printf("\nPtrs: ");
	t1=first;
	while(t1!=NULL)
	{
		printf("\t|%d|",t1);
		t1=t1->next;
	}
	printf("\n\n\n");
}
main()
{
	int a[10],i;
	Node *t1;
	
	first = NULL;
	
	printf("Index\tInput\n");

	for(i=0;i<10;i++)
	{
		printf("%d\t",i);
		scanf("%d",&a[i]);
	}
	
	array_to_LL(a);
	display();
}

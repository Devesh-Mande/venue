#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	Node *next;
};

Node *first;

void Insert();
void Remove();
void Display();
void Reverse();

main()
{
	int ch;
	
	first=NULL;
	
	do
	{
		printf("\n1-INSERT");
		printf("\n2-REMOVE");
		printf("\n3-REVERSE");
		printf("\n4-DISPLAY");
		printf("\n5-EXIT");
		printf("\n->Provide Your Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				Insert();				
				break;
			}
			case 2:{
				Remove();
				break;
			}
			case 3:{
				Reverse();
				break;
			}
			case 4:{
				Display();
				break;
			}
			case 5:{
				exit(0);
				break;
			}
		}
	}while(1);
}

void Insert()
{
	int ch,sel;
	Node *nn,*t1,*t2;
	
	nn=(Node*)malloc(sizeof(Node));
	printf("\n->Enter element to insert : ");
	scanf("%d",&nn->ele);
	
	if(first==NULL)
	{
		nn->next=NULL;
		first=nn;
		printf("\n\nList Generated\n");
	}
	else
	{
		printf("\n\t1-From Front ");
		printf("\n\t2-From Rear ");
		printf("\n\t3-At Selected ");
		printf("\n\t->Provide Your Choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				nn->next=first;
				first=nn;
				printf("\n\nNew Node Inserted From Front \n");
				break;
			}
			case 2:{
				t1=first;
				while(t1->next!=NULL)
				{
					t1=t1->next;
				}
				nn->next=NULL;
				t1->next=nn;
				printf("\n\nNew Node Inserted From Rear \n");
				break;
			}
			case 3:{
				printf("\n\t->Enter Element after to Insert : ");
				scanf("%d",&sel);
				
				t1=first;
				while(t1!=NULL)
				{
					if(t1->ele==sel)
					{
						break;
					}
					t1=t1->next;
				}
				if(t1==NULL)
				{
					printf("\n\nNo Such Node Found \n");
				}
				else
				{
					nn->next=t1->next;
					t1->next=nn;
					printf("\n\nNew Inserted at Selected Node \n");
				}
				break;
			}
		}
	}
}
void Remove()
{
	int ch,sel;
	Node *t1,*t2;
	
	if(first==NULL)
	{
		printf("\n\nList underflow \n");
	}
	else
	{
		printf("\n\t1-Front");
		printf("\n\t2-Rear");
		printf("\n\t3-Selected");
		printf("\n\t->Provide Your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				
				t1=first;
				first=first->next;
				free(t1);
				if(first==NULL)
				{
					printf("\n\nList Destroyed\n");
				}
				else
				printf("\n\nFront Node Removed\n");
				break;
			}
			case 2:{
				t1=first;
				while(t1->next!=NULL)
				{
					t2=t1;
					t1=t1->next;
				}
				if(t1==first)
				{
					t1=first;
					first=NULL;
					free(t1);
					printf("\n\nList Destroyed\n");
				}
				else
				{
					t2->next=NULL;
					free(t1);
					printf("\n\nRear Node Removed\n");	
				}
				break;
			}
			case 3:{
				printf("\n\t->Enter ele to Remove : ");
				scanf("%d",&sel);
				
				t1=first;
				while(t1!=NULL)
				{
					if(t1->ele==sel)
					{
						break;
					}
					t2=t1;
					t1=t1->next;
				}
				if(t1==NULL)
				{
					printf("\n\nNo Node Found\n");
				}
				else if(t1==first&&t1->next!=NULL)
				{
					first=first->next;
					free(t1);
					printf("\n\nSelected Node Removed\n");
				}
				else if(t1==first&&t1->next==NULL)
				{
					first=NULL;
					free(t1);
					printf("\n\nList Destroyed\n");
				}
				else 
				{
					t2->next=t1->next;
					free(t1);
					printf("\n\nSelected Node Removed\n");
				}
			
				break;
			}
		}
	}
}
void Display()
{
	Node *t1;
    if(first==NULL)
    {
    	printf("\n\nNothing to Dispaly\n");
	}
	else
	{
		printf("\n++++Linked List ++++\n\n");
		t1=first;
		while(t1!=NULL)
		{
			printf("%d\t",t1->ele);
			t1=t1->next;
		}
	}
	printf("\n");
}
void Reverse()
{
	if(first==NULL)
	{
		printf("\n\nList is empty\n");
		return;
	}
	int swap;
	Node *f,*l,*sl;
	f=first;
	sl=NULL;
	while(f->next!=sl && sl!=f)
	{
		l=f;
		while(l->next!=sl)
		{
			l=l->next;
		}
		
		swap=f->ele;
		f->ele=l->ele;
		l->ele=swap;
		
		f=f->next;
		sl=l;
	}
	printf("\n\nList Reversed\n");
}

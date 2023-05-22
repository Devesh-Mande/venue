#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int coef;
	int expo;
	Node* next;	
};

Node* CreateLL()
{
	Node *first,*last,*nn;
	char ch;
	first=NULL;
	do
	{
		nn=(Node*)malloc(sizeof(Node));
		printf("\nCoeficent :");
		scanf("%d",&nn->coef);
		printf("Exponenet : ");
		scanf("%d",&nn->expo);
		nn->next=NULL;
		if(first==NULL)
		{
			first=nn;
			last=nn;
		}
		else
		{
			last->next=nn;
			last=nn;
		}
		
		fflush(stdin);
		printf("\nDo you want to insert another Node (y/n) : ");
		scanf("%c",&ch);
	}while(ch=='y');
	return first;
}
Node* AddPoly(Node*f1,Node*f2)
{
	Node *temp,*nn,*first;
	int l=0,c=0,sum;
	first=NULL;
	
	do
	{
		sum=0;
		temp=f1;
		while(temp!=NULL)
		{
			if(l<temp->expo)
			{
				l=temp->expo;
			}
			if(temp->expo==c)
			{
				sum=sum+temp->coef;
			}
			temp=temp->next;
		}
		
		temp=f2;
		while(temp!=NULL)
		{
			if(l<temp->expo)
			{
				l=temp->expo;
			}	
			if(temp->expo==c)
			{
				sum=sum+temp->coef;
			}
			temp=temp->next;
		}
		
		nn=(Node*)malloc(sizeof(Node));
		nn->coef=sum;
		nn->expo=c;
		
		if(first==NULL)
		{
			nn->next=NULL;
			first=nn;
		}
		else
		{
			nn->next=first;
			first=nn;
		}
		c++;
	}while(c<=l);
	return first;
}
void Display(Node* t)
{

	while(t!=NULL)
	{
		printf(" (%dx^%d) +",t->coef,t->expo);
		t=t->next;
	}
	printf("\b \b");
}
main()
{
	Node *f1,*f2,*f3;
	
	printf("Enter 1st Polynomial : \n");
	f1=CreateLL();
	printf("\nYou Entered this Polynomial : ");
	Display(f1);
	
	printf("\n\nEnter 2nd Polynomial : \n");
	f2=CreateLL();
	printf("\nYou Entered this Polynomial : ");	
	Display(f2);
	
	f3=AddPoly(f1,f2);
	printf("\n\nAdding Both Polynomials ........\n\n");
	printf("\n\n\n Addition Polynomial : ");
	Display(f3);
}

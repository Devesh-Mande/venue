#include<stdio.h>
#include<stdlib.h>

void insert();
void remove();
void display();
struct Node
{
	int ele;
	Node *next;
};

Node *first;

main()
{
	int ch;
	first=NULL;
	
	do
	{
		printf("\n\n1-Insert\n");
		printf("2-Remove\n");
		printf("3-Display\n");
		printf("4-Exit\n");
		printf("Provide your choice : ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:{
				insert();
				break;
			}
			case 2:{
				remove();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}while(1);
}

void insert()
{
	int ch,sel;
    Node *nn,*temp;
	
	nn=(Node*) malloc (sizeof(Node));
	
	printf("Enter Element to insert : ");
	scanf("%d",&nn->ele);
	
	if(first==NULL)
	{
		first=nn;
		nn->next=NULL;
		printf("\nLinked list Genereted\n");
	}
	else
	{
		printf("\n1-From Front ");
		printf("\n2-From Rear ");
		printf("\n3-From Selected  ");
		printf("\nProvide your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				//algorith for inserting from Front 
					nn->next=first;
					first=nn;
					printf("\nNew Node is Insereted from Front ");
				break;
			}
			case 2:{
				//algorith for inserting from Rear
					temp=first;
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					nn->next=NULL;
					temp->next=nn;
					printf("\nNew Node Insrted from Rear ");
				break;
			}
			case 3:{
				//algorith for inserting from Selcted
				printf("\nEnter element after you want to Insert : ");
				scanf("%d",&sel); 
				temp=first;
				while(temp!=NULL)
				{
					if(temp->ele==sel)
					{
						break;
					}
					temp=temp->next;
				}
				if(temp==NULL)
				{
					printf("\nSelected element not found \nNode Rejected");
				}
				else
				{
					nn->next=temp->next;
					temp->next=nn;
					printf("\nNew Node Insert after selcted Node ");
				}
				break;
			}
		}
	}
}
void remove()
{
	int ch,sel;
	Node *temp,*temp2;
	
	if(first==NULL)
	{
		printf("\nLink list underflow\n");
	}
	else
	{
		printf("\n1-Front ");
		printf("\n2-Rear ");
		printf("\n3-Seleceted ");
		printf("\nProvide your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				temp=first;
				first=first->next;
				free(temp);
				printf("\nFirst Node removed");
				break;
			}
			case 2:{
				temp=first;
				while(temp->next!=NULL)
				{
					temp2=temp;
					temp=temp->next;
				}
				if(temp==first)
				{
					free(first);
					first=NULL;
					printf("\nLast Node removed and linked list Degenereted \n");
				}
				else
				{
					temp2->next=NULL;
					free(temp);
					printf("\nLast node removed");
				}
				break;
			}
			case 3:{
				printf("\nEnter element after you want to Remove : ");
				scanf("%d",&sel); 
				
				temp=first;
				while(temp!=NULL)
				{
					if(temp->ele==sel)
					{
						break;
					}
					temp2=temp;
					temp=temp->next;
				}
				if(temp==NULL)
				{
					printf("\nSelected node not found \n");
				}
				else if(temp==first)
				{
					first=temp->next;
					free(temp);
					printf("\nSelected Node Removed\n");
				}
				else
				{
					temp2->next=temp->next;
					free(temp);
					printf("\nSelected Node Removed\n");	
				}
							
				break;
			}
		}
	}
}
void display()
{
	Node *temp;
	if(first==NULL)
	{
		printf("\nNothing to display\n");
	}
	else
	{
		printf("\nLinked list is \n========================\n\nNodes : ");
		temp=first;
		while(temp!=NULL)
		{
			printf("|%d|%d|\t",temp->ele,temp->next);
			temp=temp->next;
		}
		printf("\nptrs : ");
		temp=first;
		while(temp!=NULL)
		{
			printf("\t %d",temp);
			temp=temp->next;
		}
		
	}

}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *first=NULL;

void insert()
{
	int ch,ele,flag=1;
	struct Node *nn, *temp;
	nn = (struct Node *)malloc(sizeof(struct Node));
	nn->next = NULL;
	printf("Enter element to Insert\n");
	scanf("%d",&nn->ele);
	if(first == NULL)
	{
		first = nn;
		printf("Element inserted\n");
	}
	else
	{
		printf("\n1 - Insert at beginning\n2 - Insert at selected position\n3 - Insert at end\nProvide your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				nn->next = first;
				first = nn;
				printf("Element Inserted at first position\n");
				break;
			case 2 :
				printf("\nProvide element after which you want to insert new element : ");
				scanf("%d",&ele);
				temp = first;
				while(temp != NULL)
				{
					if(temp->ele == ele)
					{
						flag = 2;
						break;
					}
					temp = temp->next;
				}
				if(flag == 1)
				{
					printf("No such elemnet found\n");
				}
				else
				{
					nn->next = temp->next;
					temp->next = nn;
					printf("Element inserted after specified element\n");
				}
				break;
			case 3 :
			    temp = first;
				while(temp->next!= NULL)
				{
					temp = temp->next;
				}
				temp->next = nn;
				printf("Element inserted at end\n");
				break;
		}
	}
}

void remove()
{
	struct Node *temp,*temp2;
	int ch,ele;
	if(first==NULL)
	{
		printf("List is empty, Nothing to remove\n");
	}
	else
	{
		printf("\n1 - Remove from beginning\n2 - Remove from selected position\n3 - Remove from end\nProvide your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				first = first->next;
				break;
			case 2 :
				printf("\nEnter element which you want to remove : ");
				scanf("%d",&ele);
				temp = first;
				while(temp!=NULL)
				{
					if(temp->ele==ele)
					{
						break;
					}
					temp = temp->next;
				}
				temp2 = first;
				while(temp2->next!=temp)
				{
					temp2 = temp2->next;
				}
				temp2->next = temp->next;
				break;
            case 3 :
                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }
                    temp2 = first;
                    while(temp2->next!=temp)
                    {
                        temp2 = temp2->next;
                    }
                    temp2->next = NULL;
		}
		printf("Element removed\n");
	}
}

void display()
{
    struct Node* temp=first;
    do
    {
        printf(" %d",temp->ele);
        temp = temp->next;
    }while(temp!=NULL);
    printf("\n");
}

 main()
{
	int ch;
	while(1)
	{
		printf("\n 1 - INSERT\n 2 - REMOVE\n 3 - DISPLAY\n 4 - EXIT\n Provide your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
                    insert();
                    break;
			case 2 :
                    remove();
                    break;
			case 3 :
                    display();
                    break;
			case 4 :
                    exit(0);
                    break;
		}
	}
}

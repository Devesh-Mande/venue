#include<stdio.h>
#include<stdlib.h>

//DYNAMIC STACK ALGORITHM START 
struct Node
{
	int ele;
	struct Node *next;
};

struct Node *TOP;

void push_ele(int t)
{
	struct Node *nn;
	nn = (struct Node *) malloc(sizeof(struct Node));
    nn->ele=t;

	if(TOP==NULL)
	{
		nn->next = NULL;
		TOP = nn;
	}
	else
	{
		nn->next = TOP;
		TOP = nn;
	}

} // end of push operation

int pop_ele()
{
	int r;
	struct Node *temp;
	if(TOP == NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		temp = TOP;
		r=TOP->ele;
		TOP = TOP->next;
		free(temp);
	}
	
	return r;
} // end of pop operation

void display_stack()
{
	struct Node *temp;
	if(TOP == NULL)
	{
		printf("Stack is empty, Nothing to display...\n");
	}
	else
	{
		printf("Stack contains\n");
		temp = TOP;
		while(temp!=NULL)
		{
			printf("%c\n", temp->ele);
			temp = temp->next;
		}
	}
} // end of display operation
//DYNAMIC STACK ALGORITHM END 




//SOME GOLBLE DECLARATION 
int a[20][20]={{0}};
int print[20];
int count=0;			
int sz,sz2;


//FUNCTION TO CHECK ELEMENTS IN VISITED LIST
int check_visited_list(int sel)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(print[i]==sel)
		{
			return 0;
		}
	}
	return 1;
}

//FUCTION TO CHECK ELEMENT IN STACK
int check_stack(int sel)
{
	Node *temp;
	temp=TOP;
	while(temp!=NULL)
	{
		if(temp->ele==sel)
		{
			return 0;
		}
		temp=temp->next;
	}
	return 1;
}

//FUNCTION FOR DFS
void traval(int start,int sz)
{
	int i,flag=0;
	for(i=0;i<sz;i++)
	{
		if(a[start][i]==1)
		{
			if(check_stack(i) && check_visited_list(i))
			{
				flag=1;
				push_ele(i);
			}
		}
	}
	if(flag==0)
	{
		print[count]=pop_ele();
		count++;
	}
	if(TOP!=NULL)
	{
		traval(TOP->ele,sz);
	}
}

//FUNCTION TO ACCEPT SPARSE MATRIX 
void accept_sparse()
{
	int i,r,c;
	for(i=0;i<sz2;i++)
	{
		printf("Row : ");
		scanf("%d",&r);
		printf("Col : ");
		scanf("%d",&c);
		a[r][c]=1;
	}
}

//FUNCTION TO PRINT MATRIX
void print_matrix()
{
	int i,j;

	for(i=0;i<sz;i++)
	{
		printf("\n\n");
		for(j=0;j<sz;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n\n");
	}
}


main()
{
	TOP=NULL;
	char sel;
	int i;
	
	printf("Enter Number of Vertices : ");
	scanf("%d",&sz);
	
	printf("Enter Number of Non Zero elements : ");
	scanf("%d",&sz2);
	accept_sparse();
	
	print_matrix();

	fflush(stdin);
	printf("ENTER first Character to Start DFS(upper case latter) : ");
	scanf("%c",&sel);
	
	push_ele(sel-65);
	traval(TOP->ele,sz);
/*	while(TOP!=NULL)
	{
		traval(TOP->ele,sz);
	}
*/
	
	printf("\nOrder of Travasal is \n=================\n");
	for(i=0;i<count;i++)
	{
		printf("%c\t",print[i]+65);
	}
}

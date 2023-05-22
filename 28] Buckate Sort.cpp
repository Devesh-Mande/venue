#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define max 10

struct Node
{
	int ele;
	Node *next;
};
Node *f[10]={NULL};
Node *r[10]={NULL};

void insert(int i,int ele);
int remove(int i);
void display(int i);
void display();
int get_front(int i,int j);
main()
{
	int a[max],pass,i,j,d,num,flag;
	
	printf("Enter Array : \n");
	for(i=0;i<max;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(pass=1;;pass++)
	{
		printf("\n====================================\nPass : %d\nArray : ",pass);
		Sleep(2000);
		for(i=0;i<max;i++)
		{
			printf(" %d |",a[i]);
		}
		flag=0;
		for(i=0;i<max;i++)
		{
			num=a[i];
			for(j=1;j<=pass;j++)
			{
				d=num%10;
				num=num/10;
			}
			if(d!=0)
			{
				flag=1;
			}
			insert(d,a[i]);
		}
		if(flag==0)
		{
			printf("\n\nSorting Finished \n\n");
			break;
		}
		else
		{
			Sleep(500);
			printf("\n\nBuckates : ");
			Sleep(1000);
			display();
		}
		j=0;
		for(i=0;i<10;i++)
		{
			while(f[i]!=NULL)
			{
				a[j]=remove(i);
				j++;
			}
		}
	}
	for(i=0;i<max;i++)
	{
		printf("%d  ",a[i]);
	}
}

void insert(int i,int ele)
{
	Node *nn;
	
	nn=(Node*)malloc(sizeof(Node));
	nn->next=NULL;
	nn->ele=ele;
	if(f[i]==NULL)
	{
		f[i]=nn;
		r[i]=nn;
	}
	else
	{
		r[i]->next=nn;
		r[i]=nn;
	}
}
int remove(int i)
{
	int ret;
	Node* temp;
	if(f[i]!=NULL)
	{
		ret=f[i]->ele;
		temp=f[i];
		f[i]=f[i]->next;
		free(temp);
		return ret;
	}
}
void display()
{
	int flag2,i,j,ele,flag;
	printf("\n\n");
	flag2=0;
	for(i=1;;i++)
	{
		flag=0;
		for(j=0;j<10;j++)
		{
			ele=get_front(i,j);
			if(flag2==5)
			{
				printf("   [%d]  ",j);
			}
			else if(ele==0)
			{
				printf(" |     |");
			}
			else
			{
				printf(" |%5d|",ele);
				flag=1;	
			}
		}
		printf("\n");
		if(flag2==5)
		{
			break;
		}
		if(flag==0)
		{
			flag2=5;
		}
	}
	
}
int get_front(int i,int j)
{
	int k;
	Node *temp;
	temp=f[j];
	for(k=1;k<i&&temp!=NULL;k++)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		return 0;
	}
	else
	return temp->ele;
}

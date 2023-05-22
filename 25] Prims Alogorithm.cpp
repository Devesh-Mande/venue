#include<stdio.h>
#include<windows.h>

int get_matrix(int t[][20]);
void print_matrix(int t[][20],int sz);
int find_indegre_0(int t[][20],int sz);
void time_dots();
int check_circular(int t[],int l,int j);
int sorting(int t[][3],int l);

main()
{
	int graph[20][20]={{0}},vs[20]={0},adj[10][3]={{0}},mst[20][20]={{0}};
	int sz,l,c,i,j,k,ind,sum,step=1;
	int ele;
	
	sz=get_matrix(graph);
	
	printf("Printing Matrix :- \n=========================\n");
	print_matrix(graph,sz);
	
	l=0;
	vs[l]=find_indegre_0(graph,sz);
	
	printf("\nStep :- %d",step);
	printf("\nFinding Starting Vertice :  ");
	time_dots();
	
	printf("\n");
	printf("\nWe are Starting Spaning Tree from : %c",vs[0]+65);
	step++;
	printf("\n");
	do
	{	
		c=-1;
		Sleep(1000);
		printf("\n\nStep :- %d",step);
		step++;
		Sleep(1000);
		printf("\nAdjecency List :-\n======================= \n");
 		for(k=0;k<=l;k++)
		{
			i=vs[k];
			for(j=0;j<sz;j++)
			{
				if(graph[i][j] && check_circular(vs,l,j))
				{
					c++;
					adj[c][0]=i;
					adj[c][1]=j;
					adj[c][2]=graph[i][j];
					printf("\t%d]%c---%d---%c\n",c+1,i+65,graph[i][j],j+65);
					Sleep(500);
				}
			}
		}
		if(c!=-1)
		{
			ind=sorting(adj,c);
			
			i=adj[ind][0];
			j=adj[ind][1];
			ele=adj[ind][2];
			
			l++;
			vs[l]=j;
			mst[i][j]=ele;
			
			printf("\nSelecting Edge");
			Sleep(1000);
			printf("\n\t  %c---%d---%c",i+65,ele,j+65);
		}
		else
		{
			break;
		}
	}while(1);
	
	printf("\n\nCalculating Minium Spaning Tree : ");
	time_dots();
	
	printf("\n\nPrinting Minium Spaning Tree : \n========================\n");
	print_matrix(mst,sz);
	
	sum=0;
	printf("\nPrinting Visited list :- ");
	for(i=0;i<=sz;i++)
	{
		if(i<=l)
		{
			printf("%c , ",vs[i]+65);
		}
		for(j=0;j<=sz;j++)
		{
			
			sum=sum+mst[i][j];
		}
	}
	
	printf("\n\n\nSum = %d\n\n",sum);
	
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		{
			if(mst[i][j])
			{
				printf("%d\n%d\n%d\n",i,j,mst[i][j]);
			}
		}
	}
	
}
int get_matrix(int t[][20])
{
	int sz,sz2,i,r,c,w;
	
	printf("Enter no of Vertices : ");
	scanf("%d",&sz);
	
	printf("Enter Non Zero elements with weight : ");
	scanf("%d",&sz2);
	
	for(i=0;i<sz2;i++)
	{
		printf("\nRow : ");
		scanf("%d",&r);
		printf("Col : ");
		scanf("%d",&c);
		printf("Weight : ");
		scanf("%d",&w);
		t[r][c]=w;
	}
	return sz;
}

void print_matrix(int t[][20],int sz)
{
	int i,j;
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		{
			printf("\t%d",t[i][j]);
		}
		printf("\n");
	}
}

int find_indegre_0(int t[][20],int sz)
{
	int i,j,flag=0;
	for(j=0;j<sz;j++)
	{
		flag=0;
		for(i=0;i<sz;i++)
		{
			if(t[i][j]!=0)
			{
				flag=1;
				break;
			}
		}
		if(i==sz)
		{
			return j;
		}
	}
	return 8;
}

void time_dots()
{
	int i,j;
	for(i=1;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf(".");
			Sleep(1000);
		}
		printf("\b\b\b   \b\b\b");
	}
}

int check_circular(int t[],int l,int j)
{
	int i;
	for(i=0;i<=l;i++)
	{
		if(t[i]==j)
		{
			return 0;
		}
	}
	return 1;
}

int sorting(int t[][3],int l)
{
	int i,s,index;
	
	s=t[0][2];
	index=0;
	
	for(i=1;i<=l;i++)
	{
		if(t[i][2]<s)
		{
			s=t[i][2];
			index=i;
		}
	}
	return index;
}

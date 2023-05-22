#include<stdio.h>
void printp(int first,int second,int size)
{
	int i,j;
	static int c=1;
	for (i=1;i<=size;i++)
	{
		for (j=1;j<=size;j++)
		{
			printf("%c",first);
		}
		printf("|");
		for(j=1;j<=size;j++)
		{
			printf("%c",second);
		}
		printf("\n");
	}
	if(c<size)
	{
		c++;
		for(i=1;i<=size;i++)
		{
			printf("_");
		}
		printf("+");
		for(i=1;i<=size;i++)
		{
			printf("_");
		}
		printf("\n");
		printp(second,first,size);
		
	}
	
}
main()
{
	int num;
	printf("Enter Number : ");
	scanf("%d",&num);
	
	printp(' ','*',num);
	
}

#include<stdio.h>
#include<stdlib.h>

void Insert(char T[])
{
	int i;
	printf("Index no. Char \n================\n");
	for(i=0;i<=14;i++)
	{
		printf("%d\t  ",i);
		fflush(stdin);
		scanf("%c",&T[i]);
	}
}

void InOrder()
{
	
}

main()
{
	char T[15];
	Insert(T);
}

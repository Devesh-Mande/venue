#include<stdio.h>
#define max 10
void printa(int t[],int sz)
{
	int i;
	for(i=0;i<sz;i++)
	{
		printf("%d  ",t[i]);
	}
}

main()
{
	int a1[max],a2[max];
	int i,j,s,ind;
	
	for(i=0;i<max;i++)
	{
		scanf("%d",&a1[i]);
	}
	
	printf("\nArray 1 :- ");
	printa(a1,max);
	
	for(i=max-1;i>=0;i--)
	{
		s=a1[0];
		ind=0;
		for(j=1;j<=i;j++)
		{
			if(a1[j]<s)
			{
				s=a1[j];
				ind=j;
			}
		}
		a2[max-i-1]=s;
		for(j=ind;j<i;j++)
		{
			a1[j]=a1[j+1];
		}
		printf("\n\n\nStep : %d\n=========\n",max-i);
		printf("\nArray 1 :- ");
		printa(a1,i);
		printf("\nArray 2 :- ");
		printa(a2,max-i);
	}
	
	printf("\n\n\n*****Printing Sorted Array*****\n\n");
	printa(a2,max);
	printf("\n\n\n");
}

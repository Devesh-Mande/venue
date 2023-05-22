#include<stdio.h>

main()
{
	int i,j,k,l;
	j=3;
	k=3;
	for (i=1;i<=4;i++)
	{
		for(l=1;l<=5;l++)
		{
			if(l<j||l>k)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			
		}
		if(i%2==0){
		
		printf("\n");
		
		j--;
		k++;
	}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=11-i;j++)
		{
			if(j<i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
	
}

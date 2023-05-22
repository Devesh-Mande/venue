#include<stdio.h>
main()
{
	int a[100],ele,i,j,sz,ind,temp;
	
	printf("Enter Size of Array : ");
	scanf("%d",&sz);
	
	printf("Enter Elements in Array : \n");
	for(i=0;i<sz;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<sz-1;i++)
	{
		ind=i;
		for(j=i+1;j<sz;j++)
		{
			if(a[i]>a[j])
			{
				ind=j;
			}
		}
		temp=a[i];
		a[i]=a[ind];
		a[ind]=temp;
	}
	
	printf("Sorted Array : \n");
	for(i=0;i<sz;i++)
	{
		printf("%d\t",a[i]);
	}
	
}

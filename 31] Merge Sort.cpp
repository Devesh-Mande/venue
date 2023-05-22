#include<stdio.h>
#define max 10

void InsertionSort(int st,int end,int t[])
{
	int temp;
	int i,j;
	for(i=st+1;i<=end;i++)
	{
		temp=t[i];
		for(j=i-1; j>=st && temp<t[j] ;j--)
		{
			t[j+1]=t[j];
		}
		t[j+1]=temp;
	}
}

void Msort(int st,int end,int t[])
{
	
	int mid=(st+end)/2;
	if(end-st>0)
	{
		Msort(st,mid,t);
		InsertionSort(st,end,t);
		Msort(mid+1,end,t);	
	}
}

main()
{
	int arr[max];
	int i;
	
	for(i=0;i<max;i++)
	{
		scanf("%d",&arr[i]);
	}
	Msort(0,max-1,arr);
	printf("\n\nSorted Array :- ");
	for(i=0;i<max;i++)
	{
		printf("%d ",arr[i]);
	}
}

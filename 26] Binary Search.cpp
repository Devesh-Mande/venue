#include<stdio.h>

int search(int ele,int st,int end,int t[])
{
	int mid_i=st+(end-st)/2;
	int mid_e=t[mid_i];
	int flag;
	if(mid_e==ele)
	{
		return mid_i;
	}
	else if( st==end || st>end )
	{
		return -1;	
	}
	else if(ele>mid_e)
	{
		return search(ele,mid_i+1,end,t);
	}
	else if(ele<mid_e)
	{
		return search(ele,st,mid_i-1,t);
	}
	
	
}
int main()
{
	int a[25],i,ele;

	
	for(i=0;i<25;i++)
	{
		a[i]=i;
	}
	a[18]=17;
	printf("Enter ele : ");
	scanf("%d",&ele);
	
	ele=search(ele,0,24,a);
	
	
		printf("%d",ele);
	
}

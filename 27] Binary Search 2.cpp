#include<stdio.h>
struct bin
{
	int s;
	int e;
};
bin search(int ele,int st,int end,int t[])
{
	int mid_i=st+(end-st)/2;
	int mid_e=t[mid_i];
	int flag;
	if(end-st>=5)
	{
		bin t;
		t.s=st;
		t.e=end;
		return t;
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
	a[3]=2;
	a[14]=13;
	printf("Enter ele : ");
	scanf("%d",&ele);
	
	bin o=search(ele,0,24,a);
	
	for(i=o.s;i<=o.e;i++)
	{
		if(ele==a[i])
		{
			break;
		}
	}
	if(i>o.e)
	{
		printf("Not found");
	}
	else 
	{
		printf("Found");
	}
}

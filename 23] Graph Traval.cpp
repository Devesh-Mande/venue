#include<stdio.h>
#include<stdlib.h>
int a[6][6]={  // 0  1  2  3  4  5
			   // A  B  C  D  E  F
	    /*A*/   { 0,10, 0, 0, 0,30},
		/*B*/	{10, 0, 0, 0,20, 0},
		/*C*/	{ 0, 0, 0,50, 0,40},
		/*D*/	{ 0, 0,50, 0, 0, 0},
		/*E*/	{ 0,20, 0, 0, 0, 0},
		/*F*/	{30, 0,40, 0, 0, 0}
			};
	
int t(int start,int end,int sz,int l,int sum )
{
	if(start==end)
	{
		printf("sum=%d",sum);
		
	}
	else
	{
		int i;
		for(i=0;i<sz;i++)
		{
			if(a[start][i]!=0 && i!=l)
			{
				t(i,end,sz,start,sum+a[start][i]);
			}
		}
	}
}	
main()
{
	t(4,3,6,-1,0);
}

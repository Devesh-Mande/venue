#include<iostream>
using namespace std;
main()
{
	int i,j,k,num;
	cin>>num;
	int a[num][num];
	k=num-1;
	int sq=num*num;
	
	for(j=0;j<num;j++)
	{
		for(i=j;i<=k;i++)
		{
			a[j][i]=sq--;
		}
		for(i=j+1;i<=k;i++)
		{
			a[i][k]=sq--;
		}
		for(i=k-1;i>=j;i--)
		{
			a[k][i]=sq--;
		}
		for(i=k-1;i>j;i--)
		{
			a[i][j]=sq--;
		}
		k--;
	}
	
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("%4d",a[i][j]);
		}
		cout<<endl;
	}
	
	
}

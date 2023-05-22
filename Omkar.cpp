#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	int i,A[T],N[T];
	int ans,temp;
	for(i=0;i<T;i++)
	{
		cin>>A[i]>>N[i];
	}
	
	for(i=0;i<T;i++)
	{
		
		ans = (1000000007%(long)(pow(A[i],(N[i]/2))));
		cout<<ans<<cout;
	}
}

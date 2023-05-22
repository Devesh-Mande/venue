#include<iostream>
using namespace std;
main()
{
	int hr,min;
	float a1,a2,a3,f;
	
	cin>>hr;
	cin>>min;
	
	a1=(hr*360)/12;
	a2=(min*30)/60;
	a1+=a2;
	a3=(min*360)/60;
	
	f=a3-a1;
	
	if(f<0)
	{
		f=-1*f;
		
	}
	
	if(f>180)
	{
		f=360-180;
	}
	cout<<f;
}

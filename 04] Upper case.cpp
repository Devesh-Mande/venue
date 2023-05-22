#include<iostream>
using namespace std;
class Matrix
{
	int m[3][3];
    int flag;
	public:
		int accept_values()
		{
			int i,j,k,num;
			flag=0;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<"Enter element : ";
					cin>>num;
					m[i][j]=num;
				}
				for(k=0;k<i&&flag==0;k++)
				{
					if(m[i][k]==0)
					{
						flag=0;
					}
					else
					{
						flag=1;
						break;
					}
				}
			}
			return flag;
		}
};
main()
{
	int num;
	Matrix o;
	num=o.accept_values();
	if (num==0)
	{
		cout<<"Upparcase matrix";
	}
	else
	{
		cout<<"non uppercase";
	}
}

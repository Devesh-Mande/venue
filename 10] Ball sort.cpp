#include<iostream>
using namespace std;
class Stack
{
	int stack[4],top;
	
	public:
	Stack()
	{
		top=-1;
	}
	int push(int ele)
	{
		int i;
		if(top==3)
		{
			cout<<"\nStack Overflow \n";
			return 0;
		}
		else
		{
			stack[++top]=ele;
			return 1;
		}
	}
	int pop()
	{
		int temp;
		if(top==-1)
		{
			cout<<"\nStack Underflow\n";
		}
		else
		{
			temp= stack [top];
			top--;
			return temp;
		}
		
	}
	int get_top()
	{
		return top;
	}
	int get_top_ele(int i)
	{
		int temp;
		temp=stack[i];
		return temp;
	}
};
void display_array(Stack o[])
{
	int i,j;
	for(j=3;j>=0;j--)
	{
		for(i=0;i<=4;i++)
		{
			if(j>o[i].get_top())
			{
				cout<<" |   |\t";
			}
			else
			{
				cout<<" | "<<o[i].get_top_ele(j)<<" |\t";
			}
		}
		cout<<"\n";
	}
	for(i=0;i<=4;i++)
	{
		cout<<"Stack-"<<i+1<<"\t";
	}
	cout<<endl;
}

void accept_array(Stack o[])
{
	int i,j,k,flag,ele,count[4]={0};	
	for(i=0;i<=3;i++)
	{
		for(j=1;j<=4;j++)
		{
			xyz:
			cout<<"Push Element at Stack "<<i+1<<": ";
			cin>>ele;
			if(ele<1||ele>4)
			{
				cout<<"\nInvalid input \n";
				goto xyz;
			}
			else
			{
				flag=0;
				for(k=1;k<=4;k++)
				{
					if(ele==k&&count[k-1]<4)
					{
						count[k-1]++;
						flag=1;
					}
				}
				if(flag==0)
				{
					cout<<"\nInput Exceeds\n";
					goto xyz;
				}
			}
			o[i].push(ele);
			cout<<endl;
		}
		cout<<"\n==================================\n\n";
	}
}
int winner(Stack o[])
{
	int i,j;
	for(i=0;i<=4;i++)
	{
		if(o[i].get_top()!=3)
		{
			if(o[i].get_top()!=-1)
			{
				return 0;
			}
		}
		for(j=0;j<o[i].get_top();j++)
		{
			if(o[i].get_top_ele(j)==o[i].get_top_ele(j+1))
			{
					
			}
			else 
			{
				return 0;
			}
		}
	}
	return 1; 
}
main()
{
	Stack o[5];
	int bol,ch1,ch2,ele;
	
    accept_array(o);
	
	display_array(o);

	while(1)
	{
		bol=winner(o);
		if(bol==1)
		{
			cout<<"\n\nYou Win\n\n";
			break;
		}
		abc:
		cout<<"\n====================================\n\nFrom - ";
		cin>>ch1;
		if(ch1>5&&ch1>1)
		{
			cout<<"invalid input";
			goto abc;
		}
		cout<<"\nWhere - ";
		cin>>ch2;
		
		cout<<"\n\n=====================================\n";
		
		ele=o[ch1-1].pop();
		bol=o[ch2-1].push(ele);
		if(bol==0)
		{
			o[ch1-1].push(ele);
		}
		cout<<endl;
		display_array(o);
	}
}

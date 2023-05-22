#include<iostream>
#include<stdio.h>
using namespace std;
class Stack
{
	char s[100];
	static int top;
	public:
		void push(char ch)
		{
			if(top==100)
			{
				cout<<"Stack overflow\n";
			}
			else
			{
				s[++top]=ch;
			}
		}
		void pop()
		{
			top--;
		}
		void display()
		{
			int i;
			for(i=0;i<=top;i++)
			{
				cout<<s[i]<<" ";
			}
		}
		int check_brakets(char exp[])
		{
			int i=0;
			while (exp[i]!='\0')
			{
				if(exp[i]=='('||exp[i]==')'||exp[i]=='{'||exp[i]=='}'||exp[i]=='['||exp[i]==']')
				{
					push(exp[i]);
				}
				if( (i>0) && ( (s[top]==')'&&s[(top-1)]=='(') || (s[top]=='}'&&s[(top-1)]=='{') || (s[top]==']'&&s[(top-1)]=='[') ) )
				{
					pop();
					pop();
				}
				i++;
			}
			if(top==-1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int check_operators(char exp[])
		{
			int net,i=0,c1=0,c2=0;
			while(exp[i]!='\0')
			{
				if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'||exp[i]=='^')
				{
					c1++;
				}
				else if(exp[i]>=97&&exp[i]<=122)
				{
					c2++;
				}
				i++;
			}
			net=c2-c1;
			if(net==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};int Stack::top=-1;
main()
{
	Stack o;
	char str[100];
	int yon1,yon2;
	cout<<"Enter String\n";
	gets(str);
	
	yon1=o.check_brakets(str);
	if(yon1==1)
	{
		yon2=o.check_operators(str);
	}
	if(yon1==1&&yon2==1)
	{
		cout<<"\n\n=================\nValid Expression";
	}
	else
	{
		cout<<"\n\n===================\nInvalid Expression";
	}
}

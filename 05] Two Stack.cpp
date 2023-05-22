#include<iostream>
#include<stdlib.h>
using namespace std;
class TwoStack
{
	int stack[10];
	static int top2,top1;//two top for two stacks
	public:
		void push()//to push ele in primary stack
		{
			int ele;
			if(top1==9)
			{
				cout<<"Stack overflow\n";
			}
			else
			{
				cout<<"Enter element to PUSH : ";
				cin>>ele;
				stack[--top1]=ele;
			}
		}
		void poppr()//pop element from primary stack
		{
			int ele;
			if(top1==5)
			{
				cout<<"Stack underflow\n";
			}
			else
			{
				ele=stack[top1];
				top1++;
				stack[++top2]=ele;//pushing poped element from primery stack in secondery stack
			}
		}
		void popse()//pop element from secondery 
		{
			int ele,num;
			if(top2==4)
			{
				cout<<"Stack underflow\n";
			}
			else
			{
				xyz:
				cout<<"\n1-Delete";
				cout<<"\n2-Restore";
				cin>>num;
				if(!(num==1||num==2))//checking condition that given num is must be 1 or 2
				{
					cout<<"\n\nInvalid Input Try again";
					goto xyz;//we can also use while loop her 
				}
				else if(num==2)//restoring ele
				{
					ele=stack[top2];
					top2--;
					stack[--top1]=ele;//pushing ele in primery stack forn secondery
				}
				else//removing ele
				{
				top2--;
				}
			}

		}		
		void display()//to display ele
		{
			int i;
			for (i=0;i<10;i++)
			{
				if(i==5)//to divide stack in 2 parts
				{
					cout<<"______\n\n";
				}
				if(i<top1)
				{
					cout<<"  _\n";
				}
				else if(i>top2)
				{
					cout<<"  _\n";
				}
				else
				{
					cout<<"  "<<stack[i]<<endl;
				}				
			}
		}
};
int TwoStack::top1=5;//inisalised top1 and top2
int TwoStack::top2=4;
main()
{
	int ch,ch1;
	TwoStack o;
	while(1)//infinte while loop 
	{
		cout<<"\n\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n";//providing options
		cout<<"Provide Your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:{
				o.push();//push operations
				break;
			}
			case 2:{
				abc:
				cout<<"\n1-POP from Primery\n2-POP from secondary\nProvide Your choice : ";//options for 2 stacks
				cin>>ch1;
				switch(ch1)
				{
					case 1:{
						o.poppr();
						break;
					}
					case 2:{
						o.popse();
						break;
					}
					default :{
						cout<<"\n Invalid choice";
						goto abc;
						break;
					}
				}
				break;
			}
			case 3:{
				o.display();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			default :{
				cout<<"\nInvalid choice";
				break;
			}
		}
	}
}

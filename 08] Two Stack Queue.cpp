#include<iostream>
using namespace std;

class QueueUsingTwoStack
{
	int s1[10],s2[10];
	int top1,top2,t1,t2;
	
	void Pre_Insert()
	{
		while(top2!=-1)
		{
		s1[++top1]=s2[top2--];
		}
	}
	void Pre_Remove()
	{
		while(top1!=-1)
		{
			s2[++top2]=s1[top1--];
		}
	}	
	public:
		QueueUsingTwoStack()
		{
			top1=-1;
			top2=-1;
		}
		void Insert()
		{
			Pre_Insert();
			if(top1==9)
			{
				cout<<"\nNo Space to Insert \n";
			}
			else
			{
				cout<<"\nEnter Element to Insert : ";
				cin>>t1;
				s1[++top1]=t1;
			}
		}
		void Remove()
		{
			Pre_Remove();
			if(top2==-1)
			{
				cout<<"\nQueue is Empty\n";
			}
			else
			{
				cout<<"\nElement : "<<s2[top2]<<"is removed\n";
				top2--;
			}
		}
		void display()
		{
			int i;
			if(top1==-1&&top2==-1)
			{
				cout<<"\nNothing to display \n";
			}
			else
			{	
				Pre_Remove();			
				i=0;
				while(i!=top2+1)
				{
					cout<<s2[i++]<<"\t";
				}
			}
		}
};
main()
{
	QueueUsingTwoStack o;
	int ch;
	
	do
	{
		cout<<"\n1-Insert";
		cout<<"\n2-Remove";
		cout<<"\n3-Next to Remove List";
		cout<<"\n4-Exit";
		cout<<"\nProvide Your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:{
				o.Insert();
				break;
			}
			case 2:{
				o.Remove();
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
				cout<<"\nInvalid Choice\n";
				break;
			}
		}
	}while(1);
}

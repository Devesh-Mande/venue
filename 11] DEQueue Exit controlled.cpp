#include<iostream>
using namespace std;
class DEQueue
{
	int q[10];
	int F,R;
	
	public:
		DEQueue()
		{
			F=0;
			R=-1;
		}
		void insert()
		{
			int ele,i,ch;
			if(R==9)
			{
				cout<<"\nQueue Overflow";
			}	
			else
			{
				cout<<"\n1-Insert from Front";
		    	cout<<"\n2-Insert from Rear";
				cout<<"\nProvide your choice : ";
				cin>>ch;
		
				switch(ch)
				{
					case 1:{
						for(i=R;i>=F;i--)
						{
							q[i+1]=q[i];
						}
						R++;
						cout<<"\nEnter Element to insert : ";
						cin>>ele;
						q[F]=ele;
						cout<<"\nElement : "<<ele<<" Inserted\n";
					break;
					}
					case 2:{
						cout<<"\nEnter Element to insert : ";
						cin>>ele;
						q[++R]=ele;
						cout<<"\nElement : "<<ele<<" Inserted\n";	
						break;
					}
				}	
			}
		}
		void remove()
		{
			if(F==R+1)
			{
				cout<<"\nQueue Underflow\n";
			}
			else
			{
				cout<<"\nElement : "<<q[F]<<" Removed\n";
				F++;
			}
		}
		void display()
		{
			int i;
			cout<<"\nElements in Queue are :-\n";
			for(i=R;i>=F;i--)
			{
				cout<<q[i]<<"\t";
			}
			cout<<"\n";
		}
};
main()
{
	DEQueue o;
	int ch;
	
	do{
		cout<<"\n1-INSERT";
		cout<<"\n2-REMOVE";
		cout<<"\n3-DISPLAY";
		cout<<"\n4-Exit";
		cout<<"\nProvide Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:{
				o.insert();
				break;
			}
			case 2:{
				o.remove();
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
		}
	}while(1);
}

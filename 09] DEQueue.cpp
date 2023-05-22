#include<iostream>
using namespace std;
class DEQueue
{
	int F,R,ele;
	int deQ[10];
	
	public:
		DEQueue()
		{
			F=5;
			R=4;
		}
		void insert()
		{
			int ch;
			cout<<"\n1-Insert from Front";
			cout<<"\n2-Insert from Rear";
			cout<<"\n3-Exit to Main Menue";
			cout<<"\nProvide your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1:{
					if(F==0)
					{
						cout<<"\nCann't Insert from Front ";
					}
					else
					{
						cout<<"Enter Element to Insert : ";
						cin>>ele;
						deQ[--F]=ele;
					}
					break;
				}
				case 2:{
					if(R==9)
					{
						cout<<"\nCann't Insert from Rear ";
					}
					else
					{
						cout<<"Enter Element to Insert : ";
						cin>>ele;
						deQ[++R]=ele;
					}
					break;
				}
				case 3:{
					break;
				}
			}
			
		}
		void remove()
		{
			if(F==R+1)
			{
				cout<<"\nQueue Underflow ";
			}
			else
			{
			int ch;
			cout<<"\n1-Remove from Front";
			cout<<"\n2-Remove from Rear";
			cout<<"\n3-Exit to Main Menue";
			cout<<"\nProvide your choice : ";
			cin>>ch;
			
			switch(ch)
			{
				case 1:{
					cout<<"\n"<<deQ[F]<<" is Removed\n";
					F++;
					break;
				}
				case 2:{
					cout<<"\n"<<deQ[R]<<" is Removed\n";
					R--;
					break;
				}
				case 3:{
					break;
				}
			}
			}
		}
		void display()
		{
			int i;
			if(F==R+1)
			{
				cout<<"\nEmpty Queue Nothing to Display \n";
			}
			else
			{
				for (i=R;i>=F;i--)
				{
					cout<<deQ[i]<<"\t";
				}
			}
		}
};
main()
{
	DEQueue o;
	int ch;
	
	do
	{
		cout<<"\n1-Insert";
		cout<<"\n2-Remove";
		cout<<"\n3-Display";
		cout<<"\n4-Exit";
		
		cout<<"\nProvide Your choice : ";
		cin>>ch;
		
		switch (ch)
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

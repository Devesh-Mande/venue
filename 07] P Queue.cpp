#include<iostream>
using namespace std;
struct Type
{
	char ele;
	int p;
};
class PQueue
{
	Type queue[10];
	int F,R;
	
	public:
		void fake()
		{
			F=0;
			R=-1;
		}
		void INSERT()
		{
			int i,t1;
			char t2;
			if(R==9)
			{
				cout<<"\nQueue is Overflow\n";
			}
			else
			{
				cout<<"\nEnter Character : ";
				cin>>queue[R+1].ele;
				cout<<"\nEnter Priority : ";
				cin>>queue[R+1].p;
				R++;
				for(i=R;i>0;i--)
				{
					if(queue[i].p>queue[i-1].p)//swaping logic but ganda hai 
					{
						t1=queue[i].p;
						queue[i].p=queue[i-1].p;
						queue[i-1].p=t1;
						
						t2=queue[i].ele;
						queue[i].ele=queue[i-1].ele;
						queue[i-1].ele=t2;
					}
				}
			}
		}
		void REMOVE ()
		{
			if(F==R+1)
			{
				cout<<"\nQueue is Undeflow";
				
			}
			else
			{
				cout<<"\nCharacter : "<<queue[F].ele<<"\nPriority : "<<queue[F].p<<"\n===================\nis Removed\n";
				F++;
			}
		}
		void DISPLAY()
		{
			int i;
			for(i=R;i>=F;i--)
			{
				cout<<queue[i].ele<<"\t";
			}
			cout<<"\n";
			for(i=R;i>=F;i--)
			{
				cout<<queue[i].p<<"\t";
			}	
			cout<<endl;
		}		
};
main()
{
	PQueue o;
	o.fake();
	int ch;
	do
	{
		cout<<"1-Insert\n2-Remove\n3-Display\n4-Exit\n";
		cout<<"Provide your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :{
				o.INSERT();
				break;
			}
			case 2:{
				o.REMOVE();
				break;
			}
			case 3:{
				o.DISPLAY();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}while(1);
}

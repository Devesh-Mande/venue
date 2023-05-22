#include<iostream>
using namespace std;
class CQueue
{
	int queue[10];
	int F,R,count;
	public:
		void fake()
		{
			F=0;
			R=-1;
			count=0;
		}
		void INSERT()
		{
			int ele;
			if(F==R+1&&count%2==1)
			{
				cout<<"\nQueue is Full";
			}
			else
			{
				cout<<"Enter element to INSERT : ";
				cin>>ele;
				queue[R+1]=ele;
				R++;
				if(R==9)
				{	
					R=-1;
					count++;
				}
			}
		}
		void REMOVE()
		{
			if((F==R+1)&&(count%2==0))
			{
				cout<<"\nQueue Underflow\n";
			}
			else
			{
				cout<<queue[F]<<" is REMOVED\n";
				F++;
				if(F==10)
				{	
					F=0;
					count++;
				}
			}
		}
		void Display()
		{
			int i;
            if(F==R+1&&count%2==0)
            {
            	cout<<"\nQueue is Underflow nothing to display\n";
			}
			else
			{
				i=R;
				do
				{
					if(i==-1)
					{
						i=9;
					}
					cout<<queue[i]<<"\t";
					i--;
				}while(i!=F-1);
			}
			cout<<"\n";
		}	
};
main()
{
	int ch;
	CQueue o;
	o.fake();
	do
	{
		cout<<"1-INSERT\n";
		cout<<"2-REMOVE\n";
		cout<<"3-DISPLAY\n";
		cout<<"4-EXIT";
		
		cout<<"Provide Your Choice : "; 
		cin>>ch;
		switch(ch)
		{
			case 1:{
				o.INSERT();
				break;
			}
			case 2:{
				o.REMOVE();
				break;
			}
			case 3:{
				o.Display();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}while(1);
}


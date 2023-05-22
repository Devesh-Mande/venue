#include<iostream>
#include<stdio.h>
using namespace std;
class TicTack
{
	char xo[9];
	public:
		void fake()
		{
			int i,j='1';
			cout<<"Indexing for Game\n\n";
			for (i=0;i<9;i++,j++)
			{
				
				xo[i]=j;
                cout<<" "<<xo[i]<<" ";
                if(i<8&&i%3==2)
                {
                	cout<<"\n---|---|---\n";
				}
				else if(i<8)
				{
					cout<<"|";
				}
			}
			cout<<endl;
		}
		int accept_X(int ch)
		{
			int i;	
			i=ch-1;
			if(xo[i]=='X'||xo[i]=='O')
			{
				return 0;
			}
			else
			xo[i]='X';
			cout<<"\n=====================================\n";
			display();
			cout<<"=====================================\n";
			return 1;			
		}
		int accept_O(int ch)
		{
			int i;			
			i=ch-1;
			if(xo[i]=='X'||xo[i]=='O')
			{
				return 0;
			}
			else			
			xo[i]='O';
			cout<<"\n=====================================\n";
			display();
			cout<<"=====================================\n";
			return 1;			
		}
		int winner()
		{
			if(xo[0]=='X'&&xo[1]=='X'&&xo[2]=='X')
				return 1;
			else if(xo[0]=='X'&&xo[3]=='X'&&xo[6]=='X')
				return 1;				
			else if(xo[3]=='X'&&xo[4]=='X'&&xo[5]=='X')
				return 1;		
			else if(xo[6]=='X'&&xo[7]=='X'&&xo[8]=='X')
				return 1;	
			else if(xo[1]=='X'&&xo[4]=='X'&&xo[7]=='X')
				return 1;
			else if(xo[2]=='X'&&xo[5]=='X'&&xo[8]=='X')
				return 1;				
			else if(xo[0]=='X'&&xo[4]=='X'&&xo[8]=='X')
				return 1;		
			else if(xo[2]=='X'&&xo[4]=='X'&&xo[6]=='X')
				return 1;
			else if(xo[0]=='O'&&xo[1]=='O'&&xo[2]=='O')
				return 2;
			else if(xo[0]=='O'&&xo[3]=='O'&&xo[6]=='O')
				return 2;				
			else if(xo[3]=='O'&&xo[4]=='O'&&xo[5]=='O')
				return 2;		
			else if(xo[6]=='O'&&xo[7]=='O'&&xo[8]=='O')
				return 2;	
			else if(xo[1]=='O'&&xo[4]=='O'&&xo[7]=='O')
				return 2;
			else if(xo[2]=='O'&&xo[5]=='O'&&xo[8]=='O')
				return 2;				
			else if(xo[0]=='O'&&xo[4]=='O'&&xo[8]=='O')
				return 2;		
			else if(xo[2]=='O'&&xo[4]=='O'&&xo[6]=='O')
				return 2;
				else
				return 0;										
		}
		void display()
		{
			int i;
			cout<<"\n";
			for(i=0;i<9;i++)
			{
				if((xo[i]=='O'||xo[i]=='X'))
				{
					cout<<" "<<xo[i]<<" ";
				}
				else
				{
					cout<<"   ";
				}
				if(i<8&&i%3==2)
				{
					cout<<"\n---|---|---\n";
				}
				else
				{
					cout<<"|";
				}
			}
			cout<<"\b \n\n";
		}
};
main()
{
	TicTack o;
	int i=0,w,e;
	int c;
	o.fake();
	while(1)
	{
		xyz:
		fflush(stdin);
		cout<<"\nEnter Number for X : ";
		cin>>c;
		e=o.accept_X(c);
		if(e==0)
		{
			cout<<"Index already have a value enter Proper value\n";
			goto xyz;
		}
		i++;
		
		w=o.winner();
		if(i>=5&&w==1)
		{
			cout<<"\nWinner is X";
			break;
		}
		else if(i>=5&&w==2)
		{
			cout<<"\nWinner is O";
			break;
		}					
		
		abc:
		fflush(stdin);
		cout<<"\nEnter Number for O : ";
		cin>>c;
		e=o.accept_O(c);
		if(e==0)
		{
			cout<<"Index already have a value enter Proper value\n";
			goto abc;
		}
	
		i++;
		
		w=o.winner();
		if(i>=5&&w==1)
		{
			cout<<"\nWinner is X";
			break;
		}
		else if(i>=5&&w==2)
		{
			cout<<"\nWinner is O";
			break;
		}	
		if(i==9)
		{
			cout<<"\nGAME is draw";
			break;
		}
	}
}

#include<iostream>
#include<stdio.h>
using namespace std;
class TicTack
{
	char xo[3][3];
	public:
		void fake()
		{
			int i,j,k='1';
			cout<<"Index for GAME:\n\n";
			for (i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					xo[i][j]=k;
					cout<<"  "<<xo[i][j]<<"  ";
					if(j<2)
					{
						cout<<"|";
					}
					k++;
				}
				if(i<2)
				cout<<"\n --- | --- | --- \n";
			}
			cout<<endl;
		}
		int accept_X(int ch)
		{
			if(ch<1||ch>9)
			{
				return 0;
			}
			int i,j;
			i=ch/3;
			j=(ch%3)-1;
			if(xo[i][j]=='X'||xo[i][j]=='O')
			{
				return 0;
			}			
			xo[i][j]='X';
			cout<<"\n=====================================\n";
			display();
			cout<<"=====================================\n";	
			return 1;		
		}
		int accept_O(int ch)
		{
			if(ch<1||ch>9)
			{
				return 0;
			}			
			int i,j;
			i=ch/3;
			j=ch%3;
			j--;
			if(xo[i][j]=='X'||xo[i][j]=='O')
			{
				return 0;
			}			
			xo[i][j]='O';
			cout<<"\n=====================================\n";
			display();
			cout<<"=====================================\n";		
			return 1;	
		}
		char winner()
		{
			int i,j,k=0;
			for(i=0;i<3;i++)
			{
				if(xo[i][0]==xo[i][1]&&xo[i][1]==xo[i][2])
				{
					k=1;
					return xo[i][0];
				}
				else if(xo[0][i]==xo[1][i]&&xo[1][i]==xo[2][i])
				{
					k=1;
					return xo[i][0];
				}
			}	
			if(xo[0][0]==xo[1][1]&&xo[1][1]==xo[2][2])
			{
				return xo[0][0];
			}			
			else if(xo[0][2]==xo[1][1]&&xo[1][1]==xo[2][0])
			{
				return xo[1][1];
			}
			else if(k==0)
			{
				return '\0';
			}
		}
		void display()
		{
			int i,j,k;
			cout<<"\n";
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(xo[i][j]=='X'||xo[i][j]=='O')
					{
						cout<<"  "<<xo[i][j]<<"  ";
					}
					else
					{
						cout<<"     ";
					}
					if(j<2)
					{
						cout<<"|";
					}
				}
				if(i<2)
				cout<<"\n --- | --- | --- \n";
				else
				cout<<"\n";
			}
			
		}
};
main()
{
	TicTack o;
	int i=0;
	int c,e;
	char w;
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
			cout<<"Invalid Index value\n";
			goto xyz;
		}
		
		i++;
		
		w=o.winner();
		if(i>=5&&w=='X')
		{
			cout<<"\nWinner is X";
			break;
		}
		else if(i>=5&&w=='O')
		{
			cout<<"\nWinner is O";
			break;
		}	
		if(i==9)
		{
			cout<<"\n\nGame DRAW";
			break;
		}				
		abc:
		fflush(stdin);
		cout<<"\nEnter Number for O : ";
		cin>>c;
		e=o.accept_O(c);	
		if(e==0)
		{
			cout<<"Invalid Index value\n";
			goto abc;
		}		

		i++;
		
		
		w=o.winner();
		if(i>=5&&w=='X')
		{
			cout<<"\nWinner is X";
			break;
		}
		else if(i>=5&&w=='O')
		{
			cout<<"\nWinner is O";
			break;
		}	
	}
}

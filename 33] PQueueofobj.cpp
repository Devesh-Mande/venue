#include<iostream>
#include<string>
using namespace std;

class Student
{
    public :
    //string name;
    int roll;
    double avg;
    char g;
    
    void operator = (Student o)
    {
        roll=o.roll;
        avg=o.avg;
        g=o.g;
    }
    
};
Student o[10];
int F=0;
int R=-1;
void insert()
{
	Student nn;
    cout<<"\n==================\nEnter Details of Student : ";
    //fflush(stdin);
    //cout<<"\nName : ";
    //getline(cin,nn->name);
    cout<<"\nRoll : ";
    cin>>nn.roll;
    cout<<"Average : ";
    cin>>nn.avg;
    fflush(stdin);
    cout<<"Gender : ";
    cin>>nn.g;
    
    if(R==9)
    {
    	cout<<"Queue overflow ";
    }
    else
    {
        o[++R]=nn;
    }
}
void display(Student os)
{
	cout<<"\n====================\nNow at top :\n\nRoll : "<<os.roll<<"\nAverage : "<<os.avg<<"\nGender : "<<os.g<<"\n=====================\n";
}

void Remove()
{
	Student max,temp;
	int i;
    if(F==R+1)
    {
        cout<<"Queue Underflow";
    }
	else
	{
		cout<<1;
		max=o[F];
		for(i=F+1;i<=R;i++)
		{
			cout<<2;
			if(max.avg==o[i].avg)
			{
				cout<<3;
				if(max.g==o[i].g)
				{
					cout<<4;
					if(o[i].roll<max.roll)
					{
						cout<<5;
						temp=max;
						max=o[i];
						o[i]=temp;
					}
				}
				else
				{
					cout<<6;
					if(o[i].g=='F')
					{
						cout<<7;
						temp=max;
						max=o[i];
						o[i]=temp;
					}			
				}
			}
			else if(max.avg<o[i].avg)
			{
						temp=max;
						max=o[i];
						o[i]=temp;
			}
		}
		o[F]=max;
		display(o[F]);
		F++;
	}        
}
    
main()
{
    int ch;
    
    do 
    {
        cout<<"\n1 - Insert "<<endl;
        cout<<"2 - Remove "<<endl;
        cout<<"3 - Exit "<<endl;
        cout<<"Provide Your Choice : ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            insert();
            break;
            case 2:
            Remove();
            break;
            case 3:
            exit(0);
        }
        
    }while(1);
}

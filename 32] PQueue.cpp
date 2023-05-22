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
    Student* next;
    
    void assign(Student* o)
    {
        roll=o->roll;
        avg=o->avg;
        g=o->g;
    }
    
};
Student* F;
Student* R;

void insert()
{
    Student *nn;
    nn = new Student;
    cout<<"\n==================\nEnter Details of Student : ";
    //fflush(stdin);
    //cout<<"\nName : ";
    //getline(cin,nn->name);
    cout<<"\nRoll : ";
    cin>>nn->roll;
    cout<<"\nAverage : ";
    cin>>nn->avg;
    fflush(stdin);
    cout<<"\nGender : ";
    cin>>nn->g;
    nn->next=NULL;
    if(R==NULL)
    {
        F=nn;
        R=nn;
    }
    else
    {
        R->next=nn;
    }
}
void display()
{
    Student *temp;
    temp=F;
    while(temp!=NULL)
    {
        cout<<temp->roll<<temp->avg<<temp->g;
        temp=temp->next;
    }
}

void Remove()
{
    Student *t1,*temp,*re;
    if(F==NULL)
    {
        cout<<"Queue Underflow";
    }
    else
    {
        
        re=F;
        t1=F->next;
        while(t1!=NULL)
        {
        	cout<<1;
            if(t1->avg>=re->avg)
            {
            	cout<<2;
                if(t1->avg==re->avg)
                {
                	cout<<3;
                    if(t1->g==re->g)
                    {
                    	cout<<4;
                        if(t1->roll<re->roll)
                        {
                            temp->assign(t1);
                            t1->assign(re);
                            re->assign(temp);
                        }
                    }
                    else
                    {
                    	cout<<5;
                        if(t1->g=='F')
                        {
                        	cout<<6;
                            temp->assign(t1);
                            t1->assign(re);
                            re->assign(temp);
                        }
                    }
                }
                else
                {
                	cout<< 7;
                    temp->assign(t1);
                    t1->assign(re);
                    re->assign(temp);
                }
            }
            t1=t1->next;
        }
        
    }
}
    
main()
{
    int ch;
    F = NULL;
    R = NULL;
    
    do 
    {
        cout<<"1 - Insert "<<endl;
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
            display();
            break;
            case 3:
            exit(0);
        }
        
    }while(1);
}

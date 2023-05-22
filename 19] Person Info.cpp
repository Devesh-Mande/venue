#include<stdio.h>
#include<stdlib.h>
struct PersonalInfo
{
	long mob;
	char name[25];
	char addhar[20];
};
struct BankInfo
{
	long ac_num;
	long bal;
	char ac_type[15];
};
struct VehicleInfo
{
	char company[15];
	char car_name[10];
	char car_num[15];
};
struct GasInfo
{
	char brand[15];
	long consumer_num;
	char type[10]; 
};
struct Node
{
	PersonalInfo *PI;
	BankInfo *BI;
	VehicleInfo *VI;
	GasInfo *GI;
	Node *next;
};

Node *first;

PersonalInfo* Assign_PI()
{
	PersonalInfo *nn;
	
	printf("\n+++++ Personal Info +++++\n");
	
	nn=(PersonalInfo*)malloc(sizeof(PersonalInfo));

	fflush(stdin);
	printf("\n->Enter Name : ");
	gets(nn->name);
	
	printf("\n->Enter Mobile num : ");
	scanf("%ld",&nn->mob);
	
	fflush(stdin);
	printf("\n->Enter Addhar num : ");
	gets(nn->addhar);
	
	
	return nn;
}
VehicleInfo* Assign_VI()
{
	VehicleInfo *nn;
	
	printf("\n+++++ VehicleInfo +++++\n");
	
	nn=(VehicleInfo*)malloc(sizeof(VehicleInfo));

	fflush(stdin);
	printf("\n->Enter Car Name : ");
	gets(nn->car_name);
	
	fflush(stdin);
	printf("\n->Enter Car num : ");
	gets(nn->car_num);
	
	fflush(stdin);
	printf("\n->Enter Company : ");
	gets(nn->company);
	
	
	return nn;
}
GasInfo* Assign_GI()
{
	GasInfo *nn;
	
	printf("\n+++++ Gas Info +++++\n");
	
	nn=(GasInfo*)malloc(sizeof(GasInfo));

	fflush(stdin);
	printf("\n->Enter Brand : ");
	gets(nn->brand);
	
	printf("\n->Enter consumer num : ");
	scanf("%ld",&nn->consumer_num);
	
	fflush(stdin);
	printf("\n->enter type : ");
	gets(nn->type);
	
	
	return nn;
}
BankInfo* Assign_BI()
{
	BankInfo *nn;
	
	printf("\n+++++ Bank Info +++++\n");
	
	nn=(BankInfo*)malloc(sizeof(BankInfo));

	printf("\n->Enter Balance : ");
	scanf("%ld",&nn->bal);
	
	printf("\n->Enter Bank ac num : ");
	scanf("%ld",&nn->ac_num);
	
	fflush(stdin);
	printf("\n->Enter Type : ");
	gets(nn->ac_type);
	
	
	return nn;
}
Node* Assign_values()
{
	Node *nn;
	nn=(Node*)malloc(sizeof(Node));

	nn->PI=Assign_PI();
	
	nn->GI=Assign_GI();
	
	nn->BI=Assign_BI();
	
	nn->VI=Assign_VI();
	
	return nn;
}
void Insert()
{
	Node *nn;
	
	nn=Assign_values();
	
	if(first==NULL)
	{
		nn->next=NULL;
		first=nn;
		printf("\n\nDATA INSERTED \n");
	}	
	else
	{
		nn->next=first;
		first=nn;
		printf("\n\nDATA INSERTED \n");
	}
}
void printGI(GasInfo *t)
{
	printf("\n+++++ Gas Info +++++\n");
	printf("\nBrand Name : %s",t->brand);
	printf("\nConsumer num : %ld",t->consumer_num);
	printf("\nType : %s",t->type);
}
void printVI(VehicleInfo *t)
{
	printf("\n+++++ Vehicle Info +++++\n");
	printf("\nCar Name : %s",t->car_name);
	printf("\nCar num : %s",t->car_num);
	printf("\nCompany : %s",t->company);
}
void printBI(BankInfo *t)
{
	printf("\n+++++ Bank Info +++++\n");
	printf("\nAc num : %ld",t->ac_num);
	printf("\nAc Type : %s",t->ac_type);
	printf("\nBalance : %ld",t->bal);
}
void printPI(PersonalInfo *t)
{
	printf("\n+++++ Personal Info +++++\n");
	printf("\nName : %s",t->name);
	printf("\nMobile num : %ld",t->mob);
	printf("\nAddhar : %s",t->addhar);
}
void printv(Node *t)
{
	
	printPI(t->PI);
	printBI(t->BI);
	printVI(t->VI);
	printGI(t->GI);
	
}
void Display()
{
	Node *t1;
	
	t1=first;
	while(t1!=NULL)
	{
		printv(t1);
		t1=t1->next;
	}
}
main()
{
	first=NULL;
	int ch;
	do
	{
		printf("\nSelect Operation\n");
		printf("1 - INSERT\n");
		printf("2 - REMOVE\n");
		printf("3 - Display\n");
		printf("4 - UPDATE\n");
		printf("5 - SEARCH\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: Insert();
				break;
			case 3: Display();
				break;
				
			/*case 2: remove_info();
				break;
			case 3: update_info();
				break;
			case 4: dispaly_info;
			*/
			
		} //end of switch-case
	}while(1);
}

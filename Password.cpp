#include<stdio.h>
#include<conio.h>
main()
{
	char p[10],ch;
	int i;
	printf("Enter Password : ");
	do
	{
		ch=getch();
		printf("*");
		if(ch!=13)
		{
			p[i]=ch;
			i++;
		}
	}while(ch!=13);
	printf("\n\n\n");
	puts(p);
}

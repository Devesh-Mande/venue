#include<stdio.h>
#include<windows.h>

main()
{
	int i,j,k;

	for(i=0;i<24;i++)//hours
	{
		for(j=0;j<60;j++)//mins
		{
			for(k=0;k<60;k++)//secs
			{
				printf("%d:%d:%d\n",i,j,k);
				Sleep(1000);
				system("cls");
			}
		}
	}
}


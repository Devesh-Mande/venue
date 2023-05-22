#include<stdio.h>
main()
{
	char s[50],swap;
	int i,j,t;
	
	gets(s);
	i=0;
	t=0;
	do
	{
		if(s[i]==32||!s[i])
		{
			for(j=i-1;j>=(i+t)/2;j--)
			{
				swap=s[j];
				s[j]=s[t+(i-j-1)];
				s[t+(i-j-1)]=swap;
			}
			t=i+1;
		}
		i++;
	}while(s[i-1]);
	
	puts(s);
}

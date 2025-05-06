#include<unistd.h>
#include<stdio.h>
int main(int argc,char **argv)
{
	int str_len =0;
	int i =0;
	int j= 0;

	if(argc==2)
	{
		while (argv[1][str_len]!=0)
		{
			str_len++;
		}
		while(i<str_len)
		{
			if('a'<=argv[1][i]&& argv[1][i]<='z')
			{
				while(j<=argv[1][i]-'a')
				{
					write(1,&argv[1][i],1);
					j++;
				}
			}
			else if('A'<=argv[1][i]&& argv[1][i]<='Z')
			{
				while(j<=argv[1][i]-'A')
				{
					write(1,&argv[1][i],1);
					j++;
				}
			}
			else
				write(1,&argv[1][i],1);
			j=0;
			i++;
		}
	}
	write(1,"\n",1);
	return(0);
}

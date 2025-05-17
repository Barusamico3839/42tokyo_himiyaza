#include<unistd.h>
#include<stdio.h>

int main (int argc,char **argv)
{
	int str_len = 0;
	int i=0;
	char temp;

	if(argc != 2)
	{
		write(1,"\n",1);
		return(0);
	}
	while(argv[1][str_len]!= 0)
		str_len++;
	while(i< str_len/2)
	{
		temp = argv[1][i];
		argv[1][i]=argv[1][str_len - i];
		argv[1][str_len - i]=temp;
		i++;
	}
	i=0;
	while(i<=str_len)
	{
		write(1,&argv[1][i],1);
		i++;
	}
	write(1,"\n",1);
	return(0);
}

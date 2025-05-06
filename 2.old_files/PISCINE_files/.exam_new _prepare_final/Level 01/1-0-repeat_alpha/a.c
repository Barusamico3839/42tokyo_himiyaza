#include<unistd.h>
#include<stdio.h>

int main (int argc, char **argv)
{
	int i;
	int j=0;

	if(argc!=2)
	{
		write(1,"\n",1);
		return(0);
	}
	while(argv[1][j]!=0)
	{
		i=0;
		if('a'<= argv[1][j] && argv[1][j] <= 'z')
		{
			while(i < argv[1][j] - 'a' +1)
			{
				write(1, &argv[1][j],1);
				i++;
			}
		}
		else if('A'<= argv[1][j] && argv[1][j] <= 'Z')
		{
			while(i < argv[1][j] - 'A' +1)
			{
				write(1, &argv[1][j],1);
				i++;
			}
		}
		else
		{
			write(1, &argv[1][j],1);
				i++;
		}
		j++;
	}
	write(1,"\n",1);
	return(0);
}

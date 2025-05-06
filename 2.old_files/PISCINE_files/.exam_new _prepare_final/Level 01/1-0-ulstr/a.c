#include<unistd.h>

int main (int argc, char **argv)
{
	int j=0;

	if (argc !=2)
	{
		write (1,"\n",1);
		return(0);
	}
	while(argv[1][j]!=0)
	{
		if ('a'<=argv[1][j]&&argv[1][j]<='z')
			argv[1][j]= argv[1][j] - 32;
		else if ('A'<=argv[1][j]&&argv[1][j]<='Z')
			argv[1][j]= argv[1][j] + 32;
		write(1,&argv[1][j],1);
		j++;
	}
	return(0);
}

#include <unistd.h>

int main(int argc, char **argv)
{
	int j=0;

	if(argc != 2)
	{
		write(1,"\n",1);
		return(0);
	}
	if(argv[1][0]==' '| argv[1][0]=='\t' )
	{
		while(argv[1][j]==' ' | argv[1][j]=='\t')
			j++;
		while(argv[1][j]!=' ' && argv[1][j]!='\t' && argv[1][j]!=0)
		{
			write(1,&argv[1][j],1);
			j++;
		}
	}
	else
	{
		while(argv[1][j]!=' ' && argv[1][j]!='\t' && argv[1][j]!=0)
		{
			write(1,&argv[1][j],1);
			j++;
		}
	}
	return(0);
}

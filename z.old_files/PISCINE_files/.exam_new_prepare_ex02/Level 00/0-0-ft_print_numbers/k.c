#include<unistd.h>

int main (void)
{
	int i=0;
	char j;
	while(i<= 9)
	{
		j = i + '0';
		write(1,&j,1);
		i++;
	}
	return(0);
}

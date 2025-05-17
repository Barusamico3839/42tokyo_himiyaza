#include<unistd.h>

int main(void)
{
	char c;
	int i =25;
	while(i>=0)
	{
		if(i%2==0)
		{
			c = i + 'A';
			write(1,&c,1);
		}
		else
		{
			c = i + 'a';
			write(1,&c,1);
		}
		i--;
	}
}

#include<unistd.h>

void put_nbr(int n)
{
	char str;

	if(n>=10)
		put_nbr(n/10);
	str= n%10 + '0';
	write(1,&str,1);
	return;
}

int main(void)
{
	int n=1;
	while(n<=100)
	{
		if(n %15 ==0)
			write(1,"fizzbuzz\n",9);
		else if(n%5==0)
			write(1,"buzz\n",5);
		else if(n%3==0)
			write(1,"fizz\n",5);
		else
		{
			put_nbr(n);
			write(1,"\n",1);
		}
		n++;
	}
	return(0);
}

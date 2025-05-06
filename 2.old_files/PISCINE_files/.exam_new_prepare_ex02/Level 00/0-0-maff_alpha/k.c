#include<unistd.h>

int main(void)
{
	char i='a';
	while(i<= 'z')
	 {
		if(i%2 == 0 )
		{
			i= i - 32;
			write(1,&i,1);
		}
			else
			write(1,&i,1);
		i++;
	 }
	 return(0);

}

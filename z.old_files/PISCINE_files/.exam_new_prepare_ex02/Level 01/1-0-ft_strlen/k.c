int	ft_strlen(char *str)
{
	int i=0;
	while(str[i]!=0)
		i++;
	return(i);
}
#include<stdio.h>
int main(void)
{
	char str[]="abcde";
	printf("%i",ft_strlen(str));
	return(0);
}

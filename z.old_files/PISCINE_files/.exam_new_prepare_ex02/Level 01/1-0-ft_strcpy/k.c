char    *ft_strcpy(char *s1, char *s2)
{
	int i=0;
	while(s2[i] != 0)
	{
		s1[i]=s2[i];
		i++;
	}
	s1[i] =s2[i];
	return(s1);
}
#include <stdio.h>

int main(void)
{
	char str1[] = "3";
	char str2[] = "ab3c";

	printf("%s\n", str1);
	ft_strcpy(str1, str2);
	printf("%s\n", str1);
	return (0);
}

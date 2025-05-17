#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	*s1 = *s2;
	return (s1);
}

int	main(void)
{
	char	s1[]= "aaa";
	char	s2[] = "abcdefg";

	ft_strcpy(s1, s2);
	printf("%s", s2);
}

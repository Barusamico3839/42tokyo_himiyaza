#include <stdio.h>

void	ft_swap(char *a, char *b);

int	main(void)
{
	char	*r;
	char	*l;

	r = "abc";
	l = "def";
	printf("%s,%s\n", r, l);
	ft_swap(r, l);
	printf("%s,%s\n", r, l);
}

void	ft_swap(char *a, char *b)
{
	char	*temp;

	temp = a;
	a = b;
	b = temp;
}

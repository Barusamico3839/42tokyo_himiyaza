#include <stdio.h>
#include <unistd.h>

int	count_repeat(char argv)
{
	int	repeat;

	repeat = 0;
	if (argv >= 'A' && argv <= 'Z')
	{
		repeat = argv - 'A';
	}
	else if (argv >= 'a' && argv <= 'z')
	{
		repeat = argv - 'a';
	}
	repeat = repeat + 1;
	return (repeat);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			while (j < count_repeat(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				j++;
			}
			i++;
			j = 0;
		}
	}
	write(1, "\n", 1);
}

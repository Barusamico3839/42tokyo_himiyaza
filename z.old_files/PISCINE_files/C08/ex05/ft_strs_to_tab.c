#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		src_len;
	int		position;

	src_len = ft_strlen(src);
	dst = malloc(sizeof(*dst) * (src_len + 1));
	if (dst == 0)
		return (0);
	position = 0;
	while (src[position] != 0)
	{
		dst[position] = src[position];
		position++;
	}
	dst[position] = 0;
	return (dst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			position;

	position = 0;
	res = malloc(sizeof(*res) * (ac + 1));
	if (res == 0)
		return (0);
	while (position < ac)
	{
		res[position].size = ft_strlen(av[position]);
		res[position].str = av[position];
		res[position].copy = ft_strdup(res[position].str);
		position++;
	}
	res[position].str = 0;
	return (res);
}

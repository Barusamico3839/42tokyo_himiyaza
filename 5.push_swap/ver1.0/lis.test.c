#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct s_lis_res
{
	size_t	start;
	size_t	len;
	size_t	*indices;
}	t_lis_res;

static t_lis_res	lis_len_indices(const int *a, size_t n)
{
	size_t	*dp = malloc(sizeof(size_t) * n);
	size_t	*prev = malloc(sizeof(size_t) * n);
	size_t	*result = malloc(sizeof(size_t) * n);
	t_lis_res	res = {0, 0, NULL};

	if (!dp || !prev || !result)
		return ((t_lis_res){0, 0, NULL});
	size_t	size = 0;

	for (size_t i = 0; i < n; ++i)
	{
		size_t l = 0, r = size;
		while (l < r)
		{
			size_t m = (l + r) / 2;
			if (a[dp[m]] < a[i])
				l = m + 1;
			else
				r = m;
		}
		dp[l] = i;
		prev[i] = (l > 0) ? dp[l - 1] : (size_t)-1;
		if (l == size)
			size++;
	}

	size_t k = dp[size - 1];
	for (size_t i = size; i-- > 0;)
	{
		result[i] = k;
		k = prev[k];
	}

	res.start = 0;
	res.len = size;
	res.indices = result;
	free(dp);
	free(prev);
	return res;
}

static void	rotate_copy(const int *src, int *dst, size_t n, size_t start)
{
	for (size_t i = 0; i < n; ++i)
		dst[i] = src[(start + i) % n];
}

t_lis_res	find_lis_circular(const int *a, size_t n)
{
	int			*rot = malloc(sizeof(int) * n);
	t_lis_res	best = {0, 0, NULL};

	if (!rot || !n)
		return ((t_lis_res){0, 0, NULL});
	for (size_t s = 0; s < n; ++s)
	{
		rotate_copy(a, rot, n, s);
		t_lis_res tmp = lis_len_indices(rot, n);
		if (tmp.len > best.len)
		{
			free(best.indices);
			best = tmp;
			best.start = s;
		}
		else
			free(tmp.indices);
	}
	free(rot);
	return (best);
}

int	main(void)
{
	char	buffer[10000];
	int		*arr;
	size_t	size = 0;
	char	*token;

	if (!fgets(buffer, sizeof(buffer), stdin))
		return (1);
	arr = malloc(sizeof(int) * 1000);
	if (!arr)
		return (1);
	token = strtok(buffer, " \t\n");
	while (token)
	{
		if (!isdigit(token[0]) && token[0] != '-' && token[0] != '+')
			return (free(arr), 1);
		arr[size++] = atoi(token);
		token = strtok(NULL, " \t\n");
	}
	if (size == 0)
		return (free(arr), 1);

	t_lis_res r = find_lis_circular(arr, size);

	printf("start = %zu, length = %zu\n", r.start, r.len);
	printf("LIS indices (original array): ");
	for (size_t i = 0; i < r.len; ++i)
		printf("%zu ", (r.indices[i] + r.start) % size);
	printf("\n");

	free(r.indices);
	free(arr);
	return (0);
}
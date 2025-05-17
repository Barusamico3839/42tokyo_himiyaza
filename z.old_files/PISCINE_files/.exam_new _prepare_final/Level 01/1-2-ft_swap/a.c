#include<stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int a[5]={1, 2, 3, 4, 5};
	int b[4]={6, 7, 8, 9};
	int i=0;

	while(a[i])
	{
		ft_swap(a,b);
		i++;
	}
	while(i<5)
	{
		printf("%i",a[i]);
		 i++;
	}
	printf("\n");
	i=0;
	while(i<5)
	{
		printf("%i",b[i]);
		 i++;
	}
	printf("\n");
}

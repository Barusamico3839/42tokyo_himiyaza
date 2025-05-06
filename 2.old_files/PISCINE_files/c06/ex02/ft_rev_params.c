/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:27:08 by feltan            #+#    #+#             */
/*   Updated: 2025/03/31 00:45:57 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	i=1;
	while(i<argc)
	{
		j=0;
		while(argv[argc-i][j] != 0)
		{
			write(1,&argv[argc-i][j],1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
}

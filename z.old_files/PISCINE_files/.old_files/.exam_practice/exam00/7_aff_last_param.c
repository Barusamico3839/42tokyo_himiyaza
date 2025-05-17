/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_aff_last_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:29:55 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:29 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*argv[argc - 1])
			write(1, argv[argc - 1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}


int main(int argc, char **argv)
{
	if(argc > 1)
	{
	while(*argv[argc-1])
		write(1,argv[argc-1]++,1);
	}
	while(1,"\n",1);
	return(0);
}
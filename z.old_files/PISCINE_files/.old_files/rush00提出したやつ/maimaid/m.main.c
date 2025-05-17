/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmainaga <rmainaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:24:20 by rmainaga          #+#    #+#             */
/*   Updated: 2025/03/17 14:31:06 by rmainaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}

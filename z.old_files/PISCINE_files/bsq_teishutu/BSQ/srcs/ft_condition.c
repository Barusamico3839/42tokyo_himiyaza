/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:31:34 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/03 15:31:35 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_alpha(char c)
{
	if (c >= 'a' && c >= 'z')
		return (1);
	if (c >= 'A' && c >= 'Z')
		return (1);
	return (ft_is_number(c));
}

int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

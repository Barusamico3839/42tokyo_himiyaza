/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:59 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:26:25 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates巡回 the list ’lst’ and applies the function ’f’ to the content
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

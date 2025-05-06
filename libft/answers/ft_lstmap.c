/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:35:23 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/27 11:36:06 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
// // 	new_node2 = ft_lstnew("Node 2");
// // 	new_node3 = ft_lstnew("Node 3");
// // 	head = new_node;
// // 	ft_lstadd_back(&head, new_node2);
// // 	ft_lstadd_back(&head, new_node3);
// // 	printf("Before ft_lstclear:\n");
// // 	t_list *temp = head;
// // 	while (temp)
// // 	{
// // 		printf("%s\n", (char *)temp->content);
// // 		temp = temp->next;
// // 	}
// // 	ft_lstclear(&head, free);
// // 	printf("After ft_lstclear:\n");
// // 	temp = head;
// // 	while (temp)
// // 	{
// // 		printf("%s\n", (char *)temp->content);
// // 		temp = temp->next;
// // 	}
// // 	return (0);
// // }


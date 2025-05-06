/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:31:10 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:30:17 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// int	main(void)
// {
// 	t_list	*node;
// 	char	*str;

// 	str = "Hello, World!";
// 	node = ft_lstnew(str);
// 	if (node == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	printf("Node content: %s\n", (char *)node->content);
// 	printf("Node next: %p\n", node->next);
// 	free(node);
// 	return (0);
// }

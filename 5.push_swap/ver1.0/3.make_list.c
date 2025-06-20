/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.make_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:48:32 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/13 18:02:53 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*copy_stack_2stack_a(t_node *stack)
{
    t_node	*head_a = NULL;
    t_node	*cur_a = NULL;
    t_node	*cur_b = stack;
    t_node	*new_node;

    while (cur_b)
    {
        new_node = (t_node *)malloc(sizeof(t_node));
        if (!new_node)
            return (NULL);
        new_node->content = cur_b->content;
        new_node->index = cur_b->index;
        new_node->mass = cur_b->mass;
        new_node->next = NULL;
        if (!head_a)
        {
            head_a = new_node;
            cur_a = new_node;
        }
        else
        {
            cur_a->next = new_node;
            cur_a = new_node;
        }
        cur_b = cur_b->next;
    }
    return (head_a);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = value;
	new_node->mass = 0;
	new_node->index = 0;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	add_node_end(t_node *head, int value, int i)
{
	t_node	*new_node;
	t_node	*second_to_last;

	new_node = create_node(value);
	second_to_last = head->prev;
	new_node->next = head;
	new_node->prev = second_to_last;
	second_to_last->next = new_node;
	head->prev = new_node;
	new_node->index = i;
}

t_node	*make_list(int argc, int *elements)
{
	t_node *stack_a;
	int i = 0;

	stack_a = create_node(elements[i]);
	i++;
	while (i < argc - 1)
	{
		add_node_end(stack_a, elements[i], i);
		i++;
	}
	return (stack_a);
}
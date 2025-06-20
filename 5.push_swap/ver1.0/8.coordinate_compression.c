/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.coordinate_compression.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:07:08 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/12 23:49:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_swap_i(int argc, t_node *stack_a)
{
	int	tmp;
	int	i;
	int	swapped;

	swapped = 0;
	i = 0;
	while (i++ < argc - 2)
	{
		if (stack_a->index > stack_a->next->index)
		{
			tmp = stack_a->content;
			stack_a->content = stack_a->next->content;
			stack_a->next->content = tmp;
			tmp = stack_a->mass;
			stack_a->mass = stack_a->next->mass;
			stack_a->next->mass = tmp;
            tmp = stack_a->index;
			stack_a->index = stack_a->next->index;
			stack_a->next->index = tmp;
			swapped = 1;
		}
		stack_a = stack_a->next;
	}
	stack_a = stack_a->next;
	return (swapped);
}

int	bubble_swap_c(int argc, t_node *stack_a)
{
	int	tmp;
	int	i;
	int	swapped;

	swapped = 0;
	i = 0;
	while (i++ < argc - 2)
	{
		if (stack_a->content > stack_a->next->content)
		{
			tmp = stack_a->content;
			stack_a->content = stack_a->next->content;
			stack_a->next->content = tmp;
			tmp = stack_a->mass;
			stack_a->mass = stack_a->next->mass;
			stack_a->next->mass = tmp;
            tmp = stack_a->index;
			stack_a->index = stack_a->next->index;
			stack_a->next->index = tmp;
			swapped = 1;
		}
		stack_a = stack_a->next;
	}
	stack_a = stack_a->next;
	return (swapped);
}

void	bubble_sort(int argc, t_node **stack_a, int content_or_index)
{
	int	swapped;

	if (!stack_a || !*stack_a)
		return ;
	swapped = 1;
    if(content_or_index == 0)
    {
        while (swapped)
            swapped = bubble_swap_c(argc, *stack_a);
    }
    if(content_or_index == 1)
    {
        while (swapped)
            swapped = bubble_swap_i(argc, *stack_a);
    }
}

void	input_mass(int argc, t_node *stack_a)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		stack_a->mass = i;
		stack_a = stack_a->next;
		i++;
	}
}

void	coordinate_compression(int argc, t_node **stack_a)
{
	bubble_sort(argc, stack_a , 0);
	input_mass(argc, *stack_a);
    bubble_sort(argc, stack_a , 1);
}
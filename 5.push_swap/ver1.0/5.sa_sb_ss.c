/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.sa_sb_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:41:29 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/12 23:34:58 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;

	tmp = first -> index;
	first->index = second->index;
	second->index= tmp;

	tmp = first -> mass;
	first->mass = second->mass;
	second->mass= tmp;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;

	tmp = first -> index;
	first->index = second->index;
	second->index= tmp;

	tmp = first -> mass;
	first->mass = second->mass;
	second->mass= tmp;
}
// ss : sa and sb at the same time.
void	ss(t_node **stack_a, t_node **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

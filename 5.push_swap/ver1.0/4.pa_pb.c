/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.pa_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:31:49 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/12 19:26:43 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_node **stack_a, t_node **stack_b)
{
    t_node	*tmp;

    if (!stack_b || !*stack_b)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_node **stack_a, t_node **stack_b)
{
    t_node	*tmp;

    if (!stack_a || !*stack_a)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}


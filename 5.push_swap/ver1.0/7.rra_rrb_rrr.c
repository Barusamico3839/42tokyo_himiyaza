/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.rra_rrb_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:59:08 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/12 19:03:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_node **stack_a)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    *stack_a = (*stack_a)->prev;
}
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_node **stack_b)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    *stack_b = (*stack_b)->prev;
}

// rrr : rra and rrb at the same time.
void    rrr(t_node **stack_a, t_node **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
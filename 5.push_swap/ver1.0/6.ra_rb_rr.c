/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.ra_rb_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:53:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/12 18:59:04 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_node **stack_a)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    *stack_a = (*stack_a)->next;
}
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_node **stack_b)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    *stack_b = (*stack_b)->next;
}
// rr : ra and rb at the same time.
void    rr(t_node **stack_a, t_node **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
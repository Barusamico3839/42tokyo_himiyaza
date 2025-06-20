/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.push_swaps100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:40:54 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/18 20:18:40 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tekazuの最小値を見つけて、resultの中から引き抜く、戻す。
char	*sentei(char **result)
{
    int		min_len;
    int		min_idx;
    int		i;
    int		len;

    if (!result || !result[0])
        return (NULL);
    min_len = -1;
    min_idx = 0;
    i = 0;
    while (result[i])
    {
        len = 0;
        while (result[i][len])
            len++;
        if (min_len == -1 || len < min_len)
        {
            min_len = len;
            min_idx = i;
        }
        i++;
    }
    return (result[min_idx]);
}

t_node *copy_stack_2stack_a100(t_node *stack)
{
    int temp[100];
    t_node *stack_a;
    int i=0;

    stack_a = make_list(101 , temp);
    while(i<100)
    {
        stack_a->content = stack->content;
        stack_a->index = stack->index;
        stack_a->mass = stack->mass;
        stack_a = stack_a->next;
        stack = stack->next;
        i++;
    }
    return(stack_a);
}

char *push_swaps100(t_node *stack)
{
    char *result;
    t_node *stack_a;
 
    
    stack_a = copy_stack_2stack_a100(stack);
    result = ultimate_lis_turk100(stack_a);
    free(stack_a);
    
    return(sentei(&result));
}
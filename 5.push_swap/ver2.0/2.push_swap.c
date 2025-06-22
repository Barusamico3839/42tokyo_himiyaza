/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:39:09 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/13 02:34:52 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *atoi_list(int argc, char **argv)
{
    int i=1;
    int *elements;
    
    elements = (int *)malloc((argc -1)*sizeof(int));
    if(elements == NULL)
        exit(1);
    while(i < argc)
    {
        elements[i-1] = atoi(argv[i]);
        i++;
    }
    return(elements);
}


int push_swap(int argc, char **argv)
{
    t_node *stack_a;
    char **answer;
    t_node *current;
    int *elements;
    int i=0;
    
    
    elements = atoi_list(argc, argv);
    stack_a = make_list(argc, elements);
    coordinate_compression(argc, &stack_a);
    if(argc = 101)
        answer = many_push_swaps100(stack_a);
    else if(argc = 501)
        answer = many_push_swaps500(stack_a);
    else
        answer = bubble_sort_tekitou(argc, stack_a);

    current = stack_a;
    while (i < 10)
    {
        printf("i%d:", current->index);
        printf("m%d:", current->mass);
        printf("%d\n", current->content);
        current = current->next;
        i++;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:39:09 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/18 20:07:12 by himiyaza         ###   ########.fr       */
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
    char *answer;
    t_node *current;
    int *elements;
    int i=0;
    
    
    elements = atoi_list(argc, argv);
    stack_a = make_list(argc, elements);
    coordinate_compression(argc, &stack_a);
    if(argc == 101)
        answer = push_swaps100(stack_a);
    else if(argc == 501)
        answer = many_push_swaps500(stack_a);
    else
        answer = bubble_sort_tekitou(argc, stack_a);

    current = stack_a;
    
    while(answer[i])
    {
        if(answer[i] == '1')
            write(1,"pa\n",3);
        if(answer[i] == '2')
            write(1,"pb\n",3);
        if(answer[i] == '3')
            write(1,"sa\n",3);
        if(answer[i] == '4')
            write(1,"sb\n",3);
        if(answer[i] == '5')
            write(1,"ss\n",3);
        if(answer[i] == '6')
            write(1,"ra\n",3);
        if(answer[i] == '7')
            write(1,"rb\n",3);
        if(answer[i] == '8')
            write(1,"rr\n",3);
        if(answer[i] == '9')
            write(1,"rra\n",4);
        if(answer[i] == ':')
            write(1,"rrb\n",4);
        if(answer[i] == ';')
            write(1,"rrr\n",4);
        else
            write(1,"error\n",6);
    }
    // i=0;
    // while (i < 10)
    // {
    //     printf("i%d:", current->index);
    //     printf("m%d:", current->mass);
    //     printf("%d\n", current->content);
    //     current = current->next;
    //     i++;
    // }
    return (0);
}
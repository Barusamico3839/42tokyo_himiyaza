/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.make_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:48:32 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/13 04:31:59 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
t_node *copy_stack_2stack_a(t_node *stack)
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
	t_node *stack_b;
    t_node *current;
	t_node *current2;
    int *elements;
    int i=0;
    
    
    elements = atoi_list(argc, argv);
    stack_a = make_list(argc, elements);
	stack_b = copy_stack_2stack_a(stack_a);

    current = stack_b;
    while (i < 100)
    {
        printf("i%d:", current->index);
        printf("m%d:", current->mass);
        printf("%d\n", current->content);
        current = current->next;
        i++;
    }
	printf("\n");
	current2 = stack_b;
    while (i < 5)
    {
        printf("i%d:", current2->index);
        printf("m%d:", current2->mass);
        printf("%d\n", current2->content);
        current2 = current2->next;
        i++;
    }
    return (0);
}


int main (int argc, char **argv)
{
    return(push_swap(argc, argv));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:57:07 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/18 20:24:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CHUNK_MIN 13
# define CHUNK_MAX 20

typedef struct s_kouzoutai_maji_imifu
{
	int								content;
	int								mass;
	int								index;
	struct s_kouzoutai_maji_imifu	*prev;
	struct s_kouzoutai_maji_imifu	*next;
}									t_node;

int									push_swap(int argc, char **argv);
t_node								*make_list(int argc, int *elements);
void								coordinate_compression(int argc,
										t_node **stack_a);
char								*push_swaps100(t_node *stack);
char								*many_push_swaps500(t_node *stack);
char								*bubble_sort_tekitou(int argc,
										t_node *stack_a);
char								**ultimate_sort_machine100(t_node *stack_a);
void								pa(t_node **stack_a, t_node **stack_b);
void								pb(t_node **stack_a, t_node **stack_b);
void								sa(t_node **stack_a);
void								sb(t_node **stack_b);
void								ss(t_node **stack_a, t_node **stack_b);
void								ra(t_node **stack_a);
void								rb(t_node **stack_b);
void								rr(t_node **stack_a, t_node **stack_b);
void								rra(t_node **stack_a);
void								rrb(t_node **stack_b);
void								rrr(t_node **stack_a, t_node **stack_b);
t_node								*copy_stack_2stack_a100(t_node *stack);
void								bubble_sort(int argc, t_node **stack_a,
										int content_or_index);
t_node								*copy_stack_2stack_a(t_node *stack);
char								*ultimate_lis_turk100(t_node *stack_a);
int									find_lis(int *arr_a, int *arr_lis);
#endif
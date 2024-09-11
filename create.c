/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:31:36 by seckhard          #+#    #+#             */
/*   Updated: 2024/09/10 13:07:35 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

void	create_stack(t_stack **stack, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->nbr = ft_atoi(argv[i]);
		new->index = i - 1;
		new->push_cost = 0;
		new->above_median = false;
		new->cheapest = false;
		new->target_node = NULL;
		new->next = *stack;
		new->prev = NULL;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
		i++;
	}
}

void	init_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		push_init(b, tmp, 'b');
		tmp = tmp->next;
	}
}

void   push_init(t_stack **stack, t_stack *top_node, char stack_name)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = top_node->nbr;
	new->index = top_node->index;
	new->push_cost = top_node->push_cost;
	new->above_median = top_node->above_median;
	new->cheapest = top_node->cheapest;
	new->target_node = top_node->target_node;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

void  init_nodes_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->size = a;
		tmp->target_node = b;
		tmp = tmp->next;
	}
}

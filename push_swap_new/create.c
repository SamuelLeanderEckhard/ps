/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:31:36 by seckhard          #+#    #+#             */
/*   Updated: 2024/09/02 17:45:09 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		new->next = NULL;
		new->prev = NULL;
		if (!*stack)
			*stack = new;
		else
		{
			new->next = *stack;
			(*stack)->prev = new;
			*stack = new;
		}
		i++;
	}
}

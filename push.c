/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:46:43 by seckhard          #+#    #+#             */
/*   Updated: 2024/09/08 21:46:43 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

// Pushes the top node from one stack to the top of another
static void	push_to_stack(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

// Pushes to stack a
void	pa(t_stack **a, t_stack **b)
{
	push_to_stack(a, b);
	ft_printf("pa\n");
}

// Pushes to stack b
void	pb(t_stack **b, t_stack **a)
{
	push_to_stack(b, a);
	ft_printf("pb\n");
}

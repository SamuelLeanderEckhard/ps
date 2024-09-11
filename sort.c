/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:47:17 by seckhard          #+#    #+#             */
/*   Updated: 2024/09/08 22:47:17 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->nbr > a->next->nbr)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void sort_big(t_stack *a, t_stack *b)
{
	int		median;
	int		above_median;
	int		below_median;
	int		i;

	median = get_median(a);
	above_median = 0;
	below_median = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->nbr > median)
			above_median++;
		else
			below_median++;
		a = a->next;
		i++;
	}
	if (above_median <= below_median)
		sort_big_a(a, b, median);
	else
		sort_big_b(a, b, median);
}

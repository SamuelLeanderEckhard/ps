/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:23:29 by seckhard          #+#    #+#             */
/*   Updated: 2024/09/02 18:02:10 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (OK);
	a = create_stack(argc, argv);
	b = create_stack(argc, argv);
	if (!a || !b)
	{
		free_stack(a);
		free_stack(b);
		return (OK);
	}
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small(a, b);
		else
			sort_big(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (OK);
}

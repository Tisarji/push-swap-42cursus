/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 00:43:28 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_descending_order(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr < a->next->nbr)
		{
			return	(false);
		}
		a = a->next;
	}
	return	(true);
}

void	sort_descending(t_stack **a, t_stack **b)
{
	while (*a)
	{
		ft_pb(a, b);
	}
	while (*b)
	{
		ft_pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int stack_size = ft_stacksize(*a);

	if (is_descending_order(*a))
		sort_descending(a, b);
	else if (stack_size == 3)
		algorithm_small(a);
	else if (stack_size <= 10)
		algorithm_medium(a, b);
	else if (stack_size < 100)
		algorithm_large(a, b, 1);
	else
		butterfly_split(a, b, stack_size);
}

int	main(int argc, char *argv[])
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (argc == 1)
		return 0;
	ft_check_arg(&a, argc, argv);
	if (!ft_check(a))
		sort_stack(&a, &b);
	freeall(&a);
	freeall(&b);
	return 0;
}

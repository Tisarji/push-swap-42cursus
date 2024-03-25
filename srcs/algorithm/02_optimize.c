/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:45:44 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:22:11 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_descending_order(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr < a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

void	sort_descending(t_stack **a, t_stack **b)
{
	while (*a)
		ft_pb(a, b);
	while (*b)
		ft_pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	stack_size;

	stack_size = ft_stacksize(*a);
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

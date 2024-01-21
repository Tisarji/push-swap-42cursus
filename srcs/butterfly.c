/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:32:03 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/20 02:34:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isbiggest_idx(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->idx;
	while (lst)
	{
		if (lst->idx > i)
			i = lst->idx;
		lst = lst->next;
	}
	return (i);
}

static void	ft_b_to_a(t_stack **a, t_stack **b)
{
	int	maxidx;
	int	pos;
	int	size;

	while (*b)
	{
		maxidx = ft_isbiggest_idx(*b);
		if ((*b)->idx == maxidx)
			ft_pa(a, b);
		else if ((*b)->idx != maxidx)
		{
			size = ft_stacksize(*b) - 1;
			pos = findidxpos(*b, maxidx);
			if (pos > (size / 2))
				while ((*b)->idx != maxidx)
					ft_rrb(b);
			else if (pos <= (size / 2))
			{
				while ((*b)->idx != maxidx)
					ft_rb(b);
			}
		}
	}
}

void	butterfly_split(t_stack **a, t_stack **b, int size)
{
	int	counter;
	int	nrange;

	counter = 0;
	if (size >= 6 && size <= 250)
		nrange = 15;
	else
		nrange = 30;
	while (*a)
	{
		if ((*a)->idx <= counter)
		{
			ft_pb(a, b);
			ft_rb(b);
			counter++;
		}
		else if ((*a)->idx <= (counter + nrange))
		{
			ft_pb(a, b);
			counter++;
		}
		else
			ft_ra(a);
	}
	ft_b_to_a(a, b);
}

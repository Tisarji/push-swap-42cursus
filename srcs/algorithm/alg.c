/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:32:03 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:08:28 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void	ft_b_to_a(t_stack **head_a, t_stack **head_b)
{
	int	maxidx;
	int	pos;
	int	size;

	while (*head_b)
	{
		maxidx = ft_isbiggest_idx(*head_b);
		if ((*head_b)->idx == maxidx)
			ft_pa(head_a, head_b);
		else if ((*head_b)->idx != maxidx)
		{
			size = ft_stacksize(*head_b) - 1;
			pos = findidxpos(*head_b, maxidx);
			if (pos > (size / 2))
				while ((*head_b)->idx != maxidx)
					ft_rrb(head_b);
			else if (pos <= (size / 2))
			{
				while ((*head_b)->idx != maxidx)
					ft_rb(head_b);
			}
		}
	}
}

void	butterfly_split(t_stack **head_a, t_stack **head_b, int size)
{
	int	counter;
	int	nrange;

	counter = 0;
	if (size >= 6 && size <= 250)
		nrange = 15;
	else
		nrange = 30;
	while (*head_a)
	{
		if ((*head_a)->idx <= counter)
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
			counter++;
		}
		else if ((*head_a)->idx <= (counter + nrange))
		{
			ft_pb(head_a, head_b);
			counter++;
		}
		else
			ft_ra(head_a);
	}
	ft_b_to_a(head_a, head_b);
}

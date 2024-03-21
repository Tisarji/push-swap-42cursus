/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:18:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/20 01:00:43 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_element(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	prox;

	min = ft_issmallest(*a);
	pos = findpos(*a, min);
	prox = (ft_stacksize(*a) / 2);
	if ((*a)->nbr == min)
	{
		ft_pb(a, b);
		min = ft_issmallest(*a);
		pos = findpos(*a, min);
		prox = (ft_stacksize(*a) / 2);
	}
	if (prox >= pos)
		ft_ra(a);
	else
		ft_rra(a);
}

void	algorithm_small(t_stack **lst)
{
	while (!(ft_check(*lst)))
	{
		if (!(top_next_cmp(*lst)) && top_bot_cmp(*lst))
			ft_sa(lst);
		else if (!(top_next_cmp(*lst)) && !(top_bot_cmp(*lst)) && \
				!(mid_bot_cmp(*lst)))
		{
			ft_sa(lst);
			ft_rra(lst);
		}
		else if (!(top_next_cmp(*lst)) && !(top_bot_cmp(*lst)) && \
				mid_bot_cmp(*lst))
			ft_ra(lst);
		else if (top_bot_cmp(*lst) && top_next_cmp(*lst) && \
				(!(mid_bot_cmp(*lst))))
		{
			ft_sa(lst);
			ft_ra(lst);
		}
		else
			ft_rra(lst);
	}
}

void	algorithm_medium(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
		move_min_element(a, b);
	algorithm_small(a);
	while (*b)
		ft_pa(a, b);
}

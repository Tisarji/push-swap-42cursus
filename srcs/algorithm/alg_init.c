/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:18:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:06:54 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_min_element(t_stack **head_a, t_stack **head_b)
{
	int	min;
	int	pos;
	int	prox;

	min = ft_issmallest(*head_a);
	pos = findpos(*head_a, min);
	prox = (ft_stacksize(*head_a) / 2);
	if ((*head_a)->nbr == min)
	{
		ft_pb(head_a, head_b);
		min = ft_issmallest(*head_a);
		pos = findpos(*head_a, min);
		prox = (ft_stacksize(*head_a) / 2);
	}
	if (prox >= pos)
		ft_ra(head_a);
	else
		ft_rra(head_a);
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

void	algorithm_medium(t_stack **head_a, t_stack **head_b)
{
	while (ft_stacksize(*head_a) > 3)
		move_min_element(head_a, head_b);
	algorithm_small(head_a);
	while (*head_b)
		ft_pa(head_a, head_b);
}

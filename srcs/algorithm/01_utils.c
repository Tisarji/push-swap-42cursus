/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:57:56 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/28 11:57:54 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rearrange_stack_by_key(t_stack **head_a, t_stack **head_b, \
			int keynum, int x)
{
	int	pos;
	int	prox;
	int	size;

	size = ft_stacksize(*head_a) + ft_stacksize(*head_b);
	pos = findpos(*head_a, keynum);
	while (ft_stacksize(*head_b) < (size / 7) * x)
	{
		prox = (ft_stacksize(*head_a) / 2);
		if ((*head_a)->nbr <= keynum)
			ft_pb(head_a, head_b);
		if (prox >= pos)
			ft_ra(head_a);
		else
			ft_rra(head_a);
	}
}

void	adjust_stack(t_stack **head_a, t_stack **head_b)
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

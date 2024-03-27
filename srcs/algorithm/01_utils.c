/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:57:56 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/26 10:10:58 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rearrange_stack_by_key(t_stack **a, t_stack **b, int keynum, int x)
{
	int	pos;
	int	prox;
	int	size;

	size = ft_stacksize(*a) + ft_stacksize(*b);
	pos = findpos(*a, keynum);
	while (ft_stacksize(*b) < (size / 7) * x)
	{
		prox = (ft_stacksize(*a) / 2);
		if ((*a)->nbr <= keynum)
			ft_pb(a, b);
		if (prox >= pos)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_proximity(t_stack **a, t_stack **b)
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

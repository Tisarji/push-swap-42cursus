/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:55:59 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stacksize(*a) < 2)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	if ((*a)->next)
	{
		tmp = *a;
		tmp2 = (*a)->next;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = (*a)->next;
		(*a)->next = NULL;
		*a = tmp2;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stacksize(*b) < 2)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	if ((*b)->next)
	{
		tmp = *b;
		tmp2 = (*b)->next;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = tmp;
		*b = (*b)->next;
		(*b)->next = NULL;
		*b = tmp2;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (a && ft_stacksize(*a) > 2)
		ft_ra(a);
	if (b && ft_stacksize(*b) > 2)
		ft_rb(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:54:34 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:57:43 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (ft_stacksize(*a) < 2)
		return ;
	if (!(*a)->next)
		return ;
	tmp = *a ;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (ft_stacksize(*b) < 2)
		return ;
	if (!(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if (a && ft_stacksize(*a) > 2)
		ft_sa(a);
	if (b && ft_stacksize(*b) > 2)
		ft_sb(b);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!ft_stacksize(*b))
		return ;
	if (b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!ft_stacksize(*a))
		return ;
	if (a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "pb\n", 3);
}

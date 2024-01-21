/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:40:09 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/19 23:32:56 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

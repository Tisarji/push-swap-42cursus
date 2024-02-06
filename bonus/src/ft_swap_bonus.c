/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:15:32 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 13:21:18 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_sa2(t_stack	**a)
{
	t_stack	*temp;

	if (ft_stacksize(*a) < 2)
		return ;
	if (!(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	ft_sb2(t_stack	**b)
{
	t_stack	*temp;

	if (ft_stacksize(*b) < 2)
		return ;
	if (!b)
		return ;
	if (!(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
}

void	ft_ss2(t_stack **a, t_stack **b)
{
	if (a && ft_stacksize(*a) > 2)
		ft_sa2(a);
	if (b && ft_stacksize(*b) > 2)
		ft_sb2(b);
}

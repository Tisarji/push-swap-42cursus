/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:09:32 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 13:21:27 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_ra2(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*a) < 2)
		return ;
	temp = NULL;
	temp2 = NULL;
	if ((*a)->next)
	{
		temp = *a;
		temp2 = (*a)->next;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = temp;
		*a = (*a)->next;
		(*a)->next = NULL;
		*a = temp2;
	}
}

void	ft_rb2(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*b) < 2)
		return ;
	temp = NULL;
	temp2 = NULL;
	if ((*b)->next)
	{
		temp = *b;
		temp2 = (*b)->next;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = temp;
		*b = (*b)->next;
		(*b)->next = NULL;
		*b = temp2;
	}
}

void	ft_rr2(t_stack **a, t_stack **b)
{
	if (a && ft_stacksize(*a) > 2)
		ft_ra2(a);
	if (b && ft_stacksize(*b) > 2)
		ft_rb2(b);
}

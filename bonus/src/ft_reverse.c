/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:17:21 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 01:18:29 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *a;
	last = NULL;
	if (ft_stacksize(*a) < 2)
		return ;
	while ((*a)->next)
	{
		if (!(last))
		{
			if ((*a)->next->next == NULL)
			{
				last = (*a)->next;
				(*a)->next = NULL;
				break ;
			}
		}
		*a = (*a)->next;
	}
	*a = last;
	(*a)->next = temp;
}

void	ft_rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*b) < 2)
		return ;
	temp = *b;
	last = NULL;
	while ((*b)->next)
	{
		if (!(last))
		{
			if ((*b)->next->next == NULL)
			{
				last = (*b)->next;
				(*b)->next = NULL;
				break ;
			}
		}
		*b = (*b)->next;
	}
	*b = last;
	(*b)->next = temp;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (a && ft_stacksize(*a) > 2)
		ft_rra(a);
	if (b && ft_stacksize(*b) > 2)
		ft_rrb(b);
}

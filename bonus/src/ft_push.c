/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:17:06 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 01:17:17 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!ft_stacksize(*b))
		return ;
	if (b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!ft_stacksize(*a))
		return ;
	if (b == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

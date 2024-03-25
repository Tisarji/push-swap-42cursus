/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:01:10 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 14:51:49 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_stack **head_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*head_a) < 2)
		return ;
	temp = *head_a;
	last = NULL;
	while ((*head_a)->next)
	{
		if (!(last))
		{
			if ((*head_a)->next->next == NULL)
			{
				last = (*head_a)->next;
				(*head_a)->next = NULL;
				break ;
			}
		}
		*head_a = (*head_a)->next;
	}
	*head_a = last;
	(*head_a)->next = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **head_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*head_b) < 2)
		return ;
	temp = *head_b;
	last = NULL;
	while ((*head_b)->next)
	{
		if (!(last))
		{
			if ((*head_b)->next->next == NULL)
			{
				last = (*head_b)->next;
				(*head_b)->next = NULL;
				break ;
			}
		}
		*head_b = (*head_b)->next;
	}
	*head_b = last;
	(*head_b)->next = temp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	if (head_a && ft_stacksize(*head_a) > 2)
		ft_rra(head_a);
	if (head_b && ft_stacksize(*head_b) > 2)
		ft_rrb(head_b);
}

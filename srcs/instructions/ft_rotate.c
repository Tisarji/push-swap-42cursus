/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 14:53:19 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_stack **head_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stacksize(*head_a) < 2)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	if ((*head_a)->next)
	{
		tmp = *head_a;
		tmp2 = (*head_a)->next;
		while ((*head_a)->next)
			*head_a = (*head_a)->next;
		(*head_a)->next = tmp;
		*head_a = (*head_a)->next;
		(*head_a)->next = NULL;
		*head_a = tmp2;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stacksize(*head_b) < 2)
		return ;
	tmp = NULL;
	tmp2 = NULL;
	if ((*head_b)->next)
	{
		tmp = *head_b;
		tmp2 = (*head_b)->next;
		while ((*head_b)->next)
			*head_b = (*head_b)->next;
		(*head_b)->next = tmp;
		*head_b = (*head_b)->next;
		(*head_b)->next = NULL;
		*head_b = tmp2;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	if (head_a && ft_stacksize(*head_a) > 2)
		ft_ra(head_a);
	if (head_b && ft_stacksize(*head_b) > 2)
		ft_rb(head_b);
}

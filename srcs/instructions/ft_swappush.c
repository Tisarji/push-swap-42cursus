/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:54:34 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 14:55:09 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack **head_a)
{
	t_stack	*tmp;

	if (ft_stacksize(*head_a) < 2)
		return ;
	if (!(*head_a)->next)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **head_b)
{
	t_stack	*tmp;

	if (ft_stacksize(*head_b) < 2)
		return ;
	if (!(*head_b)->next)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	if (head_a && ft_stacksize(*head_a) > 2)
		ft_sa(head_a);
	if (head_b && ft_stacksize(*head_b) > 2)
		ft_sb(head_b);
}

void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (!ft_stacksize(*head_b))
		return ;
	if (head_b)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		tmp->next = *head_a;
		*head_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (!ft_stacksize(*head_a))
		return ;
	if (head_a)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		tmp->next = *head_b;
		*head_b = tmp;
	}
	write(1, "pb\n", 3);
}

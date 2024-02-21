/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:54:34 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/07 14:54:43 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sa(t_stack **lst_a)
{
	t_stack	*tmp;
	t_stack	*a;

	if (*lst_a)
	{
		a = *lst_a;
		tmp = a->next;
		a->next = tmp->next;
		tmp->next = a;
		a = tmp;
		*lst_a = a;
		write(1, "sa\n", 3);
	}
	return (0);
}

int	sb(t_stack **lst_b)
{
	t_stack	*tmp;
	t_stack	*b;

	if (*lst_b)
	{
		b = *lst_b;
		tmp = b->next;
		b->next = tmp->next;
		tmp->next = b;
		b = tmp;
		*lst_b = b;
		write(1, "sb\n", 3);
	}
	return (0);
}

int	ss(t_stack **lst_a, t_stack **lst_b)
{
	sa(lst_a);
	sb(lst_b);
	write (1, "ss\n", 3);
	return (0);
}

int	pa(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*b;

	b = *lst_b;
	if (*lst_b)
		(*lst_b) = (*lst_b)->next;
	else
		return (0);
	b->next = (*lst_a);
	(*lst_a) = b;
	write (1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*a;

	a = *lst_a;
	if (*lst_a)
	{
		(*lst_a) = (*lst_a)->next;
		a->next = (*lst_b);
		(*lst_b) = a;
		write (1, "pb\n", 3);
	}
	return (0);
}

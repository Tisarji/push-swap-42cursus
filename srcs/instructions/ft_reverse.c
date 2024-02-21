/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:01:10 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/07 14:54:51 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rra(t_stack **lst_a)
{
	t_stack	*a;
	t_stack	*tmp;

	a = *lst_a;
	tmp = a;
	if (!a || !a->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (a->next != tmp)
		a = a->next;
	a->next = NULL;
	tmp->next = *lst_a;
	*lst_a = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **lst_b)
{
	t_stack	*b;
	t_stack	*tmp;

	b = *lst_b;
	tmp = b;
	if (!b || !b->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (b->next != tmp)
		b = b->next;
	b->next = NULL;
	tmp->next = *lst_b;
	write(1, "rrb\n", 4);
	*lst_b = tmp;
	return (0);
}

int	rrr(t_stack **lst_a, t_stack **lst_b)
{
	rra(lst_a);
	rrb(lst_b);
	write(1, "rrr\n", 4);
	return (0);
}

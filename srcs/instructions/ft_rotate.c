/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:00 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/06 10:48:28 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ra(t_stack **lst_a)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*ptr;

	a = *lst_a;
	if (!a || !a->next)
		return (0);
	tmp = a->next;
	ptr = tmp;
	a->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	*lst_a = ptr;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **lst_b)
{
	t_stack	*b;
	t_stack	*tmp;
	t_stack	*ptr;

	b = *lst_b;
	if (!b || !b->next)
		return (0);
	tmp = b->next;
	ptr = tmp;
	b->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	*lst_b = ptr;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **lst_a, t_stack **lst_b)
{
	ra(lst_a);
	rb(lst_b);
	write(1, "rr\n", 3);
	return (0);
}

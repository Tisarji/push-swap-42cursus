/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:18:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/07 14:55:04 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_2(t_stack **lst_a)
{
	if ((*lst_a)->next && (*lst_a)->data > (*lst_a)->next->data)
		sa(lst_a);
}

void	sort_3(t_stack **lst_a)
{
	int	i;

	i = find_max(lst_a);
	if (i == 2)
		sort_2(lst_a);
	if (i == 1)
	{
		rra(lst_a);
		sort_2(lst_a);
	}
	if (i == 0)
	{
		ra(lst_a);
		sort_2(lst_a);
	}
}

void	sort_4(t_stack **lst_a, t_stack **lst_b)
{
	int	i;

	i = find_max(lst_a);
	if (i == 3)
		rra(lst_a);
	else if (i == 2)
	{
		rra(lst_a);
		rra(lst_a);
	}
	else if (i == 1)
		ra(lst_a);
	pb(lst_a, lst_b);
	sort_3(lst_a);
	pa(lst_a, lst_b);
	ra(lst_a);
}

void	sort_5(t_stack **lst_a, t_stack **lst_b)
{
	int	i;

	i = find_max(lst_a);
	if (i == 4)
		rra(lst_a);
	else if (i == 3)
	{
		rra(lst_a);
		rra(lst_a);
	}
	else if (i == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (i == 1)
		ra(lst_a);
	pb(lst_a, lst_b);
	sort_4(lst_a, lst_b);
	pa(lst_a, lst_b);
	ra(lst_a);
}

void	sort_lst(t_stack **lst_a, t_stack **lst_b, int len)
{
	if (len == 2)
		sort_2(lst_a);
	else if (len == 3)
		sort_3(lst_a);
	else if (len == 4)
		sort_4(lst_a, lst_b);
	else if (len == 5)
		sort_5(lst_a, lst_b);
	else if (len >= 6 && len <= 100)
	{
		butterfly_sort(lst_a, lst_b, 15);
		push_lst_a(lst_a, lst_b, len);
	}
	else if (len > 100 && len < 500)
	{
		butterfly_sort(lst_a, lst_b, 30);
		push_lst_a(lst_a, lst_b, len);
	}
	else if (len >= 500)
	{
		butterfly_sort(lst_a, lst_b, 40);
		push_lst_a(lst_a, lst_b, len);
	}
}

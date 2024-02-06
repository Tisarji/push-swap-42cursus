/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:00:20 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/06 10:47:51 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "../../includes/push_swap.h"

void	butterfly_sort(t_stack **lst_a, t_stack **lst_b, int n)
{
	int	count;

	count = 0;
	while ((*lst_a))
	{
		if ((*lst_a)->idx <= count)
		{
			pb(lst_a, lst_b);
			rb(lst_b);
			count++;
		}
		else if ((*lst_a)->idx <= count + n)
		{
			pb(lst_a, lst_b);
			count++;
		}
		else
		{
			ra(lst_a);
		}
	}
}

void	push_lst_a(t_stack **lst_a, t_stack **lst_b, int len)
{
	int	max;

	max = 0;
	while (*lst_b)
	{
		max = find_max(lst_b);
		if (max <= len / 2)
		{
			while (max-- >= 1)
				rb(lst_b);
			pa(lst_a, lst_b);
			len--;
		}
		else
		{
			while (len - max)
			{
				rrb(lst_b);
				max++;
			}
			pa(lst_a, lst_b);
			len--;
		}
	}
}

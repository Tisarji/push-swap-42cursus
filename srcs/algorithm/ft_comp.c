/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:33:54 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 14:48:40 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	top_next_cmp(t_stack *lst)
{
	if (!lst)
		return (0);
	if (lst->nbr <= lst->next->nbr)
		return (1);
	else
		return (0);
}

int	mid_bot_cmp(t_stack *lst)
{
	int	second;

	if (!lst || !(lst->next))
		return (0);
	second = lst->next->nbr;
	while (lst->next)
		lst = lst->next;
	if (second <= lst->nbr)
		return (1);
	else
		return (0);
}

int	top_bot_cmp(t_stack *lst)
{
	int	first;

	first = lst->nbr;
	while (lst->next)
		lst = lst->next;
	if (first <= lst->nbr)
		return (1);
	else
		return (0);
}

int	sec_largest(t_stack *lst)
{
	int	largest;
	int	second;

	if (!lst)
		return (0);
	largest = lst->nbr;
	second = INT_MIN;
	while (lst)
	{
		if (lst->nbr > largest)
		{
			second = largest;
			largest = lst->nbr;
		}
		else if (lst->nbr >= second && lst->nbr < largest)
			second = lst->nbr;
		lst = lst->next;
	}
	return (second);
}

void	sort_a(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = ft_stacksize(*head_a);
	while (ft_stacksize(*head_a) != 3)
		ft_proximity(head_a, head_b);
	algorithm_small(head_a);
	while (ft_stacksize(*head_a) < size)
		ft_pa(head_a, head_b);
}

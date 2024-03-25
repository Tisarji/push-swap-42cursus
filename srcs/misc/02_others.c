/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:29:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:11:25 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_check(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->nbr > lst->next->nbr)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

int	ft_isbiggest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->nbr;
	while (lst)
	{
		if (lst->nbr > i)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}

int	ft_issmallest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->nbr;
	while (lst)
	{
		if (lst->nbr < i)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:29:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 00:42:11 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeall(t_stack **sa)
{
	t_stack	*temp;

	while (*sa)
	{
		temp = (*sa)->next;
		free(*sa);
		*sa = temp;
	}
}

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

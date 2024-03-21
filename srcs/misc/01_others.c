/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:48 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:40:17 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_sortarrayforindex(int **sortthis, int size)
{
	int	i;
	int	temp;
	int	*sorted;

	sorted = *sortthis;
	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		if (sorted[i] <= sorted[i + 1])
			i++;
		else
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
	}
}

int	findidxpos(t_stack *ls, int max)
{
	int	i;

	i = 1;
	if (ft_stacksize(ls) > 1)
	{
		while (max != ls->idx && i <= ft_stacksize(ls))
		{
			i++;
			ls = ls->next;
		}
	}
	return (i);
}

int	findpos(t_stack *ls, int num)
{
	int	i;

	i = 1;
	while (num != ls->nbr && i <= ft_stacksize(ls))
	{
		i++;
		ls = ls->next;
	}
	return (i);
}

int	ft_getindex(int *sorted, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	*ft_sortcomplete(t_stack *lst)
{
	int	size;
	int	*sorted;
	int	i;
	int	size_backup;

	i = 0;
	size = ft_stacksize(lst);
	size_backup = size;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (i < size)
	{
		sorted[i] = lst->nbr;
		lst = lst->next;
		i++;
	}
	ft_sortarrayforindex(&sorted, size_backup);
	return (sorted);
}

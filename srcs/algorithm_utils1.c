/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/20 02:47:16 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_dupcheck(int *sorted, int size)
{
	int	temp;
	int	i;

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
	i = 0;
	while (i < size - 1)
	{
		if (sorted[i] == sorted[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	check_dups(t_stack *lst)
{
	int	size;
	int	*sorted;
	int	i;

	i = 0;
	size = ft_stacksize(lst);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (i < size)
	{
		sorted[i] = lst->nbr;
		lst = lst->next;
		i++;
	}
	if (!(ft_dupcheck(sorted, size)))
	{
		free(sorted);
		return (0);
	}
	free(sorted);
	return (1);
}

void	ft_check_arg(t_stack **a, int argc, char *argv[])
{
	if (argc == 1 || parseargs(argv, argc) == NULL)
		errormsg();
	else
		create_t_stack(a, argv, argc);
	if (*a)
	{
		if (!(check_dups(*a)))
		{
			freeall(a);
			errormsg();
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:13 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/26 17:24:59 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	ft_check_arg(t_stack **head_a, int argc, char *argv[])
{
	if (argc == 1 || parser_args(argv, argc) == NULL)
		ft_msgerror();
	else
		init_stack(head_a, argv, argc);
	if (*head_a)
	{
		if (!(check_dups(*head_a)))
		{
			free_stack(head_a);
			ft_msgerror();
		}
	}
}
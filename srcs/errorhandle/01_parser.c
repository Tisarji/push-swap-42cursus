/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/20 15:19:44 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*check_char(int argc, char *argv[])
{
	int		i;
	int		j;
	bool	is_negative;

	i = 1;
	while (i < argc)
	{
		j = 0;
		is_negative = false;
		if (argv[i][0] == '-')
		{
			is_negative = true;
			j++;
		}
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] == '-' && j == 0) && !ft_isdigit(argv[i][j]))
				return (NULL);
			j++;
		}
		if (is_negative && j == 1)
			return (NULL);
		i++;
	}
	return ((void *)1);
}

int	check_issorted(t_stack **lst)
{
	int		num;
	t_stack	*tmp;
	t_stack	*tmp_num;

	tmp = *lst;
	while (*lst)
	{
		num = (*lst)->data;
		tmp_num = (*lst)->next;
		*lst = tmp_num;
		while (*lst)
		{
			if (num > (*lst)->data)
			{
				*lst = tmp;
				return (1);
			}
			*lst = (*lst)->next;
		}
		*lst = tmp_num;
	}
	*lst = tmp;
	return (0);
}

static int	ft_dupcheck(int *sorted, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (sorted[i] > sorted[i + 1])
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
		else
			i++;
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

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	check_dublicates(t_stack *head)
{
	int	size;
	int	*sorted;
	int	i;

	i = 0;
	size = ft_stacksize(head);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (head != NULL)
	{
		sorted[i] = head->data;
		head = head->next;
		i++;
	}
	if (!ft_dupcheck(sorted, size))
	{
		free(sorted);
		ft_error("Error: Duplicate found", 0);
		return (0);
	}
	free(sorted);
	return (1);
}

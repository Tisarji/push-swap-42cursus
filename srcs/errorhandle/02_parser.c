/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:13 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/28 16:54:39 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_empty_or_space(const char *str)
{
	if (ft_strlen(str) == 0)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

static void	empty_string(int argc, char **argv)
{
	int	i;
	int	count;
	int	error;

	i = 0;
	count = 0;
	error = 0;
	while (argc > ++i)
	{
		if (is_empty_or_space(argv[i]))
			error++;
		else
			count++;
	}
	if ((error > 0 && count > 0) || (argc >= 2 && error > 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (error > 0 && count == 0)
		exit(EXIT_FAILURE);
	else
		return ;
}

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
	if (argc == 1)
	{
		ft_msgerror();
		exit(EXIT_FAILURE);
	}
	else
	{
		empty_string(argc, argv);
		if (parser_args(argv, argc) == NULL)
		{
			ft_msgerror();
			exit(EXIT_FAILURE);
		}
		else
		{
			init_stack(head_a, argv, argc);
			if (*head_a && !check_dups(*head_a))
			{
				free_stack(head_a);
				ft_msgerror();
				exit(EXIT_FAILURE);
			}
		}
	}
}

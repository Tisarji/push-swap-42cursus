/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:37:58 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/26 20:54:26 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	return_number(int *start, int stop, int sign, char *argv[])
{
	long long	num;

	sign = 1;
	num = 0;
	while (*start < stop)
	{
		if (argv[1][*start] == '-')
		{
			sign *= -1;
			(*start)++;
		}
		num = num * 10 + ((char)argv[1][*start] - 48);
		(*start)++;
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		ft_msgerror();
	return (num * sign);
}

static void	allocate_values( t_stack **new, t_stack **head_a, t_stack **temp)
{
	if (!temp)
	{
		while (*head_a)
		{
			free(*head_a);
			*head_a = (*head_a)->next;
		}
		return ;
	}
	*new = ((*new)->next = *temp);
}

static int	shift_i(char *argv[], int i)
{
	if (argv[1][i] == 32)
		while (argv[1][i] == 32)
			i++;
	while ((char)argv[1][i] != 32 && argv[1][i])
		i++;
	return (i);
}

int	create_from_str(char *argv[], int i, int stop, int start)
{
	unsigned int	num;
	int				sign;

	i = 0;
	start = i;
	num = 0;
	sign = 1;
	if (argv[1][i])
	{
		num = 0;
		i = shift_i(argv, i);
		stop = i;
		while (start < stop)
		{
			if (argv[1][start] == '-')
			{
				sign *= -1;
				start++;
			}
			num = num * 10 + ((char)argv[1][start] - 48);
			start++;
		}
	}
	return (num * sign);
}

void	create_from_arg(t_stack **head_a, t_stack *new, char *argv[], int set)
{
	int				start;
	int				i;
	unsigned int	num;
	int				sign;
	t_stack			*temp;

	i = 0;
	start = i;
	while (argv[1][i])
	{
		sign = 1;
		i = shift_i(argv, i);
		num = return_number(&start, i, sign, argv);
		start++;
		while (argv[1][start] == 32)
			start++;
		if (set != 0)
		{
			temp = create_lst(num * sign);
			allocate_values(&new, head_a, &temp);
			if (!(argv[1][i]))
				new->next = NULL;
		}
		set = 1;
	}
}

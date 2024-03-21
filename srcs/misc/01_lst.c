/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:37:58 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:37:53 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	retnum(int *start, int stop, int sign, char **av)
{
	long long	num;

	sign = 1;
	num = 0;
	while (*start < stop)
	{
		if (av[1][*start] == '-')
		{
			sign *= -1;
			(*start)++;
		}
		num = num * 10 + ((char)av[1][*start] - 48);
		(*start)++;
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		errormsg();
	return (num * sign);
}

static void	al_vals( t_stack **new, t_stack **sahead, t_stack **temp)
{
	if (!temp)
	{
		while (*sahead)
		{
			free(*sahead);
			*sahead = (*sahead)->next;
		}
		return ;
	}
	*new = ((*new)->next = *temp);
}

static int	shift_i(char **av, int i)
{
	if (av[1][i] == 32)
		while (av[1][i] == 32)
				i++;
	while ((char)av[1][i] != 32 && av[1][i])
		i++;
	return (i);
}

int	createnewlistfromstr(char **av, int i, int stop, int start)
{
	unsigned int	num;
	int				sign;	

	i = 0;
	start = i;
	num = 0;
	sign = 1;
	if (av[1][i])
	{
		num = 0;
		i = shift_i(av, i);
		stop = i;
		while (start < stop)
		{
			if (av[1][start] == '-')
			{
				sign *= -1;
				start++;
			}
			num = num * 10 + ((char)av[1][start] - 48);
			start++;
		}
	}
	return (num * sign);
}

void	create_fromarg(t_stack **sahead, t_stack *new, char **av, int set)
{
	int				start;
	int				i;
	unsigned int	num;
	int				sign;
	t_stack			*temp;

	i = 0;
	start = i;
	while (av[1][i])
	{
		sign = 1;
		i = shift_i(av, i);
		num = retnum(&start, i, sign, av);
		start++;
		while (av[1][start] == 32)
			start++;
		if (set != 0)
		{
			temp = createnewlst(num * sign);
			al_vals(&new, sahead, &temp);
			if (!(av[1][i]))
				new->next = NULL;
		}
		set = 1;
	}
}

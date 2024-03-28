/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/28 16:52:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack **head_a)
{
	t_stack	*temp;

	while (*head_a)
	{
		temp = (*head_a)->next;
		free(*head_a);
		*head_a = temp;
	}
}

void	ft_msgerror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	is_all_digit(char **str)
{
	int		i;
	int		j;
	bool	is_negative;

	i = 0;
	while (str[i])
	{
		j = 0;
		is_negative = false;
		if (str[i][0] == '-' || str[i][0] == '+')
		{
			is_negative = true;
			j++;
		}
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9') && str[i][j] != ' ')
				ft_msgerror();
			j++;
		}
		if (is_negative && j == 1)
			ft_msgerror();
		i++;
	}
	return (1);
}

void	*parser_args(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_all_digit(&argv[i]))
			return (NULL);
		i++;
	}
	return ((void *)1);
}

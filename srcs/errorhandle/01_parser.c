/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:23:01 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	freeall(t_stack **head_a)
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

void	*paser_args(char *argv[], int argc)
{
	int	i;
	int	j;
	int	has_number;
	int	inside_quotes;

	i = 1;
	while (i < argc)
	{
		j = 0;
		has_number = 0;
		inside_quotes = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '"')
			{
				inside_quotes = !inside_quotes;
				j++;
				continue ;
			}
			if (inside_quotes || (argv[i][j] != ' ' && argv[i][j] != '\t'))
			{
				if (argv[i][j] == '-' && j == 0)
				{
					j++;
					continue ;
				}
				if (!ft_isdigit(argv[i][j]))
					return (NULL);
				has_number = 1;
			}
			j++;
		}
		if (!has_number)
			return (NULL);
		i++;
	}
	return ((void *)1);
}

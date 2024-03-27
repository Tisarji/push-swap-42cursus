/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/27 17:46:20 by jikarunw         ###   ########.fr       */
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

static int	is_all_digit(char *str)
{
	int	i;
	int	digits;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	digits = 0;
	while ((str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i]))
	{
		i++;
		digits++;
	}
	if (str[i] || digits == 0 || digits > 10)
		return (0);
	return (1);
}

void	*parser_args(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_all_digit(argv[i]))
			return (NULL);
		i++;
	}
	return ((void *)1);
}

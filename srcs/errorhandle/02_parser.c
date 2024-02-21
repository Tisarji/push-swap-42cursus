/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:07 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/07 12:33:42 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty_or_space(const char *str)
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

void	empty_string(int argc, char **argv)
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

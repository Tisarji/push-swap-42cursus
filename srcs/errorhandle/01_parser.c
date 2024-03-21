/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:44:49 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	errormsg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	*parseargs(char **argv, int argc)
{
	int	i;
	int	d;

	i = 1;
	while (i < argc)
	{
		d = 0;
		while (argv[i][d] != '\0')
		{
			if (!(ft_isdigit(argv[i][d])))
				return (NULL);
			d++;
		}
		i++;
	}
	return ((void *)1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:51:41 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/19 22:57:34 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

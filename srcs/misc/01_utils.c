/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:48 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 18:19:17 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_msgerror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	init_stack(t_stack *stack_b, int **sort)
{
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->node = 0;
	*sort = NULL;
}

int	get_size_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i + 1);
}

int	generate_range(int size)
{
	int	nrange;

	nrange = 1;
	if (size < 50)
		nrange = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		nrange = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		nrange = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		nrange = 27 + (size - 350) / 15;
	else if (size > 500)
		nrange = 37 + (size - 500) / 20;
	return (nrange);
}

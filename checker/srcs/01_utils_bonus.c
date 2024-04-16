/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:43 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:37:47 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->node = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->node = 0;
}

void	ft_msgerror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	get_str_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i + 1);
}

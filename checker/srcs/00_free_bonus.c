/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:45 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:35:26 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	free_2d_array(char **array, int size)
{
	--size;
	while (size >= 0)
	{
		free(array[size]);
		array[size] = NULL;
		--size;
	}
	free(array);
	array = NULL;
}

void	free_and_exit(char **array, int size, char *msg)
{
	free_2d_array(array, size);
	ft_msgerror(msg);
}

void	free_list_and_exit(t_stack *stack, int *array, int i)
{
	int		j;
	t_lst	*temp;

	j = -1;
	free(array);
	while (++j < i)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	ft_msgerror("Error\n");
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_lst	*temp;

	if (stack_a->head)
	{
		i = -1;
		while (++i < stack_a->node)
		{
			temp = stack_a->head;
			stack_a->head = stack_a->head->next;
			free(temp);
		}
	}
	if (stack_b->head)
	{
		i = -1;
		while (++i < stack_b->node)
		{
			temp = stack_b->head;
			stack_b->head = stack_b->head->next;
			free(temp);
		}
	}
}

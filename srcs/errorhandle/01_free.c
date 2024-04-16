/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:13 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/15 12:53:32 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(int *un_order, int *sort, char *msg)
{
	free(un_order);
	free(sort);
	ft_msgerror(msg);
}

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

void	free_list_and_exit(t_stack *stack, int *array[], int i)
{
	int		j;
	t_lst	*temp;

	j = -1;
	free(array[0]);
	free(array[1]);
	while (++j < i)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	ft_msgerror("Error\n");
}

void	free_stack_and_array(t_stack *stack_a, t_stack *stack_b, int *array1, int *array2)
{
	t_lst	*temp;
	int		i;

	i = -1;
	while (++i < stack_a->node)
	{
		temp = stack_a->head;
		stack_a->head = stack_a->head->next;
		free(temp);
	}
	if (stack_b->head)
	{
		i = -1;
		while (++i < stack_a->node)
		{
			temp = stack_a->head;
			stack_a->head = stack_a->head->next;
			free(temp);
		}
	}
	free(array1);
	free(array2);
}

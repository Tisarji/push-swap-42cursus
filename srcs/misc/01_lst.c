/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:37:58 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 12:10:26 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_index(int *array, int value, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == value)
			return (i);
	}
	return (0);
}

t_lst	*make_lst(t_stack *stack, int *array[], int size, int i)
{
	t_lst	*new_lst;
	t_lst	*temp_head;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		free_list_and_exit(stack, array, i);
	if (i == 0)
	{
		new_lst->value = array[0][0];
		new_lst->idx = find_index(array[1], new_lst->value, size);
		new_lst->prev = NULL;
	}
	else
	{
		temp_head = stack->head;
		while (temp_head->next != NULL)
			temp_head = temp_head->next;
		new_lst->value = array[0][i];
		new_lst->idx = find_index(array[1], new_lst->value, size);
		temp_head->next = new_lst;
		new_lst->prev = temp_head;
	}
	stack->tail = new_lst;
	new_lst->next = NULL;
	return (new_lst);
}

void	make_stack_a(t_stack *stack, int *un_order, int *sort, int size)
{
	int	i;
	int	*array[2];

	stack->head = NULL;
	stack->tail = NULL;
	array[0] = un_order;
	array[1] = sort;
	stack->head = make_lst(stack, array, size, 0);
	i = 0;
	while (++i < size)
		make_lst(stack, array, size, i);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->node = size;
}

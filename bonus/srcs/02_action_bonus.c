/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:40 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:30:08 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->node <= 1)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void	rotate_stack(t_stack *stack)
{
	if (stack->node <= 1)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->node <= 1)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	push_stack_01(t_stack *from)
{
	if (from->node == 1)
	{
		free(from->head);
		from->head = NULL;
		from->tail = NULL;
	}
	else if (from->node == 2)
	{
		from->tail->next = NULL;
		from->tail->prev = NULL;
		free(from->head);
		from->head = from->tail;
	}
	else
	{
		from->head->next->prev = from->tail;
		from->tail->next = from->head->next;
		free(from->head);
		from->head = from->tail->next;
	}
	--from->node;
}

void	push_stack(t_stack *from, t_stack *to)
{
	t_lst	*new_lst;

	if (!from->head)
		return ;
	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		ft_msgerror("Error\n");
	++to->node;
	new_lst->value = from->head->value;
	if (!to->head)
	{
		new_lst->next = NULL;
		new_lst->prev = NULL;
		to->head = new_lst;
		to->tail = new_lst;
	}
	else
	{
		new_lst->next = to->head;
		new_lst->prev = to->tail;
		to->head->prev = new_lst;
		to->head = new_lst;
		to->tail->next = to->head;
	}
	push_stack_01(from);
}

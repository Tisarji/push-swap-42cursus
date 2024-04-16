/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:01:10 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/15 20:30:24 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack(t_stack *stack, char *action_msg)
{
	int	temp;

	ft_printf("%s\n", action_msg);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	temp = stack->head->idx;
	stack->head->idx = stack->head->next->idx;
	stack->head->next->idx = temp;
}

void	rotate_stack(t_stack *stack, char *action_msg)
{
	if (stack->node <= 1)
		return ;
	ft_printf("%s\n", action_msg);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	reverse_rotate_stack(t_stack *stack, char *action_msg)
{
	ft_printf("%s\n", action_msg);
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	push_stack_01(t_stack *form, char *action_msg)
{
	if (form->node == 1)
	{
		free(form->head);
		form->head = NULL;
		form->tail = NULL;
	}
	else if (form->node == 2)
	{
		form->tail->next = NULL;
		form->tail->prev = NULL;
		free(form->head);
		form->head = form->tail;
	}
	else
	{
		form->head->next->prev = form->tail;
		form->tail->next = form->head->next;
		free(form->head);
		form->head = form->tail->next;
	}
	--form->node;
	ft_printf("%s\n", action_msg);
}

void	push_stack(t_stack *form, t_stack *to, char *action_msg)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		ft_msgerror("Error\n");
	++to->node;
	new_lst->value = form->head->value;
	new_lst->idx = form->head->idx;
	if (to->head == NULL)
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
	push_stack_01(form, action_msg);
}

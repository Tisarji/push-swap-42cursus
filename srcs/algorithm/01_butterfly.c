/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:20:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 18:15:17 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->idx == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					reverse_rotate_stack(stack_a, "rra");
			}
			else
				while (i-- > 0)
					rotate_stack(stack_a, "ra");
			break;
		}
		++i;
		lst = lst->next;
		if (lst == stack_a->head)
			is_tail = 1;
	}
}

void	find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->idx == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					reverse_rotate_stack(stack_b, "rrb");
			}
			else
				while (i-- > 0)
					rotate_stack(stack_b, "rb");
			break;
		}
		++i;
		lst = lst->next;
		if (lst == stack_b->head)
			is_tail = 1;
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*lst;

	while (stack_b->head != NULL)
	{
		lst = stack_b->head;
		find_max_and_push_a(lst, stack_b, stack_b->node);
		push_stack(stack_b, stack_a, "pa");
	}
}

void	make_butterfly(t_stack *stack_a, t_stack *stack_b, int nrange)
{
	int		count;
	t_lst	*lst;

	count = 0;
	lst = stack_a->head;
	while (stack_a->head != NULL)
	{
		if (lst->idx <= count)
		{
			push_stack(stack_a, stack_b, "pb");
			rotate_stack(stack_b, "rb");
			++count;
		}
		else if (lst->idx <= count + nrange)
		{
			push_stack(stack_a, stack_b, "pb");
			++count;
		}
		else
			rotate_stack(stack_a, "ra");
		lst = stack_a->head;
	}
}

void	butterfly_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	nrange;

	nrange = generate_range(size);
	make_butterfly(stack_a, stack_b, nrange);
	sort_stack(stack_a, stack_b);
}

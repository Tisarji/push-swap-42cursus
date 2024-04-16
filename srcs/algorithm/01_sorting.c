/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:18:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 18:10:28 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	double_sort(int *un_order, int *sort)
{
	write(1, "sa\n", 3);
	ft_free(un_order, sort, "");
}

void	triple_sort(t_stack *stack_a)
{
	int	arr[3];

	arr[0] = stack_a->head->idx;
	arr[1] = stack_a->head->next->idx;
	arr[2] = stack_a->head->next->next->idx;
	if (arr[0] == 0 && arr[1] == 2)
	{
		reverse_rotate_stack(stack_a, "rra");
		swap_stack(stack_a, "sa");
	}
	else if (arr[0] == 0 && arr[1] == 1)
		return ;
	else if (arr[0] == 1 && arr[1] == 0)
		swap_stack(stack_a, "sa");
	else if (arr[0] == 1 && arr[1] == 2)
		reverse_rotate_stack(stack_a, "rra");
	else if (arr[0] == 2 && arr[1] == 0)
		rotate_stack(stack_a, "ra");
	else if (arr[0] == 2 && arr[1] == 1)
	{
		swap_stack(stack_a, "sa");
		reverse_rotate_stack(stack_a, "rra");
	}
}

void	four_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst	*lst;

	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void	five_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst	*lst;

	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size - 1);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void	sorting(int size, t_stack *stack_a, t_stack *stack_b)
{
	if (size == 3)
		triple_sort(stack_a);
	else if (size == 4)
		four_sort(stack_a, stack_b, size);
	else
		five_sort(stack_a, stack_b, size);
}

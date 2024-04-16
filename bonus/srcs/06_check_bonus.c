/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:35:38 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sorted_exit(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	free_stack(stack_a, stack_b);
	ft_printf("%s\n", msg);
	exit(EXIT_SUCCESS);
}

void	is_sorted_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*temp;

	if (stack_b->node > 0)
		sorted_exit(stack_a, stack_b, "KO");
	if (stack_a->node == 1)
		sorted_exit(stack_a, stack_b, "OK");
	temp = stack_a->head;
	while (temp != stack_a->tail)
	{
		if (temp->value >= temp->next->value)
			sorted_exit(stack_a, stack_b, "KO");
		temp = temp->next;
	}
	sorted_exit(stack_a, stack_b, "OK");
}

void	do_inst(char *inst, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		swap_stack(stack_a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		swap_stack(stack_b);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		ss_stack(stack_a, stack_b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		rotate_stack(stack_a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		rotate_stack(stack_b);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		rr_stack(stack_a, stack_b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		reverse_rotate_stack(stack_a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		reverse_rotate_stack(stack_b);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		rrr_stack(stack_a, stack_b);
}

int	check_inst(char *inst)
{
	if (inst[0] == '\0')
		return (2);
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "sb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "ss\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "pa\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "pb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "ra\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rr\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rra\n", 4) == 0)
		return (0);
	if (ft_strncmp(inst, "rrb\n", 4) == 0)
		return (0);
	if (ft_strncmp(inst, "rrr\n", 4) == 0)
		return (0);
	return (1);
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (check_inst(inst) == 2)
			break ;
		if (check_inst(inst) == 1)
		{
			free_stack(stack_a, stack_b);
			ft_msgerror("Error\n");
		}
		do_inst(inst, stack_a, stack_b);
		free(inst);
		inst = get_next_line(0);
	}
	is_sorted_stack(stack_a, stack_b);
}

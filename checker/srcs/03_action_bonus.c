/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:37 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:35:05 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ss_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}

void	rr_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rrr_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}

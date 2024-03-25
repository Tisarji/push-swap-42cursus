/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:20:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:10:06 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_rb(t_stack ***stack_a, t_stack ***stack_b, int max, int *rbcount)
{
	while ((*rbcount) > 0)
	{
		max = ft_isbiggest(**stack_b);
		if (ft_stacksize(**stack_b) > 2)
			ft_rrb(*stack_b);
		if ((**stack_b)->nbr == max)
			ft_pa(*stack_a, *stack_b);
		(*rbcount)--;
	}
	return (*rbcount);
}

void	if_secondpos(t_stack ***stack_a, t_stack ***stack_b, int *secondpos)
{
	if (*secondpos > 0)
	{
		ft_pb(*stack_a, *stack_b);
		ft_sb(*stack_b);
		*secondpos = 0;
	}
	ft_pa(*stack_a, *stack_b);
	if (**stack_b)
		if ((**stack_b)->nbr == ft_isbiggest(**stack_b))
			ft_pa(*stack_a, *stack_b);
}

int	foundsecond_pos(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_pa(*stack_a, *stack_b);
	return (1);
}

void	ft_prox_bymax(t_stack **stack_a, t_stack **stack_b, int rbcount)
{
	int	max;
	int	secondbiggest;
	int	secondpos;

	secondpos = 0;
	rbcount = 0;
	if (ft_stacksize(*stack_b) > 1)
		secondbiggest = sec_largest(*stack_b);
	while (*stack_b)
	{
		max = ft_isbiggest(*stack_b);
		if ((*stack_b)->nbr != max)
		{
			if ((*stack_b)->nbr == secondbiggest)
				secondpos = foundsecond_pos(&stack_a, &stack_b);
			ft_rb(stack_b);
			rbcount++;
		}
		else
		{
			if_secondpos(&stack_a, &stack_b, &secondpos);
			if (rbcount > 0 && ft_stacksize(*stack_b) > 2)
				rbcount = reverse_rb(&stack_a, &stack_b, max, &rbcount);
		}
	}
}

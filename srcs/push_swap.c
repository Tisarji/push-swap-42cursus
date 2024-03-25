/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:23:53 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_check_arg(&stack_a, argc, argv);
	if (!ft_check(stack_a))
		sort_stack(&stack_a, &stack_b);
	freeall(&stack_a);
	freeall(&stack_b);
	return (0);
}

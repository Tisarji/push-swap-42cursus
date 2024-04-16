/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:17:25 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:38:43 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	int		num_count;
	int		*un_order;
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a, &stack_b);
	num_count = check_args(argc, argv);
	un_order = get_num(num_count, argv);
	check_duplicates(un_order, num_count);
	make_stack_a(&stack_a, un_order, num_count);
	free(un_order);
	checker(&stack_a, &stack_b);
	return (0);
}

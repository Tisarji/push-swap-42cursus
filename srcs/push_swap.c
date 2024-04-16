/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/15 00:55:09 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		num_count;
	int		*un_order;
	int		*sort;
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_b, &sort);
	num_count = parser_args(argc, argv);
	un_order = get_num(num_count, argv);
	check_duplicates(un_order, num_count);
	if (is_sorted(un_order, num_count))
		ft_free(un_order, sort, "");
	sort = copy_into_sorted(un_order, num_count);
	if (num_count == 2)
		double_sort(un_order, sort);
	else if (num_count >= 3)
	{
		make_stack_a(&stack_a, un_order, sort, num_count);
		if (num_count >= 3 && num_count <= 5)
			sorting(num_count, &stack_a, &stack_b);
		else
			butterfly_sort(&stack_a, &stack_b, num_count);
	}
	free_stack_and_array(&stack_a, &stack_b, un_order, sort);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:09:59 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/15 22:14:46 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_bigger(long num, t_stack *b)
{
	int		i;

	if (!b)
		return (0);
	while (b->next)
	{
		if (num > b->num)
			b = b->next;
	}
}

t_stack	*ft_start_process(t_stack **a, t_stack **b)
{
	int		i;

	i = 0;

	push_b(a, b);
	push_b(a, b);
	
	if(ft_is_bigger((*a)->num, *b))
}

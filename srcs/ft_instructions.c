/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:15:50 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/15 22:18:44 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp_next

	if (!(*a) || !a)
		return ;
	tmp = *a;
	tmp_next = (*a)->next;
	(*a) = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = tmp_next;
}

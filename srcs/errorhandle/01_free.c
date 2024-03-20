/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:34:15 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/20 15:23:12 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_data(t_data **data)
{
	int		i;

	i = -1;
	while ((*data)->split_str && (*data)->split_str[++i])
	{
		free((*data)->split_str[i]);
		(*data)->split_str[i] = 0;
	}
	free((*data)->split_str);
	(*data)->split_str = 0;
	free((*data)->join_str);
	(*data)->join_str = 0;
	free(*data);
	*data = NULL;
}

void	free_lst(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	while (*lst_a)
	{
		tmp = (*lst_a)->next;
		free(*lst_a);
		(*lst_a) = tmp;
	}
	free(*lst_a);
	while (*lst_b)
	{
		tmp = (*lst_b)->next;
		free(*lst_b);
		(*lst_b) = tmp;
	}
	free(*lst_b);
}

void	free_stack(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

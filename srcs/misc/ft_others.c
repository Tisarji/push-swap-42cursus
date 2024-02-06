/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:48 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/06 10:49:11 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max(t_stack **lst)
{
	int		i;
	int		j;
	int		max;
	t_stack	*node;

	i = 0;
	j = 0;
	node = *lst;
	max = node->idx;
	node = node->next;
	while (node)
	{
		if (max < node->idx)
		{
			max = node->idx;
			node = node->next;
			j = ++i;
		}
		else
		{
			node = node->next;
			i++;
		}
	}
	return (j);
}

int	issorted_detals(t_stack **lst_a, t_stack **lst_b, t_data *data)
{
	if (check_issorted(lst_a) == 1)
	{
		index_1(lst_a);
		index_lst(lst_a, data->len);
		data->lst_len = ft_lstlen(*lst_a);
		sort_lst(lst_a, lst_b, data->lst_len);
	}
	return (0);
}

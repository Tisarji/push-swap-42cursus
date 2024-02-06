/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:07:51 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/06 10:49:18 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*append(t_stack **head, int new_data)
{
	t_stack	*tmp;
	t_stack	*new_node;
	t_stack	*last_node;

	last_node = 0;
	new_node = malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		last_node = *head;
		tmp = last_node;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		last_node->next->next = 0;
		last_node = tmp;
	}
	return (last_node);
}

void	index_1(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	while (temp)
	{
		temp->idx = -1;
		temp = temp->next;
	}
}

void	fill_lst(t_stack **lst, char **num, int *len)
{
	int		i;
	int		n;
	t_stack	*node;

	i = 0;
	node = 0;
	while (num[i])
	{
		n = ft_atoi_ps(num[i]);
		node = append(&node, n);
		i++;
	}
	(*len) = i;
	*lst = node;
}

void	index_lst(t_stack **lst, int len)
{
	t_stack	*node;
	t_stack	*max;
	int		i;

	i = 0;
	node = (*lst)->next;
	max = *lst;
	index_1(lst);
	while (i < len)
	{
		while (node != NULL)
		{
			if (max->data > node->data && node->idx == -1)
				max = node;
			node = node->next;
		}
		max->idx = i;
		max = *lst;
		node = *lst;
		i++;
		while (i < len && max->idx != -1 && max->next != NULL)
		{
			max = max->next;
		}
	}
}

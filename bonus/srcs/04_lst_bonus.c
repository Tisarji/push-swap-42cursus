/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:35 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:23:01 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_lst	*make_lst(t_stack *stack, int *un_order, int i)
{
	t_lst	*new_lst;
	t_lst	*temp_head;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		free_list_and_exit(stack, un_order, i);
	if (i == 0)
	{
		new_lst->value = un_order[0];
		new_lst->prev = NULL;
	}
	else
	{
		temp_head = stack->head;
		while (temp_head->next)
			temp_head = temp_head->next;
		new_lst->value = un_order[i];
		temp_head->next = new_lst;
		new_lst->prev = temp_head;
	}
	stack->tail = new_lst;
	new_lst->next = NULL;
	return (new_lst);
}

void	make_stack_a(t_stack *stack, int *un_order, int size)
{
	int	i;

	stack->head = NULL;
	stack->tail = NULL;
	stack->head = make_lst(stack, un_order, 0);
	i = 0;
	while (++i < size)
		make_lst(stack, un_order, i);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->node = size;
}

int	*get_num(int num_count, char **argv)
{
	int		*num;
	char	**temp;
	int		idx[3];

	idx[0] = 0;
	idx[2] = -1;
	num = (int *)malloc(sizeof(int) * num_count);
	if (!num)
		ft_msgerror("Error\n");
	while (argv[++idx[0]])
	{
		temp = ft_split(argv[idx[0]], ' ');
		if (!temp)
			ft_msgerror("Error\n");
		else if (!temp[0])
			free_2d_array(temp, 1);
		else
		{
			idx[1] = -1;
			while (temp[++idx[1]])
				num[++idx[2]] = ft_atoi(temp[idx[1]]);
			free_2d_array(temp, get_str_size(temp));
		}
	}
	return (num);
}

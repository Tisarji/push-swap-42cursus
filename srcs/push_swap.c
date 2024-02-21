/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/02/22 03:44:51 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	alg(t_stack **lst_a, t_stack **lst_b, t_data *data)
{
	data->split_str = ft_split(data->join_str, ' ');
	if (!data->split_str[0])
		return ;
	check_char(data->split_str);
	check_valid(data->split_str);
	fill_lst(lst_a, data->split_str, &data->len);
	check_dublicates(lst_a);
	issorted_detals(lst_a, lst_b, data);
}

static void	init_handle(int argc, char **argv, t_data *data)
{
	data->join_str = NULL;
	data->split_str = 0;
	empty_string(argc, argv);
}

int	main(int argc, char *argv[])
{
	t_data			*data;
	t_stack			*lst_a;
	t_stack			*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	data = malloc(sizeof(t_data));
	init_handle(argc, argv, data);
	if (argc > 1)
	{
		data->i = 1;
		while (argv[data->i])
		{
			data->join_str = ft_strjoin(data->join_str, argv[data->i]);
			data->join_str = ft_strjoin(data->join_str, " ");
			data->i++;
		}
		alg(&lst_a, &lst_b, data);
		free_lst(&lst_a, &lst_b);
	}
	free_data(&data);
	return (0);
}

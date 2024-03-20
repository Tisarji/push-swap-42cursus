/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:11:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/20 14:45:24 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	alg(t_stack **lst_a, t_stack **lst_b, t_data *data, int argc, char *argv[])
{
	data->split_str = ft_split(data->join_str, ' ');
	if (!data->split_str[0])
		return ;
	fill_lst(lst_a, data->split_str, &data->len);
	all_checks(lst_a, argc, argv);
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
	t_data		*data;
	t_stack		*lst_a;
	t_stack		*lst_b;

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
		alg(&lst_a, &lst_b, data, argc, argv);
		free_lst(&lst_a, &lst_b);
	}
	free_data(&data);
	return (0);
}

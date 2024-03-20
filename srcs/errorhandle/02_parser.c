/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:07 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/20 14:45:07 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty_or_space(const char *str)
{
	if (ft_strlen(str) == 0)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	empty_string(int argc, char **argv)
{
	int	i;
	int	count;
	int	error;

	i = 0;
	count = 0;
	error = 0;
	while (argc > ++i)
	{
		if (is_empty_or_space(argv[i]))
			error++;
		else
			count++;
	}
	if ((error > 0 && count > 0) || (argc >= 2 && error > 0))
		ft_error("Error: Empty String found", 0);
	else if (error > 0 && count == 0)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	free_and_exit(t_stack *lst_a, t_stack *lst_b, char **arguments,
		int argc)
{
	if (argc == 2)
		free(arguments);
	free_lst(&lst_a, &lst_b);
	exit(0);
}

void	all_checks(t_stack **lst_a, int argc, char *argv[])
{
	if (argc == 1 || check_char(argc, argv) == NULL)
		ft_error("Error: Invaild", 0);
	if (*lst_a)
	{
		if (!(check_dublicates(*lst_a)))
		{
			free_stack(lst_a);
			ft_error("Error: Duplicate", 0);
		}
	}
}

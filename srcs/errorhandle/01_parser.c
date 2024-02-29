/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/01 02:33:34 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_msgerror(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (1);
}

int	check_char(char **str)
{
	int		i;
	int		j;
	bool	is_negative;

	i = 0;
	while (str[i])
	{
		j = 0;
		is_negative = false;
		if (str[i][0] == '-')
		{
			is_negative = true;
			j++;
		}
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				ft_msgerror();
			j++;
		}
		if (is_negative && j == 1)
			ft_msgerror();
		i++;
	}
	return (0);
}

int	check_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-')
						&& j != 0)
				ft_msgerror();
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dublicates(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*ptr;

	tmp = *head;
	while (*head)
	{
		ptr = (*head)->next;
		while (ptr)
		{
			if (ptr->data == (*head)->data)
				ft_msgerror();
			ptr = ptr->next;
		}
		ptr = (*head)->next;
		*head = ptr;
	}
	*head = tmp;
	return (0);
}

int	check_issorted(t_stack **lst)
{
	int		num;
	t_stack	*tmp;
	t_stack	*tmp_num;

	tmp = *lst;
	while (*lst)
	{
		num = (*lst)->data;
		tmp_num = (*lst)->next;
		*lst = tmp_num;
		while (*lst)
		{
			if (num > (*lst)->data)
			{
				*lst = tmp;
				return (1);
			}
			*lst = (*lst)->next;
		}
		*lst = tmp_num;
	}
	*lst = tmp;
	return (0);
}

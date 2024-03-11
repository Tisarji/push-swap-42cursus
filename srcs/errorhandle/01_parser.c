/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:10:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/11 12:53:51 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_msgerror(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_char(char **str)
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
				ft_error("Error : Bad Input exit 0", 1, str);
			j++;
		}
		if (is_negative && j == 1)
			ft_error("Error: Bad Input exit 1", 1, str);
		i++;
	}
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
				ft_error("Error: Bad Input exit 2", 0);
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

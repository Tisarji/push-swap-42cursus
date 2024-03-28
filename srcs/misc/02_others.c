/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:29:55 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/28 16:53:58 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long int	ft_atoi_ps(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (result * sign > 2147483647 || result * sign < -2147483648 || i > 13)
		ft_msgerror();
	return (result * sign);
}

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_check(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->nbr > lst->next->nbr)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

int	ft_isbiggest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->nbr;
	while (lst)
	{
		if (lst->nbr > i)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}

int	ft_issmallest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->nbr;
	while (lst)
	{
		if (lst->nbr < i)
			i = lst->nbr;
		lst = lst->next;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:49 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/18 17:16:45 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int num)
{
	int	digit;
	int	temp;
	int	div;

	digit = 0;
	if (num == INT_MIN)
		return (ft_printf_string("-2147483648"));
	else if (num < 0)
	{
		digit += ft_printf_char('-');
		num *= -1;
	}
	temp = num;
	div = 1;
	while (temp >= 10)
	{
		temp /= 10;
		div *= 10;
	}
	while (div > 0)
	{
		digit += ft_printf_char('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (digit);
}

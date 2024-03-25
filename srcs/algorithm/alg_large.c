/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_large.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:00:20 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:07:15 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_findquarter_original(int *array, int size, int i)
{
	return (array[((size / 7) * i)] - 1);
}

static int	crudesort(int ***sorted, int i)
{
	int	temp;

	temp = 0;
	if ((**sorted)[i] <= (**sorted)[i + 1])
		i++;
	else
	{
		temp = (**sorted)[i];
		(**sorted)[i] = (**sorted)[i + 1];
		(**sorted)[i + 1] = temp;
		i = 0;
	}
	return (i);
}

int	ft_sortarray_original(t_stack *lst, int **sorted, int size)
{
	int	i;

	i = 0;
	size = ft_stacksize(lst);
	while (i < size)
	{
		(*sorted)[i] = lst->nbr;
		lst = lst->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
		i = crudesort(&sorted, i);
	return (i);
}

void	algorithm_large(t_stack **head_a, t_stack **head_b, int x)
{
	int	size;
	int	*original;
	int	keynum;

	original = NULL;
	x = 1;
	if (*head_a)
		original = (int *)malloc(ft_stacksize(*head_a) * sizeof(int));
	else
		ft_msgerror();
	if (!original)
		return ;
	size = ft_stacksize(*head_a);
	ft_sortarray_original(*head_a, &original, size);
	while (x < 7)
	{
		keynum = ft_findquarter_original(original, size, x);
		ft_prox_bykey(head_a, head_b, keynum, x);
		x++;
	}
	sort_a(head_a, head_b);
	if (*head_b)
		ft_prox_bymax(head_a, head_b, keynum);
	free(original);
}

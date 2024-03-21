/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_large.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:00:20 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:42:49 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	reverse_rb(t_stack ***a, t_stack ***b, int max, int *rbcount)
{
	while ((*rbcount) > 0)
	{
		max = ft_isbiggest(**b);
		if (ft_stacksize(**b) > 2)
			ft_rrb(*b);
		if ((**b)->nbr == max)
			ft_pa(*a, *b);
		(*rbcount)--;
	}
	return (*rbcount);
}

static void	if_secondpos(t_stack ***a, t_stack ***b, int *secondpos)
{
	if (*secondpos > 0)
	{
		ft_pb(*a, *b);
		ft_sb(*b);
		*secondpos = 0;
	}
	ft_pa(*a, *b);
	if (**b)
		if ((**b)->nbr == ft_isbiggest(**b))
			ft_pa(*a, *b);
}

static int	foundsecond_pos(t_stack ***a, t_stack ***b)
{
	ft_pa(*a, *b);
	return (1);
}

static void	ft_prox_bymax(t_stack **a, t_stack **b, int rbcount)
{
	int	max;
	int	secondbiggest;
	int	secondpos;

	secondpos = 0;
	rbcount = 0;
	if (ft_stacksize(*b) > 1)
		secondbiggest = sec_largest(*b);
	while (*b)
	{
		max = ft_isbiggest(*b);
		if ((*b)->nbr != max)
		{
			if ((*b)->nbr == secondbiggest)
				secondpos = foundsecond_pos(&a, &b);
			ft_rb(b);
			rbcount++;
		}
		else
		{
			if_secondpos(&a, &b, &secondpos);
			if (rbcount > 0 && ft_stacksize(*b) > 2)
				rbcount = reverse_rb(&a, &b, max, &rbcount);
		}
	}
}

void	algorithm_large(t_stack **a, t_stack **b, int x)
{
	int	size;
	int	*original;
	int	keynum;

	original = NULL;
	x = 1;
	if (*a)
		original = (int *)malloc(ft_stacksize(*a) * sizeof(int));
	else
		errormsg();
	if (!original)
		return ;
	size = ft_stacksize(*a);
	ft_sortarray_original(*a, &original, size);
	while (x < 7)
	{
		keynum = ft_findquarter_original(original, size, x);
		ft_prox_bykey(a, b, keynum, x);
		x++;
	}
	sort_a(a, b);
	if (*b)
		ft_prox_bymax(a, b, keynum);
	free(original);
}

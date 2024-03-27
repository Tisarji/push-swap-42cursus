/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:38:44 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/26 12:00:50 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	assign_indexes(t_stack **lst2)
{
	int			size;
	int			size_backup;
	int			i;
	int			*sortedarray;
	t_stack		*lst;

	lst = *lst2;
	sortedarray = ft_sortcomplete(lst);
	size = ft_stacksize(lst);
	size_backup = size;
	i = 0;
	while ((i < size))
	{
		(*lst2)->idx = ft_getindex(sortedarray, (*lst2)->nbr, size_backup);
		(*lst2) = (*lst2)->next;
		i++;
	}
	free (sortedarray);
}

t_stack	*create_lst(int nbr)
{
	t_stack	*newlist;

	if (nbr < INT_MIN)
	{
		ft_msgerror();
		exit(EXIT_FAILURE);
	}
	newlist = (t_stack *)malloc(sizeof(t_stack));
	if (!newlist)
		newlist = NULL;
	newlist->nbr = nbr;
	newlist->idx = 0;
	newlist->next = NULL;
	return (newlist);
}

void	createt_stack_nodes(t_stack **head_a, t_stack *new, \
			char *argv[], int argc)
{
	int		i;
	t_stack	*temp;

	i = 2;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN)
		{
			ft_msgerror();
			exit(EXIT_FAILURE);
		}
		temp = create_lst(ft_atoi(argv[i++]));
		if (!temp)
		{
			while (*head_a)
			{
				free(*head_a);
				*head_a = (*head_a)->next;
			}
			return ;
		}
		new = (new->next = temp);
		if (i == argc - 1)
			new->next = NULL;
	}
}

void	init_stack(t_stack **head_a, char *argv[], int argc)
{
	int		i;
	int		set;
	t_stack	*newlist;
	t_stack	**temp;

	if (argc == 1)
		return ;
	i = 1;
	set = 0;
	if (argc > 2)
	{
		newlist = create_lst(ft_atoi(argv[i]));
		if (!newlist)
			return ;
		createt_stack_nodes(head_a, newlist, argv, argc);
	}
	else
	{
		newlist = create_lst(create_from_str(argv, i, set, 0));
		create_from_arg(head_a, newlist, argv, set);
	}
	(*head_a) = newlist;
	temp = &newlist;
	assign_indexes(temp);
}

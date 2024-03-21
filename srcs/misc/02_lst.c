/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:38:44 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:38:06 by jikarunw         ###   ########.fr       */
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

t_stack	*createnewlst(int nbr)
{
	t_stack	*newlist;

	if (nbr < INT_MIN)
	{
		errormsg();
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

void	createt_stacknodes(t_stack **sahead, t_stack *new, char **av, int ac)
{
	int		i;
	t_stack	*temp;

	i = 2;
	while (i < ac)
	{	
		if (ft_atoi(av[i]) < INT_MIN)
		{
			errormsg();
			exit(EXIT_FAILURE);
		}	
		temp = createnewlst(ft_atoi(av[i++]));
		if (!temp)
		{
			while (*sahead)
			{
				free(*sahead);
				*sahead = (*sahead)->next;
			}
			return ;
		}
		new = (new->next = temp);
		if (i == ac - 1)
			new->next = NULL;
	}
}

void	create_t_stack(t_stack **sahead, char **argv, int argc)
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
		newlist = createnewlst(ft_atoi(argv[i]));
		if (!newlist)
			return ;
		createt_stacknodes(sahead, newlist, argv, argc);
	}
	else
	{
		newlist = createnewlst(createnewlistfromstr(argv, i, set, 0));
		create_fromarg(sahead, newlist, argv, set);
	}
	(*sahead) = newlist;
	temp = &newlist;
	assign_indexes(temp);
}

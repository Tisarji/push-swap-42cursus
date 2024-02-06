/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:18:43 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/22 13:22:00 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	errormsgbonus(void)
{
	write(1, "KO\n", 3);
	exit(EXIT_FAILURE);
}

static void	ft_docommand2(char *line, t_stack **a, t_stack **b, int size)
{
	if (!(ft_strncmp(line, "ra\n", size)))
		ft_ra2(a);
	else if (!(ft_strncmp(line, "rb\n", size)))
		ft_rb2(b);
	else if (!(ft_strncmp(line, "rr\n", size)))
		ft_rr2(a, b);
	else if (!(ft_strncmp(line, "rra\n", size)))
		ft_rra2(a);
	else if (!(ft_strncmp(line, "rrb\n", size)))
		ft_rrb2(b);
	else if (!(ft_strncmp(line, "rrr\n", size)))
		ft_rrr2(a, b);
	else
		errormsgbonus();
}

void	ft_docommand1(char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!(ft_strncmp(line, "pa\n", size)))
		ft_pa2(a, b);
	else if (!(ft_strncmp(line, "pb\n", size)))
		ft_pb2(a, b);
	else if (!(ft_strncmp(line, "sa\n", size)))
		ft_sa2(a);
	else if (!(ft_strncmp(line, "sb\n", size)))
		ft_sb2(b);
	else if (!(ft_strncmp(line, "ss\n", size)))
		ft_ss2(a, b);
	else
		ft_docommand2(line, a, b, size);
	free(line);
}

void	printlist(t_stack *shead)
{
	if (!shead)
		return ;
	while (shead->next != NULL)
	{
		ft_printf("%d\n", shead->data);
		shead = shead->next;
	}
	ft_printf("%d\n", shead->data);
}

int	main(int argc, char *argv[])
{
	t_stack	*sahead;
	t_stack	*sbhead;

	sahead = NULL;
	sbhead = NULL;
	if (argc == 1)
		return (0);
	do_all_checks(&sahead, argc, argv);
	while (get_next_line(0, &sahead, &sbhead))
	{
		if (ft_ordercheck(sahead) && ft_stacksize(sbhead) == 0)
			break ;
	}
	if (ft_ordercheck(sahead) && ft_stacksize(sbhead) == 0)
		write(1, "OK\n", 3);
	else
		errormsgbonus();
}

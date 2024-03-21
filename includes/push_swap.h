/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:46:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/21 23:55:07 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <string.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_stack
{
	int			nbr;
	int			idx;
	struct s_stack	*next;
}				t_stack;

/*********************************************
* SECTION - ALGORITHM SORT "BUTTERFLY SORT" *
*********************************************/

void		algorithm_small(t_stack **lst);
void		algorithm_medium(t_stack **a, t_stack **b);
void		algorithm_large(t_stack **a, t_stack **b, int x);
void		butterfly_split(t_stack **a, t_stack **b, int size);
bool		is_descending_order(t_stack *a);
void		sort_descending(t_stack **a, t_stack **b);
void		sort_stack(t_stack **a, t_stack **b);


void		*parseargs(char **argv, int argc);
void		errormsg(void);

/************************************
* SECTION CREATE STACK FOR SORTING *
************************************/
/******************************
 * SECTION LINKLIST FOR STACK *
 ******************************/

void	create_t_stack(t_stack **sahead, char **argv, int argc);
int		createnewlistfromstr(char **av, int i, int stop, int start);
t_stack		*createnewlst(int nbr);
void		createt_stacknodes(t_stack **sahead, t_stack *new, char **av, int ac);
void		create_t_stack(t_stack **sahead, char **argv, int argc);
int			createnewlistfromstr(char **av, int i, int stop, int start);
void		create_fromarg(t_stack **sahead, t_stack *new, char **av, int set);
void		ft_check_arg(t_stack **a, int argc, char *argv[]);

/*******************
* SECTION - UTILS *
*******************/

int			top_next_cmp(t_stack *lst);
int			mid_bot_cmp(t_stack *lst);
int			top_bot_cmp(t_stack *lst);
int			sec_largest(t_stack *lst);

void		freeall(t_stack **sa);
int			ft_stacksize(t_stack *lst);
int			ft_check(t_stack *lst);
int			ft_isbiggest(t_stack *lst);
int			ft_issmallest(t_stack *lst);
int			findidxpos(t_stack *ls, int max);
int			findpos(t_stack *ls, int num);
int			ft_getindex(int *sorted, int num, int size);
int			*ft_sortcomplete(t_stack *lst);
void		move_min_element(t_stack **a, t_stack **b);
int			ft_findquarter_original(int *array, int size, int i);
int			ft_sortarray_original(t_stack *lst, int **sorted, int size);
void		ft_prox_bykey(t_stack **a, t_stack **b, int keynum, int x);
void		ft_proximity(t_stack **a, t_stack **b);
void		sort_a(t_stack **a, t_stack **b);


/*********************
* SECTION OPARATION *
*********************/

void		ft_sa(t_stack **a);
void		ft_sb(t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);

void		ft_ra(t_stack **a);
void		ft_rb(t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);

void		ft_rra(t_stack **a);
void		ft_rrb(t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);

void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);

#endif

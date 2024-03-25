/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:46:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:38 by jikarunw         ###   ########.fr       */
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
	int				nbr;
	int				idx;
	struct s_stack	*next;
}				t_stack;

/*********************************************
 * SECTION - ALGORITHM SORT "BUTTERFLY SORT" *
 *         PATH: DIR/SRCS/ALGORITHM          *
 *********************************************/

void		algorithm_small(t_stack **lst);
void		algorithm_medium(t_stack **head_a, t_stack **head_b);
void		algorithm_large(t_stack **head_a, t_stack **head_b, int x);
void		butterfly_split(t_stack **head_a, t_stack **head_b, int size);
bool		is_descending_order(t_stack *head_a);
void		sort_descending(t_stack **head_a, t_stack **head_b);
void		sort_stack(t_stack **head_a, t_stack **head_b);
int			reverse_rb(t_stack ***head_a, t_stack ***head_b, \
				int max, int *rbcount);
void		if_secondpos(t_stack ***head_a, t_stack ***head_b, int *secondpos);
int			foundsecond_pos(t_stack ***head_a, t_stack ***head_b);
void		ft_prox_bymax(t_stack **head_a, t_stack **head_b, int rbcount);
int			top_next_cmp(t_stack *lst);
int			mid_bot_cmp(t_stack *lst);
int			top_bot_cmp(t_stack *lst);
int			sec_largest(t_stack *lst);
int			*ft_sortcomplete(t_stack *lst);
void		move_min_element(t_stack **head_a, t_stack **head_b);
int			ft_findquarter_original(int *array, int size, int i);
int			ft_sortarray_original(t_stack *lst, int **sorted, int size);
void		ft_prox_bykey(t_stack **head_a, t_stack **head_b, \
				int keynum, int x);
void		ft_proximity(t_stack **head_a, t_stack **head_b);
void		sort_a(t_stack **head_a, t_stack **head_b);

/******************************
 *   SECTION - ERROR-HANDLE   *
 * PATH: DIR/SRCS/ERRORHANDLE *
 ******************************/

void		*paser_args(char *argv[], int argc);
void		ft_msgerror(void);
void		freeall(t_stack **head_a);

/*******************************
 *   SECTION - INSTRUCTIONS    *
 * PATH: DIR/SRCS/INSTRUCTIONS *
 *******************************/

void		ft_sa(t_stack **head_a);
void		ft_sb(t_stack **head_b);
void		ft_ss(t_stack **head_a, t_stack **head_b);

void		ft_ra(t_stack **head_a);
void		ft_rb(t_stack **head_b);
void		ft_rr(t_stack **head_a, t_stack **head_b);

void		ft_rra(t_stack **head_a);
void		ft_rrb(t_stack **head_b);
void		ft_rrr(t_stack **head_a, t_stack **head_b);

void		ft_pa(t_stack **head_a, t_stack **head_b);
void		ft_pb(t_stack **head_a, t_stack **head_b);

/***********************
 *   SECTION - MISC    *
 * PATH: DIR/SRCS/MISC *
 ***********************/

void		create_t_stack(t_stack **head_a, char **argv, int argc);
int			createnewlistfromstr(char *argv[], int i, int stop, int start);
t_stack		*createnewlst(int nbr);
void		createt_stacknodes(t_stack **head_a, t_stack *new, \
				char *argv[], int argc);
void		create_t_stack(t_stack **head_a, char *argv[], int argc);
int			createnewlistfromstr(char *argv[], int i, int stop, int start);
void		create_fromarg(t_stack **head_a, t_stack *new, \
				char *argv[], int set);
void		ft_check_arg(t_stack **head_a, int argc, char *argv[]);
int			ft_stacksize(t_stack *lst);
int			ft_check(t_stack *lst);
int			ft_isbiggest(t_stack *lst);
int			ft_issmallest(t_stack *lst);
int			findidxpos(t_stack *ls, int max);
int			findpos(t_stack *ls, int num);
int			ft_getindex(int *sorted, int num, int size);

#endif

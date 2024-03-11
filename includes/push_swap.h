/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:46:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/11 12:47:25 by jikarunw         ###   ########.fr       */
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
	int				data;
	int				idx;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	unsigned int	lst_len;
	int				i;
	char			*join_str;
	char			**split_str;
	int				len;
}				t_data;

/*********************************************
* SECTION - ALGORITHM SORT "BUTTERFLY SORT" *
*********************************************/

void			alg(t_stack **lst_a, t_stack **lst_b, t_data *data);
void			butterfly_sort(t_stack **lst_a, t_stack **lst_b, int n);
void			push_lst_a(t_stack **lst_a, t_stack **lst_b, int len);
void			sort_lst(t_stack **lst_a, t_stack **lst_b, int len);
void			sort_2(t_stack **lst_a);
void			sort_3(t_stack **lst_a);
void			sort_4(t_stack **lst_a, t_stack **lst_b);
void			sort_5(t_stack **lst_a, t_stack **lst_b);

/************************************
* SECTION CREATE STACK FOR SORTING *
************************************/
/******************************
 * SECTION LINKlst FOR STACK *
 ******************************/

void			fill_lst(t_stack **lst, char **num, int *len);
void			index_1(t_stack **lst);
t_stack			*append(t_stack **head, int new_data);
void			index_lst(t_stack **lst, int len);

/*******************
* SECTION - UTILS *
*******************/

int				find_max(t_stack **lst);
int				issorted_detals(t_stack **lst_a, \
	t_stack **lst_b, t_data *data);
long int		ft_atoi_ps(const char *str);
unsigned int	ft_lstlen(t_stack *lst);
void			ft_msgerror(void);
void			check_char(char **str);
int				check_issorted(t_stack **lst);
int				check_dublicates(t_stack **head);
size_t			ft_strlen(const char *str);
char			**ft_split(char const *s, char c);
void			empty_string(int argc, char **argv);
void			free_lst(t_stack **lst_a, t_stack **lst_b);
void			free_data(t_data **data);
int				is_empty_or_space(const char *str);

/*********************
* SECTION OPARATION *
*********************/

int				sa(t_stack **lst);
int				sb(t_stack **lst);
int				ss(t_stack **lst_a, t_stack **lst_b);
int				pa(t_stack **lst_a, t_stack **lst_b);
int				pb(t_stack **lst_b, t_stack **lst_a);
int				ra(t_stack **lst_a);
int				rb(t_stack **lst_b);
int				rr(t_stack **lst_a, t_stack **lst_b);
int				rra(t_stack **lst_a);
int				rrb(t_stack **lst_b);
int				rrr(t_stack **lst_a, t_stack **lst_b);

#endif

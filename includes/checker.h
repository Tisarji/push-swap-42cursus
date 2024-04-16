/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:16:12 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 21:05:52 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

typedef struct s_lst
{
	int				value;
	int				idx;
	struct s_lst	*next;
	struct s_lst	*prev;
}			t_lst;

typedef struct s_stack
{
	t_lst	*head;
	t_lst	*tail;
	int		node;
}				t_stack;

/*******************
 * SECTION - UTILS *
 *******************/

void		init_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_msgerror(char *msg);
int			get_str_size(char **str);

/********************
 * SECTION - PARSER *
 ********************/

void		check_duplicates(int *un_order, int size);
void		check_num_01(char *num, char **temp);
void		check_num_02(char *num, char **temp, int *num_count);
int			parser_args(int argc, char *argv[]);
int			get_num_count(char *argv[]);

/******************
 * SECTION - FREE *
 ******************/

void		free_2d_array(char **array, int size);
void		free_and_exit(char **array, int size, char *msg);
void		free_list_and_exit(t_stack *stack, int *array, int i);
void		free_stack(t_stack *stack_a, t_stack *stack_b);

/***********************
 * SECTION - LST_STACK *
 ***********************/

t_lst		*make_lst(t_stack *stack, int *un_order, int i);
void		make_stack_a(t_stack *stack, int *un_order, int size);
int			*get_num(int num_count, char **argv);

/**************************
 * SECTION - ACTION STACK *
 **************************/

void		swap_stack(t_stack *stack);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		push_stack_01(t_stack *form);
void		push_stack(t_stack *form, t_stack *to);

void		ss_stack(t_stack *stack_a, t_stack *stack_b);
void		rr_stack(t_stack *stack_a, t_stack *stack_b);
void		rrr_stack(t_stack *stack_a, t_stack *stack_b);

/*********************
 * SECTION - CHECKER *
 *********************/

void		sorted_exit(t_stack *stack_a, t_stack *stack_b, char *msg);
void		is_sorted_stack(t_stack *stack_a, t_stack *stack_b);
void		do_inst(char *inst, t_stack *stack_a, t_stack *stack_b);
int			check_inst(char *inst);
void		checker(t_stack *stack_a, t_stack *stack_b);

#endif

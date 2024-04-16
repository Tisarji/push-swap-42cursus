/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:46:04 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 12:10:54 by jikarunw         ###   ########.fr       */
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

/*********************************************
 * SECTION - ALGORITHM SORT "BUTTERFLY SORT" *
 *         PATH: DIR/SRCS/ALGORITHM          *
 *********************************************/

void		bubble_sort(int *array, int size);
int			*copy_into_sorted(int *array, int size);
bool		is_sorted(int *array, int size);
int			*get_num(int num_count, char *argv[]);

void		find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size);
void		find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size);
void		sort_stack(t_stack *stack_a, t_stack *stack_b);
void		make_butterfly(t_stack *stack_a, t_stack *stack_b, int nrange);
void		butterfly_sort(t_stack *stack_a, t_stack *stack_b, int size);

void		double_sort(int *un_order, int *sort);
void		triple_sort(t_stack *stack_a);
void		four_sort(t_stack *stack_a, t_stack *stack_b, int size);
void		five_sort(t_stack *stack_a, t_stack *stack_b, int size);
void		sorting(int size, t_stack *stack_a, t_stack *stack_b);

/******************************
 *   SECTION - ERROR-HANDLE   *
 * PATH: DIR/SRCS/ERRORHANDLE *
 ******************************/

void		ft_free(int *un_order, int *sort, char *msg);
void		free_2d_array(char **array, int size);
void		free_and_exit(char **array, int size, char *msg);
void		free_list_and_exit(t_stack *stack, int *array[], int i);
void		free_stack_and_array(t_stack *stack_a, t_stack *stack_b, int *array1, int *array2);

void		check_duplicates(int *un_order, int size);
void		check_num_02(char *num, char **temp, int *num_count);
void		check_num_01(char *num, char **temp);
int			get_num_count(char *argv[]);
int			parser_args(int argc, char *argv[]);

/*******************************
 *   SECTION - INSTRUCTIONS    *
 * PATH: DIR/SRCS/INSTRUCTIONS *
 *******************************/

void		swap_stack(t_stack *stack, char *action_msg);
void		rotate_stack(t_stack *stack, char *action_msg);
void		reverse_rotate_stack(t_stack *stack, char *action_msg);
void		push_stack_01(t_stack *form, char *action_msg);
void		push_stack(t_stack *form, t_stack *to, char *action_msg);

/***********************
 *   SECTION - MISC    *
 * PATH: DIR/SRCS/MISC *
 ***********************/

void		ft_msgerror(char *msg);
int			generate_range(int size);
int			get_size_str(char **str);
void		init_stack(t_stack *stack_b, int **sort);
int			find_index(int *array, int value, int size);
t_lst		*make_lst(t_stack *stack, int *array[], int size, int i);
void		make_stack_a(t_stack *stack, int *un_order, int *sort, int size);

#endif

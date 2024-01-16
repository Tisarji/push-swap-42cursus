/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:01 by jikarunw          #+#    #+#             */
/*   Updated: 2024/01/15 22:09:03 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_find_size(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;;
	while (str[i] != NULL)
	{
		size++;
		i++;
	}
	return (size);
}

int		*ft_parse(char *str, int *size)
{
	int		*nums;
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(str, 32);
	*(size) = ft_find_size(temp);
	nums = (int *)malloc(sizeof(int) * (*size));
	while (i < (*size))
	{
		nums[i] = ft_atoi(temp[i]);
		i++;
	}
	return (nums);
}

t_stack		*ft_add_to_stack(t_stack *a, int *result, int *index, int size)
{
	while (size)
	{
		ft_add_back(&a, ft_stacknew(result[size - 1], index));
		size--;
	}
	return (a);
}

t_stack		*parse(int argc, char *argv[], int *index)
{
	t_stack	*stack_a;
	int		i;
	char	*ptr;
	int		num;
	int		size;

	i = 1;
	size = 0;
	a = NULL;
	if (argc < 2)
		return (NULL);
	ptr = NULL;
	if (argc >= 2)
	{
		while (i < argc)
		{
			ptr = argv[i];
			num = ft_atoi(ptr);
			if (num == 0 && ptr[0] != '0')
				ft_error();
			stack_a = ft_stacknew(num);
			ft_stackadd(&stack_a, ft_stacknew(num));
			i++;
		}
	}
	else
		ft_error("Arguement Error!");
	num = ft_p
	return (stack_a);
}

t_stack	*ft_convert_to_stack(int argc, char *argv[], int *index)
{
	t_stack	*stack_a;
	int		i;
	char	*ptr;
	int		*nums_result;
	int		size;

	i = 1;
	size = 0;
	stack_a = NULL;
	if (argc < 2)
		return (NULL);
	ptr = NULL;
	if (argc >= 2)
	{
		while (i < argc)
			ptr = ft_strjoin(ptr, argv[i++]);
	}
	else
		ft_error("Arguement Error!");
	nums_result = ft_parse(ptr, &size);
	stack_a = ft_add_to_stack(stack_a, nums_result, index, size);
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:57:56 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/15 12:40:43 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int	*copy_into_sorted(int *array, int size)
{
	int	*sorted;
	int	i;

	i = -1;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(array);
		ft_msgerror("Error\n");
	}
	while (++i < size)
		sorted[i] = array[i];
	bubble_sort(sorted, size);
	return (sorted);
}

bool	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		ft_free(array, NULL, "");
	while (++i < size)
	{
		if (array[i] <= array[i - 1])
			return (false);
	}
	return (true);
}

int	*get_num(int num_count, char *argv[])
{
	int		*nums;
	char	**temp;
	int		idx[3];

	idx[0] = 0;
	idx[2] = -1;
	nums = (int *)malloc(sizeof(int) * num_count);
	if (!nums)
		ft_msgerror("Error\n");
	while (argv[++idx[0]])
	{
		temp = ft_split(argv[idx[0]], ' ');
		if (!temp)
			ft_msgerror("Error\n");
		else if (temp[0] == NULL)
			free_2d_array(temp, 1);
		else
		{
			idx[1] = -1;
			while (temp[++idx[1]])
				nums[++idx[2]] = ft_atoi(temp[idx[1]]);
			free_2d_array(temp, get_size_str(temp));
		}
	}
	return (nums);
}

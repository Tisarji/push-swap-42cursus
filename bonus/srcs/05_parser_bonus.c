/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:18:32 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/16 20:31:01 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	check_duplicates(int *un_order, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (un_order[i] == un_order[j])
			{
				free(un_order);
				ft_msgerror("Error\n");
			}
			++j;
		}
	}
}

void	check_num_01(char *num, char **temp)
{
	int	len;

	len = ft_strlen(num);
	if ((num[0] == '+' || num[0] == '-') && num[1] == '0')
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (num[0] == '0' && num[1] != '\0')
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (num[0] == '-' && num[1] == '\0')
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (num[0] == '+' && num[1] == '\0')
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (len < 10)
		return ;
	else if (((num[0] == '+' || num[0] == '-') && len > 11)
			|| (ft_isdigit(num[0]) == 1 && len > 10))
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (num[0] == '+' && (ft_strncmp(num, "+2147483647", len) > 0))
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (num[0] == '-' && (ft_strncmp(num, "-2147483648", len) > 0))
		free_and_exit(temp, get_str_size(temp), "Error\n");
	else if (ft_strncmp(num, "2147483647", len) > 0)
		free_and_exit(temp, get_str_size(temp), "Error\n");
}

void	check_num_02(char *num, char **temp, int *num_count)
{
	int	i;

	i = 0;
	*num_count += 1;
	if (!ft_isdigit(num[0]) && num[0] != '+' && num[0] != '-')
		free_and_exit(temp, get_str_size(temp), "Error\n");
	while (num[++i])
		if (!ft_isdigit(num[i]))
			free_and_exit(temp, get_str_size(temp), "Error\n");
	check_num_01(num, temp);
}

int	get_num_count(char *argv[])
{
	int		i;
	int		j;
	char	**temp;
	int		count;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			ft_msgerror("Error\n");
		else if (temp[0] == NULL)
			free_2d_array(temp, 1);
		else
		{
			j = -1;
			while (temp[++j])
				check_num_02(temp[j], temp, &count);
			free_2d_array(temp, get_str_size(temp));
		}
	}
	return (count);
}

int	parser_args(int argc, char *argv[])
{
	int	count;

	count = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	count = get_num_count(argv);
	if (count == 0)
		ft_msgerror("Error\n");
	return (count);
}

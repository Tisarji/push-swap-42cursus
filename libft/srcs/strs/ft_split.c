/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 01:24:08 by jikarunw          #+#    #+#             */
/*   Updated: 2023/09/13 13:58:36 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **str, int size)
{
	while (size >= 0)
		free(str[size--]);
	free(str);
	return (-1);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') == 1 && 
			(str[i] == c || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_make_word(char *dst, const char *str, char c)
{
	int		i;

	i = 0;
	while ((str[i] == c || str[i] == '\0') == 0)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
}

static int	ft_make_split(char **split, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == c || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (ft_free(split, word - 1));
			ft_make_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (ft_make_split(res, s, c) == -1)
		return (NULL);
	return (res);
}

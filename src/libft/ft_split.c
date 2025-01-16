/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:15:16 by msuokas           #+#    #+#             */
/*   Updated: 2024/11/20 09:39:21 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_splits(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_malloc(char **array_of_strings)
{
	size_t	i;

	i = 0;
	while (array_of_strings[i])
	{
		free(array_of_strings[i]);
		i++;
	}
	free(array_of_strings);
	return (NULL);
}

static char	**split_the_strings(char const *s, char c, char **array_of_strings)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		array_of_strings[y] = ft_substr(s, j, i - j);
		if (!array_of_strings[y])
			return (free_malloc(array_of_strings));
		y++;
	}
	array_of_strings[y] = NULL;
	return (array_of_strings);
}

char	**ft_split(char const *s, char c)
{
	char	**array_of_strings;
	int		amount_of_strings;

	if (!s)
		return (NULL);
	amount_of_strings = ft_count_splits(s, c);
	array_of_strings = malloc((amount_of_strings + 1) * sizeof(char *));
	if (array_of_strings == NULL)
		return (NULL);
	return (split_the_strings(s, c, array_of_strings));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:20:48 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 11:06:50 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		str_length;
	int		i;

	str_length = count_length(n);
	i = str_length;
	str = malloc((str_length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[str_length] = '\0';
	while (str_length-- && i > 0)
	{
		str[str_length] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

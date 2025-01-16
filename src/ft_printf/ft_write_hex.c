/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:43:58 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/05 09:52:09 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_put_hex(unsigned int n, const char format)
{
	int	result;

	result = 0;
	if (n >= 16)
	{
		result = ft_put_hex(n / 16, format);
		if (result == -1)
			return (-1);
		return (ft_put_hex(n % 16, format));
	}
	else
	{
		if (n <= 9)
			return (ft_write_char(n + '0'));
		else if (format == 'x')
			return (ft_write_char(n - 10 + 'a'));
		else if (format == 'X')
			return (ft_write_char(n - 10 + 'A'));
	}
	return (0);
}

int	ft_hex(unsigned int n, const char format)
{
	if (ft_put_hex(n, format) == -1)
		return (-1);
	return (ft_hex_len(n));
}

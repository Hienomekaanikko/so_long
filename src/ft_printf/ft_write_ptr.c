/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:44:03 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/05 10:38:52 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t n)
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

int	ft_put_ptr(uintptr_t n)
{
	int	result;

	if (n >= 16)
	{
		result = ft_put_ptr(n / 16);
		if (result == -1)
			return (-1);
		return (ft_put_ptr(n % 16));
	}
	else
	{
		if (n <= 9)
			return (ft_write_char(n + '0'));
		else
			return (ft_write_char(n - 10 + 'a'));
	}
	return (0);
}

int	ft_write_ptr(uintptr_t ptr)
{
	int	len;

	if (ptr == 0)
	{
		if (ft_write_string("(nil)") == -1)
			return (-1);
		return (5);
	}
	else
	{
		if (ft_write_string("0x") == -1)
			return (-1);
		if (ft_put_ptr(ptr) == -1)
			return (-1);
		len = ft_ptr_len(ptr) + 2;
	}
	return (len);
}

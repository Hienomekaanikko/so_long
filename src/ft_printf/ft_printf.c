/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:43:36 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/05 11:01:45 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, const char format)
{
	int	total_length;

	total_length = 0;
	if (format == 'd' || format == 'i')
		total_length += ft_write_int(va_arg(*args, int));
	else if (format == '%')
		total_length += write(1, "%", 1);
	else if (format == 'u')
		total_length += ft_write_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 's')
		total_length += ft_write_string(va_arg(*args, char *));
	else if (format == 'c')
		total_length += ft_write_char(va_arg(*args, int));
	else if (format == 'x' || format == 'X')
		total_length += ft_hex(va_arg(*args, unsigned int), format);
	else if (format == 'p')
		total_length += ft_write_ptr(va_arg(*args, uintptr_t));
	else
		total_length -= 1;
	return (total_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	int		total_length;
	va_list	args;

	i = 0;
	total_length = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length = ft_format(&args, str[++i]);
			if (length == -1)
				return (va_end(args), -1);
			else
				total_length += length;
		}
		else
			total_length += write(1, &str[i], 1);
		i++;
	}
	return (va_end(args), total_length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:44:00 by msuokas           #+#    #+#             */
/*   Updated: 2024/12/05 10:15:39 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(int n)
{
	int		i;
	char	*nbr;

	i = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	nbr = ft_itoalen(n);
	while (nbr[i] != '\0')
	{
		if (write(1, &nbr[i], 1) == -1)
		{
			i = -1;
			break ;
		}
		i++;
	}
	free (nbr);
	return (i);
}

int	ft_write_unsigned_int(unsigned int n)
{
	int				i;
	char			*nbr;

	i = 0;
	nbr = ft_utoa(n);
	while (nbr[i] != '\0')
	{
		if (write(1, &nbr[i], 1) == -1)
		{
			i = -1;
			break ;
		}
		i++;
	}
	free (nbr);
	return (i);
}

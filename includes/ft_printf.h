/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:43:38 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/03 12:46:28 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_itoalen(int n);
char	*ft_utoa(unsigned int n);
int		ft_write_int(int n);
int		ft_write_unsigned_int(unsigned int n);
int		ft_write_string(char *str);
int		ft_write_char(int c);
int		ft_hex(unsigned int n, const char format);
int		ft_write_ptr(uintptr_t n);

#endif

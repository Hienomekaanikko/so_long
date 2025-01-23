/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/23 12:30:35 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define	SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "MLX42/MLX42.h"

void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_b);
void	rrb(t_list **stack_b);
void	add_targets(t_list **stack_a, t_list **stack_b);
void	count_cost(t_list **stack_a, t_list **stack_b);
void	long_sort(t_list **stack_a, t_list **stack_b);
void	rotate_max_on_top(t_list **stack);
int		highest(t_list **stack);
int		lowest(t_list **stack);
void	empty_b_to_a(t_list	**stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	short_sort(t_list **stack_a);
int		error_check(t_list	**stack_a);
void	add_index(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);

#endif

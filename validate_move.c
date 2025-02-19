/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:45:26 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 09:36:26 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_up(t_game *game, int x, int y)
{
	if (game->map.matrix[y - 1][x] != '1')
		game->plr.y--;
}

void	pos_down(t_game *game, int x, int y)
{
	if (game->map.matrix[y + 1][x] != '1')
		game->plr.y++;
}

void	pos_left(t_game *game, int x, int y)
{
	if (game->map.matrix[y][x - 1] != '1')
		game->plr.x--;
}

void	pos_right(t_game *game, int x, int y)
{
	if (game->map.matrix[y][x + 1] != '1')
		game->plr.x++;
}

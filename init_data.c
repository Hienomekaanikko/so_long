/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/26 18:10:19 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_starting_setup(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			if (game->map.matrix[y][x] == 'P')
			{
				game->plr.x = x;
				game->plr.y = y;
			}
			if (game->map.matrix[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
			}
			x++;
		}
		y++;
	}
}

int	check_component(t_game *game, char c)
{
	if (c == 'C' || c == 'E' || c == 'P'
		|| c == '1' || c == '0')
	{
		if (c == 'C')
			game->map.total_collectables++;
		else if (c == 'E')
			game->map.exits++;
		else if (c == 'P')
			game->map.players++;
		return (1);
	}
	game->map.invalid++;
	game->msg = "Invalid map component";
	return (0);
}

void	init_data(t_game *game)
{
	game->map.h = 0;
	game->map.w = 0;
	game->map.players = 0;
	game->map.exits = 0;
	game->map.invalid = 0;
	game->map.total_collectables = 0;
	game->map.matrix = NULL;
	game->temp_map = NULL;
	game->plr.direction = 1;
	game->plr.x = 0;
	game->plr.y = 0;
	game->plr.collectables = 0;
	game->plr.movements = 0;
	game->mlx = NULL;
	game->msg = NULL;
	game->exit.x = 0;
	game->exit.y = 0;
}

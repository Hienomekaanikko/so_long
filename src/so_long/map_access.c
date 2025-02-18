/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:49:16 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 14:39:13 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, t_access *access)
{
	if (x < 0 || y < 0 || x > game->map.w || y > game->map.h)
		return ;
	if (game->map_cpy.pos[y][x] == '1' || game->map_cpy.pos[y][x] == '.')
		return ;
	if (game->map_cpy.pos[y][x] == 'C')
		access->visited_collectables++;
	if (game->map_cpy.pos[y][x] == 'E')
		access->visited_exit++;
	game->map_cpy.pos[y][x] = '.';
	flood_fill(game, x + 1, y, access);
	flood_fill(game, x - 1, y, access);
	flood_fill(game, x, y + 1, access);
	flood_fill(game, x, y - 1, access);
}

int	all_accessible(t_game *game)
{
	t_access	access;
	int			start_x;
	int			start_y;

	access.visited_collectables = 0;
	access.visited_exit = 0;
	start_x = game->plr.x;
	start_y = game->plr.y;
	flood_fill(game, start_x, start_y, &access);
	if (access.visited_collectables != game->map.total_collectables)
	{
		game->msg = "Not all collectables are accessible";
		return (0);
	}
	if (access.visited_exit != game->map.exits)
	{
		game->msg = "The exit is not accessible";
		return (0);
	}
	ft_free_split(game->map_cpy.pos);
	return (1);
}

void	access_checks(t_game *game)
{
	if (!get_starting_setup(game))
		return ;
	if (!all_accessible(game))
	{
		ft_free_split(game->map_cpy.pos);
		return ;
	}
}

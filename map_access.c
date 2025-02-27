/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:49:16 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 16:43:33 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, int x, int y, t_access *access)
{
	if (x < 0 || y < 0 || x > game->map.w || y > game->map.h)
		return ;
	if (game->map_cpy.matrix[y][x] == '1' || game->map_cpy.matrix[y][x] == '.')
		return ;
	if (game->map_cpy.matrix[y][x] == 'C')
		access->visited_collectables++;
	if (game->map_cpy.matrix[y][x] == 'E')
		access->visited_exit++;
	game->map_cpy.matrix[y][x] = '.';
	flood_fill(game, x + 1, y, access);
	flood_fill(game, x - 1, y, access);
	flood_fill(game, x, y + 1, access);
	flood_fill(game, x, y - 1, access);
}

static void	all_accessible(t_game *game)
{
	t_access	access;

	access.visited_collectables = 0;
	access.visited_exit = 0;
	flood_fill(game, game->plr.x, game->plr.y, &access);
	if (access.visited_collectables != game->map.total_collectables)
		game->msg = "Not all collectables are accessible";
	if (access.visited_exit != game->map.exits)
		game->msg = "The exit is not accessible";
}

void	access_checks(t_game *game)
{
	get_starting_setup(game);
	all_accessible(game);
	ft_free_split(game->map_cpy.matrix);
	if (game->msg != NULL)
		close_program(game);
}

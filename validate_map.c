/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:41:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 15:53:41 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_components(t_game *game)
{
	if (game->map.total_collectables == 0)
		game->msg = "The map must have atleast 1 collectable";
	if (game->map.players != 1)
		game->msg = "The map must have ONE player";
	if (game->map.exits != 1)
		game->msg = "The map must have ONE exit";
	if (game->msg != NULL)
		close_program(game);
}

int	vertical_walls(t_game *game, char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1' || line[ft_strlen(line) - 2] != '1')
	{
		game->msg = "The map must be closed with walls";
		return (0);
	}
	return (1);
}

void	validate_last_line(t_game *game)
{
	size_t	i;
	size_t	j;

	if (!game->temp_map)
		close_program(game);
	i = 0;
	while (game->temp_map[i] && game->temp_map[i] != '\n')
		i++;
	j = ft_strlen(game->temp_map) - i - 1;
	while (game->temp_map[j] && game->temp_map[j] != '\n')
	{
		if (game->temp_map[j] == '1')
			j++;
		else
		{
			game->msg = "The map must be closed with walls";
			close_program(game);
		}
	}
}

int	check_map_width(t_game *game, char *line, size_t prev_width)
{
	size_t	width;

	if (!line)
	{
		game->msg = "Invalid map";
		return (0);
	}
	width = ft_strlen(line) - 1;
	if (width != prev_width)
		game->msg = "The map must be rectangle";
	if (width > MAX_W)
		game->msg = "The map is too wide";
	if (game->msg != NULL)
		return (0);
	return (1);
}

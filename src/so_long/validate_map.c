/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:41:56 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 15:26:54 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_components(t_game *game)
{
	if (game->map.total_collectables == 0)
		game->msg = "The map must have atleast 1 collectable";
	if (game->map.players != 1)
		game->msg = "The map must have ONE player";
	if (game->map.exits != 1)
		game->msg = "The map must have ONE exit";
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

int	validate_last_line(t_game *game, char *temp_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (temp_map[i] && temp_map[i] != '\n')
		i++;
	j = ft_strlen(temp_map) - i - 1;
	while (temp_map[j] && temp_map[j] != '\n')
	{
		if (temp_map[j] == '1')
			j++;
		else
		{
			game->msg = "The map must be closed with walls";
			free(temp_map);
			return (0);
		}
	}
	return (1);
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

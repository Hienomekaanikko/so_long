/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:28:13 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 16:27:07 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.h)
	{
		x = 0;
		while (x < game->map.w)
		{
			add_element(game, &x, &y);
			x++;
		}
		y++;
	}
}

static void	scan_row(t_game *game, char *line, size_t *prev_width)
{
	int	i;

	i = 0;
	if (game->map.h < MAX_H)
	{
		if (game->map.h == 0)
		{
			if (!ft_strchr(line, '1'))
				game->msg = "The map must be closed with walls";
		}
		vertical_walls(game, line);
		if (game->map.h > 0)
			check_map_width(game, line, *prev_width);
		while (line[i] && line[i] != '\n')
		{
			check_component(game, line[i]);
			i++;
		}
		if (game->map.w == 0)
			game->map.w = i;
		*prev_width = i;
		game->map.h++;
	}
	else
		game->msg = "The map is too high";
}

static void	allocate_map(t_game *game)
{
	if (!game->temp_map)
		close_program(game);
	if (game->msg != NULL)
		close_program(game);
	game->map.matrix = ft_split(game->temp_map, '\n');
	if (!game->map.matrix)
		close_program(game);
	game->map_cpy.matrix = ft_split(game->temp_map, '\n');
	if (!game->map.matrix)
		close_program(game);
}

void	read_map(const char *filename, t_game *game)
{
	size_t	prev_width;

	open_map_file(filename, game);
	game->temp_map = ft_strdup("");
	if (!game->temp_map)
		exit(1);
	while (game->file.line != NULL)
	{
		scan_row(game, game->file.line, &prev_width);
		game->temp_map = ft_strjoin(game->temp_map, game->file.line);
		free(game->file.line);
		game->file.line = get_next_line(game->file.fd);
	}
	validate_last_line(game);
	validate_components(game);
	allocate_map(game);
	if (game->temp_map)
		free(game->temp_map);
	close(game->file.fd);
	if (game->msg != NULL)
		close_program(&game);
	game->temp_map = NULL;
}

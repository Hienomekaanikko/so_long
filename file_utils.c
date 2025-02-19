/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 18:47:31 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map_file(const char *filename, t_game *game)
{
	game->file.fd = open(filename, O_RDONLY);
	if (game->file.fd < 0)
	{
		perror(filename);
		close_program(game);
	}
	game->file.line = get_next_line(game->file.fd);
	if (game->file.line == NULL)
	{
		game->msg = "Invalid file";
		close_program(game);
	}
}

void	validate_filename(t_game *game, char *map_name)
{
	int	len;

	if (!map_name)
		return ;
	len = ft_strlen(map_name);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
	{
		game->msg = "The map file must be type .ber";
		close_program(game);
	}
}

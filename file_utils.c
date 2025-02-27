/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/26 18:38:25 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map_file(const char *filename, t_game *game)
{
	game->file.fd = open(filename, O_RDONLY);
	if (game->file.fd < 0)
	{
		ft_putendl_fd("Error", 2);
		perror(filename);
		close_program(game);
	}
	game->file.line = get_next_line(game->file.fd);
	if (game->file.line == NULL)
	{
		game->msg = "Empty file";
		close_program(game);
	}
}

void	validate_path(t_game *game, char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (ft_strncmp(map_path + len - 4, ".ber", 4) != 0)
	{
		game->msg = "The map file must be type .ber";
		close_program(game);
	}
}

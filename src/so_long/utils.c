/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 16:07:38 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map_file(const char *filename, t_game *game)
{
	game->file.fd = open(filename, O_RDONLY);
	if (game->file.fd < 0)
		exit(1);
	game->file.line = get_next_line(game->file.fd);
	if (game->file.line == NULL)
		exit(1);
}

void	mlx42_error(t_game *game)
{
	ft_putendl_fd(mlx_strerror(mlx_errno), 2);
	ft_free_split(game->map.pos);
	mlx_terminate(game->mlx);
	exit(0);
}

void	validate_filename(t_game *game, char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
	{
		game->msg = "The map file must be type .ber";
		error(game);
	}
}

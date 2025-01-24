/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:54 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/24 17:02:52 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	load_textures(t_images *images, mlx_t *mlx, t_textures *textures)
{
	textures->wall = mlx_load_png(WALL_IMG);
	textures->ground = mlx_load_png(GROUND_IMG);
	textures->player = mlx_load_png(PLAYER_IMG);
	textures->collectable = mlx_load_png(COLLECTABLE_IMG);
	textures->exit = mlx_load_png(EXIT_IMG);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	images->ground = mlx_texture_to_image(mlx, textures->ground);
	images->player = mlx_texture_to_image(mlx, textures->player);
	images->collectable = mlx_texture_to_image(mlx, textures->collectable);
	images->exit = mlx_texture_to_image(mlx, textures->exit);
	if (mlx_resize_image(images->wall, WALL_SIZE, WALL_SIZE) == false)
		exit(1);
	if (mlx_resize_image(images->ground, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(images->player, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(images->collectable, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(images->exit, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
}

void	read_map(const char* filename, t_map *game_map)
{
	char	*line;
	int		i;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	game_map->height = 0;
	game_map->width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (game_map->height < MAX_MAP_HEIGHT)
		{
			i = 0;
			while (line[i] && line[i] != '\n' && i < MAX_MAP_WIDTH)
			{
				game_map->map[game_map->height][i] = line[i];
				i++;
			}
			game_map->map[game_map->height][i] = '\0';
			if (game_map->width == 0)
				game_map->width = i;
			game_map->height++;
		}
		free(line);
	}
	close(fd);
}

void	render_map(mlx_t *mlx, t_map *game_map, t_images *images)
{
	int y = 0;
	while (y < game_map->height)
	{
		int x = 0;
		while (x < game_map->width)
		{
			mlx_image_to_window(mlx, images->ground, x * TILE_SIZE, y * TILE_SIZE);
			if (game_map->map[y][x] == 'P')
				mlx_image_to_window(mlx, images->player, x * TILE_SIZE, y * TILE_SIZE);
			if (game_map->map[y][x] == '1')
				mlx_image_to_window(mlx, images->wall, x * TILE_SIZE, y * TILE_SIZE);
			if (game_map->map[y][x] == 'C')
				mlx_image_to_window(mlx, images->collectable, x * TILE_SIZE, y * TILE_SIZE);
			if (game_map->map[y][x] == 'E')
				mlx_image_to_window(mlx, images->exit, x * TILE_SIZE, y * TILE_SIZE);
			if (game_map->map[y][x] == '0')
				mlx_image_to_window(mlx, images->ground, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map		game_map;
	t_textures	textures;
	t_images	images;
	mlx_t		*mlx;

	if (argc != 2)
		return (1);
	read_map(argv[1], &game_map);
	mlx = mlx_init(game_map.width * TILE_SIZE, game_map.height * TILE_SIZE, "So Long", false);
	if (!mlx)
		return (1);
	load_textures(&images, mlx, &textures);
	render_map(mlx, &game_map, &images);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

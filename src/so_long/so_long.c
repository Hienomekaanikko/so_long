/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:54 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/28 09:52:04 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	load_textures(t_game *game)
{
	game->textures.wall = mlx_load_png(WALL_IMG);
	game->textures.ground = mlx_load_png(GROUND_IMG);
	game->textures.player_right = mlx_load_png(PLAYER_RIGHT_IMG);
	game->textures.player_left = mlx_load_png(PLAYER_LEFT_IMG);
	game->textures.collectable = mlx_load_png(COLLECTABLE_IMG);
	game->textures.exit = mlx_load_png(EXIT_IMG);
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->images.ground = mlx_texture_to_image(game->mlx, game->textures.ground);
	game->images.player_right = mlx_texture_to_image(game->mlx, game->textures.player_right);
	game->images.player_left = mlx_texture_to_image(game->mlx, game->textures.player_left);
	game->images.collectable = mlx_texture_to_image(game->mlx, game->textures.collectable);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
	if (mlx_resize_image(game->images.wall, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(game->images.ground, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(game->images.player_right, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(game->images.player_left, TILE_SIZE, TILE_SIZE) == false)
		exit(1);
	if (mlx_resize_image(game->images.collectable, TILE_SIZE / 2, TILE_SIZE / 2) == false)
		exit(1);
	if (mlx_resize_image(game->images.exit, TILE_SIZE , TILE_SIZE) == false)
		exit(1);
}

void	read_map(const char* filename, t_game *game)
{
	char	*line;
	int		i;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	game->map.height = 0;
	game->map.width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (game->map.height < MAX_MAP_HEIGHT)
		{
			i = 0;
			while (line[i] && line[i] != '\n' && i < MAX_MAP_WIDTH)
			{
				game->map.map[game->map.height][i] = line[i];
				i++;
			}
			game->map.map[game->map.height][i] = '\0';
			if (game->map.width == 0)
				game->map.width = i;
			game->map.height++;
		}
		free(line);
	}
	close(fd);
}

void	get_starting_position(t_game *game)
{
	int y = 0;

	while (y < game->map.height)
	{
		int x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int y = 0;
	int centered_x;
	int centered_y;

	while (y < game->map.height)
	{
		int x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->images.ground, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map.map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->images.player_right, game->player.pos_x * TILE_SIZE, game->player.pos_y * TILE_SIZE);
				game->player.pos_x = x;
				game->player.pos_y = y;
			}
			if (game->map.map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images.wall, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map.map[y][x] == 'C')
			{
				game->map.total_collectables++;
				centered_x = x * TILE_SIZE + (TILE_SIZE - game->images.collectable->width) / 2;
				centered_y = y * TILE_SIZE + (TILE_SIZE - game->images.collectable->height) / 2;
				mlx_image_to_window(game->mlx, game->images.collectable, centered_x, centered_y);
			}
			if (game->map.map[y][x] == 'E')
			{
				game->exit.pos_x = x;
				game->exit.pos_y = y;
				mlx_image_to_window(game->mlx, game->images.exit, x * TILE_SIZE, y * TILE_SIZE);
			}
			if (game->map.map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->images.ground, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
int	valid_move_down(t_game *game)
{
	int	y;
	int x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	if (game->map.map[y + 1][x] == '1')
		return (0);
	return (1);
}

int	valid_move_up(t_game *game)
{
	int	y;
	int x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	if (game->map.map[y - 1][x] == '1')
		return (0);
	return (1);
}

int	valid_move_left(t_game *game)
{
	int	y;
	int x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	if (game->map.map[y][x - 1] != '1')
		return (1);
	return (0);
}

int	valid_move_right(t_game *game)
{
	int	y;
	int x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	if (game->map.map[y][x + 1] != '1')
		return (1);
	return (0);
}

int collect(t_game *game)
{
	int	y;
	int x;

	y = game->player.pos_y;
	x = game->player.pos_x;
	if (game->map.map[y][x] == 'C')
	{
		game->player.collectables++;
		game->map.total_collectables--;
		if (game->player.collectables == 1)
			printf("%d pint collected!\n", game->player.collectables);
		else
			printf("%d pints collected!\n", game->player.collectables);
		mlx_image_to_window(game->mlx, game->images.ground, x * TILE_SIZE, y * TILE_SIZE);
		game->map.map[y][x] = '0';
		return (1);
	}
	return (0);
}

//add the need condition to check if currently positioned at exit too

void	exit_game(t_game *game)
{
	if (game->map.total_collectables == 0)
	{
		printf("You finished the game! Total points: %d.\n", game->player.collectables);
		mlx_close_window(game->mlx);
	}
	return ;
}

void direction(int old_x, t_game *game)
{
	if (game->player.pos_x > old_x)
		game->player.direction = 1;
	else if (game->player.pos_x < old_x)
		game->player.direction = 0;
	else
		return ;
}

void key_hook(mlx_key_data_t keydata, void* param)
{
	int	old_x;
	int	old_y;

	t_game *game = (t_game *)param;
	old_x = game->player.pos_x;
	old_y = game->player.pos_y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && valid_move_down(game))
	{
		game->player.pos_y++ && game->player.movements++;
		printf("Total movements: %d\n", game->player.movements);
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && valid_move_up(game))
	{
		game->player.pos_y-- && game->player.movements++;
		printf("Total movements: %d\n", game->player.movements);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && valid_move_left(game))
	{
		game->player.pos_x-- && game->player.movements++;
		printf("Total movements: %d\n", game->player.movements);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && valid_move_right(game))
	{
		game->player.pos_x++ && game->player.movements++;
		printf("Total movements: %d\n", game->player.movements);
	}
	else
	{
		game->player.pos_x = old_x;
		game->player.pos_y = old_y;
	}
	if (game->player.pos_x != old_x || game->player.pos_y != old_y)
	{
		collect(game);
		direction(old_x, game);
		if (game->player.pos_x == game->exit.pos_x && game->player.pos_y == game->exit.pos_y)
			exit_game(game);
		if (old_x == game->exit.pos_x && old_y == game->exit.pos_y)
			mlx_image_to_window(game->mlx, game->images.exit, old_x * TILE_SIZE, old_y * TILE_SIZE);
		else
			mlx_image_to_window(game->mlx, game->images.ground, old_x * TILE_SIZE, old_y * TILE_SIZE);
		if (game->player.direction == 1)
			mlx_image_to_window(game->mlx, game->images.player_right, game->player.pos_x * TILE_SIZE, game->player.pos_y * TILE_SIZE);
		else if (game->player.direction == 0)
			mlx_image_to_window(game->mlx, game->images.player_left, game->player.pos_x * TILE_SIZE, game->player.pos_y * TILE_SIZE);
	}
}

void	run_game(t_game *game)
{
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.player.collectables = 0;
	game.map.total_collectables = 0;
	game.player.movements = 0;
	read_map(argv[1], &game);
	game.mlx = mlx_init(game.map.width * TILE_SIZE, game.map.height * TILE_SIZE, "So Long", false);
	if (!game.mlx)
		return (1);
	get_starting_position(&game);
	load_textures(&game);
	render_map(&game);
	run_game(&game);
	mlx_terminate(game.mlx);
	return (0);
}

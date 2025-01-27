/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/27 17:02:29 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define	SO_LONG_H

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "MLX42/MLX42.h"

#define WALL_SIZE 150
#define TILE_SIZE 150
#define MAX_MAP_WIDTH 2000
#define MAX_MAP_HEIGHT 2000

#define GROUND_IMG "contents/ground.png"
#define	PLAYER_RIGHT_IMG "contents/cow_right.png"
#define	PLAYER_LEFT_IMG "contents/cow_left.png"
#define WALL_IMG "contents/wall.png"
#define COLLECTABLE_IMG "contents/collectable.png"
#define EXIT_IMG "contents/exit.png"

typedef struct s_player
{
	int	pos_y;
	int	pos_x;
	int	collectables;
	int	direction;
} t_player;

typedef struct s_exit
{
	int	pos_y;
	int	pos_x;
} t_exit;

typedef struct s_map
{
	char	map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	int		width;
	int		height;
	int		total_collectables;
} t_map;

typedef struct s_textures
{
	mlx_texture_t*	wall;
	mlx_texture_t*	ground;
	mlx_texture_t*	player_right;
	mlx_texture_t*	player_left;
	mlx_texture_t*	collectable;
	mlx_texture_t*	exit;
	mlx_texture_t*	empty_space;
} t_textures;

typedef struct s_images
{
	mlx_image_t*	wall;
	mlx_image_t*	ground;
	mlx_image_t*	player_right;
	mlx_image_t*	player_left;
	mlx_image_t*	collectable;
	mlx_image_t*	exit;
	mlx_image_t*	empty_space;
} t_images;

typedef struct s_game
{
	mlx_t*		mlx;
	t_player	player;
	t_map		map;
	t_textures	textures;
	t_images	images;
	t_exit		exit;
} t_game;

#endif

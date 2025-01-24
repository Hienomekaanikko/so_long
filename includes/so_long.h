/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/24 16:37:36 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define	SO_LONG_H

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "MLX42/MLX42.h"

#define WALL_SIZE 190
#define TILE_SIZE 200
#define MAX_MAP_WIDTH 2000
#define MAX_MAP_HEIGHT 2000

#define GROUND_IMG "contents/ground.png"
#define	PLAYER_IMG "contents/player.png"
#define WALL_IMG "contents/wall.png"
#define COLLECTABLE_IMG "contents/collectable.png"
#define EXIT_IMG "contents/exit.png"

typedef struct s_player
{
	int	*pos_y;
	int	*pos_x;
} t_player;

typedef struct s_map
{
	char	map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	int		width;
	int		height;
} t_map;

typedef struct s_textures
{
	mlx_texture_t*	wall;
	mlx_texture_t*	ground;
	mlx_texture_t*	player;
	mlx_texture_t*	collectable;
	mlx_texture_t*	exit;
	mlx_texture_t*	empty_space;
} t_textures;

typedef struct s_images
{
	mlx_image_t*	wall;
	mlx_image_t*	ground;
	mlx_image_t*	player;
	mlx_image_t*	collectable;
	mlx_image_t*	exit;
	mlx_image_t*	empty_space;
} t_images;

#endif

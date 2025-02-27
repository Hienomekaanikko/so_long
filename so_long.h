/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/26 16:55:36 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

# define T 100
# define MAX_W 38
# define MAX_H 20

# define GROUND_IMG "textures/ground.png"
# define PLAYER_RIGHT_IMG "textures/cow_right.png"
# define PLAYER_LEFT_IMG "textures/cow_left.png"
# define WALL_IMG "textures/wall.png"
# define COLLECTABLE_IMG "textures/collectable.png"
# define EXIT_IMG "textures/exit.png"

typedef struct s_file
{
	int		fd;
	char	*line;
}	t_file;

typedef struct s_player
{
	int	old_y;
	int	old_x;
	int	y;
	int	x;
	int	collectables;
	int	direction;
	int	movements;
}	t_player;

typedef struct s_exit
{
	int	y;
	int	x;
}	t_exit;

typedef struct s_map
{
	char	**matrix;
	int		w;
	int		h;
	int		total_collectables;
	int		players;
	int		exits;
	int		invalid;
}	t_map;

typedef struct s_access
{
	int	visited_collectables;
	int	visited_exit;
}	t_access;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*grnd;
	mlx_texture_t	*plr_r;
	mlx_texture_t	*plr_l;
	mlx_texture_t	*col;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*grnd;
	mlx_image_t	*plr_r;
	mlx_image_t	*plr_l;
	mlx_image_t	*col;
	mlx_image_t	*exit;
}	t_img;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	plr;
	t_map		map;
	t_map		map_cpy;
	t_textures	txtr;
	t_img		img;
	t_exit		exit;
	t_file		file;
	char		*temp_map;
	char		*msg;
}	t_game;

void	validate_path(t_game *game, char *map_path);
void	open_map_file(const char *filename, t_game *game);
void	init_data(t_game *game);
void	run_game(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	finish_game(t_game *game);
void	mlx42_error(t_game *game);
void	close_program(void *param);

void	read_map(const char *filename, t_game *game);
void	get_starting_setup(t_game *game);
void	access_checks(t_game *game);
int		check_map_width(t_game *game, char *line, size_t prev_width);
int		check_component(t_game *game, char c);
int		vertical_walls(t_game *game, char *line);
void	validate_last_line(t_game *game);
void	validate_components(t_game *game);

void	load_textures(t_game *game);
void	render_image(t_game *game, mlx_image_t *img, int x, int y);
void	render_map(t_game *game);
void	add_element(t_game *game, int *x, int *y);

void	pos_up(t_game *game, int x, int y);
void	pos_down(t_game *game, int x, int y);
void	pos_left(t_game *game, int x, int y);
void	pos_right(t_game *game, int x, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:45:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 16:27:04 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_game *game, mlx_image_t *img, int x, int y)
{
	if (!img || (mlx_image_to_window(game->mlx, img, x, y) < 0))
		mlx42_error(game);
}

void	add_element(t_game *game, int *x, int *y)
{
	int			cntrd_x;
	int			cntrd_y;

	render_image(game, game->img.grnd, *x * T, *y * T);
	if (game->map.pos[*y][*x] == 'P')
		render_image(game, game->img.plr_r, *x * T, *y * T);
	if (game->map.pos[*y][*x] == '1')
		render_image(game, game->img.wall, *x * T, *y * T);
	if (game->map.pos[*y][*x] == 'C')
	{
		cntrd_x = *x * T + (T - game->img.col->width) / 2;
		cntrd_y = *y * T + (T - game->img.col->height) / 2;
		render_image(game, game->img.col, cntrd_x, cntrd_y);
	}
	if (game->map.pos[*y][*x] == 'E')
		render_image(game, game->img.exit, *x * T, *y * T);
}

mlx_image_t	*texture_to_img(t_game *game, mlx_texture_t *texture)
{
	mlx_image_t	*img;

	if (texture == NULL)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	if (texture == game->txtr.col)
	{
		if (mlx_resize_image(img, T / 2, T / 2) == false)
			mlx42_error(game);
		mlx_delete_texture(texture);
		return (img);
	}
	if (mlx_resize_image(img, T, T) == false)
		mlx42_error(game);
	mlx_delete_texture(texture);
	return (img);
}

void	load_textures(t_game *game)
{
	game->txtr.wall = mlx_load_png(WALL_IMG);
	game->txtr.grnd = mlx_load_png(GROUND_IMG);
	game->txtr.plr_r = mlx_load_png(PLAYER_RIGHT_IMG);
	game->txtr.plr_l = mlx_load_png(PLAYER_LEFT_IMG);
	game->txtr.col = mlx_load_png(COLLECTABLE_IMG);
	game->txtr.exit = mlx_load_png(EXIT_IMG);
	game->img.wall = texture_to_img(game, game->txtr.wall);
	game->img.grnd = texture_to_img(game, game->txtr.grnd);
	game->img.plr_r = texture_to_img(game, game->txtr.plr_r);
	game->img.plr_l = texture_to_img(game, game->txtr.plr_l);
	game->img.col = texture_to_img(game, game->txtr.col);
	game->img.exit = texture_to_img(game, game->txtr.exit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:55:44 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 16:27:10 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	collect(t_game *game)
{
	int	y;
	int	x;

	y = game->plr.y;
	x = game->plr.x;
	if (game->map.pos[y][x] == 'C')
	{
		game->plr.collectables++;
		if (game->plr.collectables == 1)
			ft_printf("%d pint collected!\n", game->plr.collectables);
		else
			ft_printf("%d pints collected!\n", game->plr.collectables);
		render_image(game, game->img.grnd, x * T, y * T);
		game->map.pos[y][x] = '0';
		return (1);
	}
	return (0);
}

static void	direction(int old_x, t_game *game)
{
	if (game->plr.x > old_x)
		game->plr.direction = 1;
	else if (game->plr.x < old_x)
		game->plr.direction = 0;
	else
		return ;
}

static void	move_player(t_game *game, int old_x, int old_y)
{
	int			x;
	int			y;

	x = game->plr.x;
	y = game->plr.y;
	collect(game);
	direction(old_x, game);
	if (game->plr.x == game->exit.pos_x && y == game->exit.pos_y)
		finish_game(game);
	if (old_x == game->exit.pos_x && old_y == game->exit.pos_y)
		render_image(game, game->img.exit, old_x * T, old_y * T);
	else
		render_image(game, game->img.grnd, old_x * T, old_y * T);
	if (game->plr.direction == 1)
		render_image(game, game->img.plr_r, x * T, y * T);
	else if (game->plr.direction == 0)
		render_image(game, game->img.plr_l, x * T, y * T);
	game->plr.movements++;
	ft_printf("Total movements: %d\n", game->plr.movements);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	int		x;
	int		y;
	t_game	*game;

	game = (t_game *)param;
	x = game->plr.x;
	y = game->plr.y;
	game->plr.old_x = game->plr.x;
	game->plr.old_y = game->plr.y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_program(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		pos_down(game, x, y);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		pos_up(game, x, y);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		pos_left(game, x, y);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		pos_right(game, x, y);
	if (game->plr.x != game->plr.old_x || game->plr.y != game->plr.old_y)
		move_player(game, x, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:35:25 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 18:33:54 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	if (game->plr.collectables == game->map.total_collectables)
	{
		ft_printf("You won!\n", game->plr.collectables);
		close_program(game);
	}
}

void	mlx42_error(t_game *game)
{
	ft_putendl_fd(mlx_strerror(mlx_errno), 2);
	close_program(game);
	exit(0);
}

void	close_program(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->temp_map)
		free(game->temp_map);
	if (game->map.matrix)
		ft_free_split(game->map.matrix);
	if (game->msg && game->file.fd != -1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(game->msg, 2);
		exit(1);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

void	run_game(t_game *game)
{
	mlx_close_hook(game->mlx, &close_program, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

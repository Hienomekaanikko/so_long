/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:54 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/18 16:27:23 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	validate_filename(&game, argv[1]);
	init_data(&game);
	read_map(argv[1], &game);
	if (game.msg != NULL)
		error(&game);
	access_checks(&game);
	if (game.msg != NULL)
		close_program(&game);
	game.mlx = mlx_init(game.map.w * T, game.map.h * T, "So Long", false);
	load_textures(&game);
	render_map(&game);
	run_game(&game);
	close_program(&game);
}

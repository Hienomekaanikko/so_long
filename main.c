/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:54 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/19 18:12:58 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	init_data(&game);
	validate_filename(&game, argv[1]);
	read_map(argv[1], &game);
	access_checks(&game);
	game.mlx = mlx_init(game.map.w * T, game.map.h * T, "So Long", false);
	load_textures(&game);
	render_map(&game);
	run_game(&game);
	close_program(&game);
}

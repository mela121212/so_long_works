/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:18:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/08 22:20:59 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		panic(game, "Failed to initialize mlx");
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * TILE_SIZE, game->map.rows * TILE_SIZE,
			"so_long");
	if (!game->win_ptr)
		panic(game, "Failed to open a new window");
}

void init_game(t_game *game)
{
	game->map.map = NULL;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->tiles.collectible = NULL;
	game->tiles.exit = NULL;
	game->tiles.floor = NULL;
	game->tiles.player = NULL;
	game->tiles.wall = NULL;
	game->moves = -1;
}

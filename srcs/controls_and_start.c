
#include "../includes/so_long.h"

int	quit_game(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_pos(game, 0, -1);
	else if (key == A || key == LEFT)
		update_player_pos(game, -1, 0);
	else if (key == S || key == DOWN)
		update_player_pos(game, 0, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(game, 1, 0);
	return (EXIT_SUCCESS);
}

void	controls_and_start(t_game *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17),
		quit_game, game);
	mlx_loop(game->mlx_ptr);
}

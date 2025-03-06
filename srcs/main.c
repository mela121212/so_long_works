
#include "../includes/so_long.h"

static void init_game(t_game *game)
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

static void	init_mlx(t_game *game)
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

static void	check_args(int argc, char **argv)
{
	if (argc != 2)
		panic(NULL, "Invalid number of arguments");
	if (*argv[1] == '\0')
		panic(NULL, "NULL map argument");
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	init_game(&game);
	get_map(argv[1], &game);
	map_check(&game);
	init_mlx(&game);
	open_xpm(&game);
	render_tiles(&game);
	controls_and_start(&game);
	return (EXIT_SUCCESS);
}

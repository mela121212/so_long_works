/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:20:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:30:12 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h> 
# include <stdbool.h>
# include "../mlx/mlx.h"


# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "You won, that's all folks!\n"

# define WALL_TILE "./assets/wall.xpm"
# define FLOOR_TILE "./assets/floor.xpm"
# define PLAYER_TILE "./assets/player.xpm"
# define ENEMY_TILE "./assets/ghost.xpm"
# define COLLECTIBLE_TILE "./assets/coin.xpm"
# define EXIT_TILE "./assets/exit.xpm"

# define TILE_SIZE 64

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game {
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	int			moves;
}				t_game;

void	get_map(char *map_file, t_game *game);
void	check_path(t_game *game);
void	map_check(t_game *game);
void	open_xpm(t_game *game);
void	render_tiles(t_game *game);
void	update_player_pos(t_game *game, int dx, int dy);
void	put_player_tile(t_game *game);
void	controls_and_start(t_game *game);
int		quit_game(t_game *game);
void	panic(t_game *game, char *error_msg);
void	destroy_game(t_game *game);
void	free_matrix(char **matrix);
char	*trim_free(char *s1, char const *set);

#endif
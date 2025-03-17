/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:03:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:20:56 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**blank_grid(t_game *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!grid)
		panic(game, "malloc() failed");
	while (i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.map[i]);
		if (!grid[i])
		{
			free_matrix(grid);
			panic(game, "malloc() failed");
		}
		i += 1;
	}
	return (grid);
}

static int	flood_fill(t_map *map, t_point curr, char **sol_grid, int *coins, int *found_exit)
{
	if (sol_grid[curr.y][curr.x] == WALL)
		return (0);
	if (sol_grid[curr.y][curr.x] == COLLECTIBLE)
		*coins += 1;
	if (sol_grid[curr.y][curr.x] == EXIT)
		*found_exit = 1;
	sol_grid[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid, coins, found_exit);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid, coins, found_exit);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid, coins, found_exit);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid, coins, found_exit);
	return (*coins == map->collectibles && *found_exit);
}

void	check_path(t_game *game)
{
	char	**sol_grid;
	int		coins;
	int		found_exit;

	coins = 0;
	found_exit = 0;
	sol_grid = blank_grid(game);
	if (!flood_fill(&game->map, game->map.player_pos, sol_grid, &coins, &found_exit))
	{
		free_matrix(sol_grid);
		panic(game, "Map has unachievable entities");
	}
	free_matrix(sol_grid);
}
/////////////////
static int	flood_fill(t_map *map, t_point curr, char **sol_grid, int result[2])
{
	if (sol_grid[curr.y][curr.x] == WALL)
		return (0);

	if (sol_grid[curr.y][curr.x] == COLLECTIBLE)
		result[0] += 1;

	if (sol_grid[curr.y][curr.x] == EXIT)
		result[1] = 1;

	sol_grid[curr.y][curr.x] = WALL;

	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid, result);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid, result);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid, result);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid, result);

	return (result[0] == map->collectibles && result[1]);
}

void	check_path(t_game *game)
{
	char	**sol_grid;
	int		result[2]; // result[0] = coins, result[1] = found_exit

	result[0] = 0;
	result[1] = 0;
	sol_grid = blank_grid(game);

	if (!flood_fill(&game->map, game->map.player_pos, sol_grid, result))
	{
		free_matrix(sol_grid);
		panic(game, "Map has unachievable entities");
	}
	free_matrix(sol_grid);
}


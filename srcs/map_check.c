/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:38:12 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:15:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define VALID_ENTITIES "ECP01"

static int	is_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL) //cambia wall por '1'
			return (0);
	i = -1;
	while (++i < map->columns)
		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
			return (0);
	return (1);
}

static void	valid_elements(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		panic(game, "Invalid number of Exits");
	if (game->map.collectibles == 0)
		panic(game, "Map doesn't have any Collectible");
	if (game->map.player == 0 || game->map.player > 1)
		panic(game, "Invalid number of Starting Positions");
}

static void	count_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (!is_onstr(VALID_ENTITIES, game->map.map[i][j]))
				panic(game, "Invalid entity on map's file");
			if (game->map.map[i][j] == 'E')
				game->map.exit += 1;
			else if (game->map.map[i][j] == 'C')
				game->map.collectibles += 1;
			else if (game->map.map[i][j] == 'P')
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
}

/*static void	count_elements(t_game *game) // es para no usar on_str y que sea mas legible
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			char c = game->map.map[i][j];

			// Si el caracter no es válido, lanza un error
			if (c != 'E' && c != 'C' && c != 'P' && c != '0' && c != '1')
				panic(game, "Invalid entity on map's file");

			// Contar los elementos importantes
			if (c == 'E')
				game->map.exit += 1;
			else if (c == 'C')
				game->map.collectibles += 1;
			else if (c == 'P')
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
}*/


static int	valid_form(t_game *game) //is_resctangle??
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (0);
		i += 1;
	}
	return (1);
}

void	map_check(t_game *game)
{
	if (!valid_form(game))
		panic(game, "Invalid map format");
	count_elements(game);
	valid_elements(game);
	if (!is_closed(&game->map))
		panic(game, "Map is not closed by walls");
	check_path(game);
}

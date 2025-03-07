/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:15:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:20:23 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_ber(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (1);
	return (0);
}

static void	count_rows(char *map_file, t_game *game)
{
	int		counter;
	int		map_fd;
	char	*temp;

	counter = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		panic(game, "Failed to open map's file");
	temp = get_next_line(map_fd);
	while (temp)
	{
		counter += 1;
		free(temp);
		temp = get_next_line(map_fd);
	}
	if (counter == 0)
		panic(game, "Map file is empty");
	game->map.rows = counter;
	close(map_fd);
}

static void	count_lines(char *map_file, t_game *game) //Cambia nombre count_colums
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		panic(game, "Failed to open map's file");
	i = 0;
	while (i < game->map.rows)
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (game->map.rows - 1))
	{
		game->map.map[i] = trim_free(game->map.map[i], "\n");
		if (!game->map.map[i])
			panic(game, "malloc() failed");
		i += 1;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	if (valid_ber(map_file) == 0)
		panic(game, "Invalid map file extension");
	count_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *)); //este malloc puedo hacerlo dentro de count lines
	if (!game->map.map)
		panic(game, "malloc() failed");
	count_lines(map_file, game); //count_colums
}

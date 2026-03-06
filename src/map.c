/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:51:55 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 17:39:57 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

static int	count_rows(char *file)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

// Lee el archivo y rellena game->map.grid fila a fila
static int	fill_grid(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map.grid);
		return (-1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map.grid[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map.grid[i] = NULL;
	game->map.cols = ft_strlen(game->map.grid[0]);
	close(fd);
	return (0);
}

int	load_map(t_game *game, char *file)
{
	if (check_extension(file) < 0)
		return (-1);
	game->map.rows = count_rows(file);
	if (game->map.rows <= 0)
		return (-1);
	game->map.grid = malloc(sizeof(char *) * (game->map.rows + 1));
	if (game->map.grid == NULL)
		return (-1);
	if (fill_grid(game, file) < 0)
		return (-1);
	if (map_validator(game) < 0)
	{
		free_map(game);
		return (-1);
	}
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.grid[i])
	{
		free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
}

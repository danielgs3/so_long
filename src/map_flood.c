/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 16:56:03 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Hace una copia profunda del mapa para no modificar el original
static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// Rellena recursivamente desde (x,y) marcando con 'V' las casillas accesibles
static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

// Libera la copia del mapa
static void	free_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

// Devuelve -1 si algún C o E quedó sin alcanzar tras el flood
static int	check_reachable(char **copy, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == COLLECTIBLE || copy[y][x] == EXIT)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

// Comprueba que todos los C y E son accesibles desde P
int	check_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	if (!copy)
		return (-1);
	flood_fill(copy, game->player_x, game->player_y);
	if (check_reachable(copy, game) < 0)
	{
		free_copy(copy);
		write(2, "Error\n No valid path in map.\n", 29);
		return (-1);
	}
	free_copy(copy);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/07 12:57:01 by danielg3         ###   ########.fr       */
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

// Libera la copia y devuelve ret (permite usarlo en un return directo)
static int	free_copy_r(char **copy, int ret)
{
	int	i;

	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
	return (ret);
}

// Reemplaza 'block' por 'rep', hace flood desde P y busca 'target' sin visitar
static int	run_check(t_game *game, char block, char rep, char target)
{
	char	**copy;
	int		y;
	int		x;

	copy = copy_map(game);
	if (!copy)
		return (-1);
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (copy[y][++x])
			if (copy[y][x] == block)
				copy[y][x] = rep;
	}
	flood_fill(copy, game->player_x, game->player_y);
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (copy[y][++x])
			if (copy[y][x] == target)
				return (free_copy_r(copy, -1));
	}
	return (free_copy_r(copy, 0));
}

// Pasada 1: E→muro → todas las C alcanzables sin pasar por E
// Pasada 2: C→suelo → E alcanzable con todas las C recogidas
int	check_path(t_game *game)
{
	if (run_check(game, EXIT, WALL, COLLECTIBLE) < 0)
	{
		write(2, "Error\n-Collectibles not reachable.\n", 35);
		return (-1);
	}
	if (run_check(game, COLLECTIBLE, FLOOR, EXIT) < 0)
	{
		write(2, "Error\n-Exit not reachable.\n", 27);
		return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:30:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 17:21:24 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Comprueba que el nombre del archivo (sin ruta) acabe en .ber
// y que haya al menos 1 carácter antes del punto
int	check_extension(char *file)
{
	char	*name;
	int		len;

	name = ft_strrchr(file, '/');
	if (name)
		name++;
	else
		name = file;
	len = ft_strlen(name);
	if (len <= 4 || ft_strncmp(name + len - 4, ".ber", 4) != 0)
	{
		write(2, "Error\n Map must be a .ber file.\n", 32);
		return (-1);
	}
	return (0);
}

// Comprueba que la primera y última fila sean todo paredes
static int	check_h_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.grid[0][i] != WALL
			|| game->map.grid[game->map.rows - 1][i] != WALL)
		{
			write(2, "Error\n Map not surrounded by walls.\n", 36);
			return (-1);
		}
		i++;
	}
	return (0);
}

// Comprueba que la primera y última columna de cada fila sean paredes
static int	check_v_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.grid[i][0] != WALL
			|| game->map.grid[i][game->map.cols - 1] != WALL)
		{
			write(2, "Error\n Map not surrounded by walls.\n", 36);
			return (-1);
		}
		i++;
	}
	return (0);
}

// Llama a check_h_walls y check_v_walls
int	check_walls(t_game *game)
{
	if (check_h_walls(game) < 0)
		return (-1);
	if (check_v_walls(game) < 0)
		return (-1);
	return (0);
}

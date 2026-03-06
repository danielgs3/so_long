/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 16:31:07 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_chars(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c != FLOOR && c != WALL && c != COLLECTIBLE
				&& c != EXIT && c != PLAYER)
			{
				write(2, "Error\n Invalid character in map.\n", 33);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.grid[i]) != game->map.cols)
		{
			write(2, "Error\n Map is not rectangular.\n", 31);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	check_tile(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == PLAYER)
	{
		game->player_x = x;
		game->player_y = y;
		game->map.player_count++;
	}
	else if (game->map.grid[y][x] == COLLECTIBLE)
		game->map.collectibles++;
	else if (game->map.grid[y][x] == EXIT)
		game->map.exit_count++;
}

static int	count_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (game->map.grid[y][x])
			check_tile(game, x++, y);
		y++;
	}
	if (game->map.player_count != 1 || game->map.exit_count != 1
		|| game->map.collectibles < 1)
	{
		write(2, "Error\n Invalid number of P, E or C.\n", 36);
		return (-1);
	}
	return (0);
}

int	map_validator(t_game *game)
{
	if (check_rectangular(game) < 0)
		return (-1);
	if (check_walls(game) < 0)
		return (-1);
	if (check_chars(game) < 0)
		return (-1);
	if (count_elements(game) < 0)
		return (-1);
	if (check_path(game) < 0)
		return (-1);
	return (0);
}

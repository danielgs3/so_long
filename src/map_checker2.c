/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 13:00:00 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_side_walls(t_game *game)
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

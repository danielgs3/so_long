/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:12 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 16:58:03 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->images.wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &w, &h);
	game->images.floor = mlx_xpm_file_to_image(game->mlx, IMG_FLOOR, &w, &h);
	game->images.player = mlx_xpm_file_to_image(game->mlx, IMG_PLAYER, &w, &h);
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, IMG_COLLECTIBLE,
			&w, &h);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT, &w, &h);
	if (!game->images.wall || !game->images.floor || !game->images.player
		|| !game->images.collectible || !game->images.exit)
	{
		write(2, "Error loading images\n", 21);
		exit(1);
	}
}

void	draw_tile(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->images.floor, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->images.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->images.collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->images.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->images.player, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			draw_tile(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/06 17:12:40 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Intenta mover al jugador a la casilla (nx, ny)
static void	move_player(t_game *game, int nx, int ny)
{
	char	next_tile;

	next_tile = game->map.grid[ny][nx];
	if (next_tile == WALL)
		return ;
	if (next_tile == EXIT && game->collected < game->map.collectibles)
		return ;
	if (next_tile == COLLECTIBLE)
	{
		game->collected++;
		game->map.grid[ny][nx] = FLOOR;
	}
	game->map.grid[game->player_y][game->player_x] = FLOOR;
	game->map.grid[ny][nx] = PLAYER;
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render(game);
	if (next_tile == EXIT)
	{
		ft_printf("You win in %d moves!\n", game->moves);
		handle_close(game);
	}
}

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == 65307)
		handle_close(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

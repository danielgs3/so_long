/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:00:00 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 15:14:33 by danielg3         ###   ########.fr       */
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

int	handle_keys(int keycode, t_game *game) // Maneja los eventos de pulsación de tecla
{
	if (keycode == 65307) // Si la tecla pulsada es ESC (código 65307), llamamos a la función handle_close para cerrar el juego
		handle_close(game);
	else if (keycode == 119 || keycode == 65362) // Si la tecla pulsada es W (código 119) o la flecha hacia arriba (código 65362), intentamos mover al jugador hacia arriba llamando a la función move_player con las coordenadas (game->player_x, game->player_y - 1)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115 || keycode == 65364) // Si la tecla pulsada es S (código 115) o la flecha hacia abajo (código 65364), intentamos mover al jugador hacia abajo llamando a la función move_player con las coordenadas (game->player_x, game->player_y + 1)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97 || keycode == 65361) // Si la tecla pulsada es A (código 97) o la flecha hacia la izquierda (código 65361), intentamos mover al jugador hacia la izquierda llamando a la función move_player con las coordenadas (game->player_x - 1, game->player_y)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100 || keycode == 65363) // Si la tecla pulsada es D (código 100) o la flecha hacia la derecha (código 65363), intentamos mover al jugador hacia la derecha llamando a la función move_player con las coordenadas (game->player_x + 1, game->player_y)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

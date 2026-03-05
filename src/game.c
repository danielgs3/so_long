/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:26:19 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/05 13:24:44 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_close(t_game *game) // Función para cerrar el juego
{
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

int init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game)); // Limpia la estructura del juego
	if(load_map(game, map_file) < 0) // Carga el mapa desde el archivo .ber
	{
		write(2, "Error\n Invalid map file.\n", 29);
		return (-1);
	}
	game->mlx = mlx_init(); // Inicializa la conexión con X11
	if(game->mlx == NULL)
	{
		free_map(game); // Si falla, libera el mapa
		write(2, "Error initializing MLX\n", 22);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx,
		     game->map.cols * TILE_SIZE,
			 game->map.rows * TILE_SIZE,
			 "so_long"); // Crea la ventana con el tamaño adecuado)
	if(game->win == NULL)
	{
		free_map(game); // Si falla, libera el mapa
		write(2, "Error\n Window creation failed.\n", 34);
		return (-1);
	}
	return (0); // Todo bien, devuelve 0





	game->mlx = mlx_init();
	if(game->mlx == NULL)
		return (-1);
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	if(game->win == NULL)
	{
		write(2, "Error creating window\n", 21);
		free(game->mlx);
		return(-1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:26:19 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 14:42:09 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images.wall);
	mlx_destroy_image(game->mlx, game->images.floor);
	mlx_destroy_image(game->mlx, game->images.player);
	mlx_destroy_image(game->mlx, game->images.collectible);
	mlx_destroy_image(game->mlx, game->images.exit);
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

int	handle_expose(t_game *game)
{
	render(game);
	return (0);
}

int	init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game)); // Inicializamos la estructura t_game a cero
	if (load_map(game, map_file) < 0) // Cargamos el mapa desde el archivo
		return (-1);
	game->mlx = mlx_init(); // Inicializamos la conexión con la biblioteca gráfica MLX
	if (game->mlx == NULL) // Si mlx_init falla
	{
		free_map(game); // Liberamos la memoria del mapa
		write(2, "Error initializing MLX\n", 22); // Mensaje de error
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE,
			"so_long"); // Creamos una nueva ventana con el tamaño adecuado para mostrar el mapa, multiplicando el número de columnas y filas por el tamaño de cada tile (TILE_SIZE) y con el título "so_long"
	if (game->win == NULL) // Si mlx_new_window falla
	{
		free_map(game);
		write(2, "Error\n Window creation failed.\n", 32);
		return (-1);
	}
	return (0);
}

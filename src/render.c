/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:24:12 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 14:59:50 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w; // Variable para almacenar el ancho de las imágenes
	int	h; // Variable para almacenar la altura de las imágenes

	game->images.wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &w, &h); // Cargamos la imagen de la pared desde el archivo IMG_WALL utilizando la función mlx_xpm_file_to_image, que devuelve un puntero a la imagen cargada. También se pasan las direcciones de las variables w y h para que la función pueda almacenar el ancho y la altura de la imagen.
	game->images.floor = mlx_xpm_file_to_image(game->mlx, IMG_FLOOR, &w, &h); // Cargamos la imagen del suelo desde el archivo IMG_FLOOR utilizando la función mlx_xpm_file_to_image, que devuelve un puntero a la imagen cargada. También se pasan las direcciones de las variables w y h para que la función pueda almacenar el ancho y la altura de la imagen.
	game->images.player = mlx_xpm_file_to_image(game->mlx, IMG_PLAYER, &w, &h);
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, IMG_COLLECTIBLE,
			&w, &h);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT, &w, &h);
	if (!game->images.wall || !game->images.floor || !game->images.player
		|| !game->images.collectible || !game->images.exit) // Si alguna de las imágenes no se ha cargado correctamente (es decir, si alguna de las funciones mlx_xpm_file_to_image ha devuelto NULL), mostramos un mensaje de error y salimos del programa con código 1.
	{
		write(2, "Error loading images\n", 21);
		exit(1);
	}
}

void	draw_tile(t_game *game, char tile, int x, int y) // Dibuja la baldosa correspondiente en la posición (x, y) según el tipo de tile que se le pase como argumento. Primero dibuja el suelo en esa posición, y luego, dependiendo del tipo de tile, dibuja la pared, el jugador, el objeto coleccionable o la salida encima del suelo.
{
	mlx_put_image_to_window(game->mlx, game->win, game->images.floor, x
		* TILE_SIZE, y * TILE_SIZE); // Dibujamos el suelo en la posición (x, y) multiplicando las coordenadas por el tamaño de cada tile (TILE_SIZE) para que se dibuje en la posición correcta en la ventana. La función mlx_put_image_to_window se encarga de dibujar la imagen especificada (en este caso, game->images.floor) en la ventana del juego (game->win) utilizando la conexión con MLX (game->mlx).
	if (tile == WALL) // Si el tipo de tile es una pared (WALL), dibujamos la imagen de la pared encima del suelo en la misma posición (x, y) utilizando la función mlx_put_image_to_window.
		mlx_put_image_to_window(game->mlx, game->win, game->images.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE) // Si el tipo de tile es un objeto coleccionable (COLLECTIBLE), dibujamos la imagen del objeto coleccionable encima del suelo en la misma posición (x, y) utilizando la función mlx_put_image_to_window.
		mlx_put_image_to_window(game->mlx, game->win, game->images.collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT) /// Si el tipo de tile es una salida (EXIT), dibujamos la imagen de la salida encima del suelo en la misma posición (x, y) utilizando la función mlx_put_image_to_window.
		mlx_put_image_to_window(game->mlx, game->win, game->images.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER) // Si el tipo de tile es el jugador (PLAYER), dibujamos la imagen del jugador encima del suelo en la misma posición (x, y) utilizando la función mlx_put_image_to_window.
		mlx_put_image_to_window(game->mlx, game->win, game->images.player, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render(t_game *game)
{
	int	y; // Variable para iterar por las filas del mapa
	int	x; // Variable para iterar por las columnas del mapa

	y = 0;
	while (y < game->map.rows) // Iteramos por cada fila del mapa, desde la fila 0 hasta la fila game->map.rows - 1
	{
		x = 0; // Variable para iterar por las columnas del mapa
		while (x < game->map.cols) // Iteramos por cada columna del mapa, desde la columna 0 hasta la columna game->map.cols - 1
		{
			draw_tile(game, game->map.grid[y][x], x, y); // Dibujamos la baldosa correspondiente en la posición (x, y)
			x++; // Incrementamos la columna
		}
		y++; // Incrementamos la fila
	}
}

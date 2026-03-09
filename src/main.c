/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:33:50 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 15:17:18 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game; // Declaramos la variable game de tipo t_game, que es una estructura que contiene toda la información del juego, como el mapa, las imágenes, la ventana, etc.

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./so_long <map.ber>\n", 2);
		return (1);
	}
	if (init_game(&game, argv[1]) == -1) // Llamamos a la función init_game, que se encarga de inicializar el juego, cargar el mapa desde el archivo, contar los elementos del mapa, etc.
		return (1); //Si la función devuelve -1, significa que hubo un error al cargar el mapa, por lo que mostramos un mensaje de error y salimos con código 1.
	load_images(&game); // Llamamos a la función load_images, que se encarga de cargar las imágenes necesarias para el juego, como el suelo, las paredes, el jugador, los objetos coleccionables y la salida.
	render(&game); // Llamamos a la función render, que se encarga de dibujar el mapa en la ventana del juego.
	mlx_hook(game.win, 2, 1L << 0, handle_keys, &game); // Registramos un hook para el evento de pulsación de tecla (evento 2) en la ventana del juego (game.win). El tercer argumento (1L << 0) es una máscara que indica que queremos recibir eventos de pulsación de tecla. El cuarto argumento es un puntero a la función handle_keys, que se encargará de manejar los eventos de pulsación de tecla. El último argumento (&game) es un puntero a la estructura t_game, que se pasará como parámetro a la función handle_keys cuando se llame.
	mlx_hook(game.win, 12, 1L << 15, handle_expose, &game); // Registramos un hook para el evento de exposición (evento 12) en la ventana del juego (game.win). El tercer argumento (1L << 15) es una máscara que indica que queremos recibir eventos de exposición. El cuarto argumento es un puntero a la función handle_expose, que se encargará de manejar los eventos de exposición. El último argumento (&game) es un puntero a la estructura t_game, que se pasará como parámetro a la función handle_expose cuando se llame.
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}

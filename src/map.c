/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:51:55 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/04 17:37:11 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_rows(char *file)
{
	int fd;
	int rows;
	char *line;

	fd = open(file, O_RDONLY); // 1. Abre el archivo .ber
	if(fd < 0)
		return (-1); // Si falla, devuelve -1
	rows = 0;
	line = get_next_line(fd); // 2. Lee la primera línea
	while(line) // 3. Mientras haya líneas...
	{
		rows++; //    cuenta +1
		free(line); //    libera la línea
		line = get_next_line(fd); // lee la siguiente
	}
	close(fd); // 4. Cierra el archivo
	return (rows); // 5. Devuelve el total de filas
}

static int map_validator(t_game *game)
{
	int y;
	int x;

	y = 0;
	while(y < game->map.rows)
	{
		x = 0;
		while(game->map.grid[y][x])
		{
			if(game->map.grid[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				game->map.player_count++;
			}
			else if((game->map.grid[y][x] == COLLECTIBLE))
				game->map.collectibles++;
			else if(game->map.grid[y][x] == EXIT)
				game->map.exit_count++;
			x++;
		}
		y++;
	}
	if((game->map.player_count != 1) || (game->map.exit_count != 1 || game->map.collectibles < 1)) // Debe haber exactamente 1 jugador, al menos 1 coleccionable y exactamente 1 salida
		return(-1);
	return (0);
}

int load_map(t_game *game, char *file)
{
	int fd; // Descriptor de archivo para el mapa
	int i; // Índice para iterar sobre las filas del mapa
	char *line; // Variable para almacenar cada línea leída del archivo

	game->map.rows = count_rows(file); // Cuenta el número de filas en el archivo .ber
	if(game->map.rows <= 0) // Si el conteo de filas es 0 o negativo, el mapa es inválido
		return(-1);
	game->map.grid = malloc(sizeof(char *) * (game->map.rows + 1)); // Reserva memoria para el arreglo de filas del mapa, con espacio adicional para un puntero NULL al final
	if(game->map.grid == NULL) // Si la reserva de memoria falla, devuelve -1
		return(-1);
	fd = open(file, O_RDONLY); // Abre el archivo .ber para lectura
	if(fd < 0) // Si el archivo no se puede abrir, libera la memoria reservada para el mapa y devuelve -1
		return(-1);
	i = 0; // Inicializa el índice de filas a 0
	line = get_next_line(fd); // Lee la primera línea del archivo .ber
	while(line) // Mientras haya líneas para leer...
	{
		game->map.grid[i] = ft_strtrim(line, "\n"); // Elimina el salto de línea al final de la línea leída y almacena la cadena resultante en el arreglo de filas del mapa
		free(line); // Libera la memoria de la línea original leída del archivo
		i++; // Incrementa el índice de filas para la siguiente iteración
		line = get_next_line(fd); // Lee la siguiente línea del archivo .ber
	}
	game->map.grid[i] = NULL; // Después de leer todas las líneas, establece el último puntero del arreglo de filas a NULL para marcar el final del mapa
	game->map.cols = ft_strlen(game->map.grid[0]); // Asume que todas las filas tienen la misma longitud y almacena la longitud de la primera fila como el número de columnas del mapa
	close(fd); // Cierra el archivo .ber después de leerlo completamente
	return(map_validator(game));
}

void free_map(t_game *game)
{
	int i;

	i = 0;

	while(game->map.grid[i])
	{
		free(game->map.grid[i]); // Libera la memoria de cada fila del mapa
		i++;
	}
	free(game->map.grid); // Libera la memoria del arreglo de filas del mapa
}

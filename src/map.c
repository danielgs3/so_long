/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:51:55 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 15:18:40 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

static int	count_rows(char *file) // Contamos el número de filas del mapa
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY); // Abrimos el archivo en modo lectura
	if (fd < 0) // Si no se puede abrir el archivo
	{
		write(2, "Error\n-Could not open map file.\n", 32);
		return (-1);
	}
	line = get_next_line(fd); // Leemos la primera línea
	while (line) // Mientras haya líneas que leer
	{
		rows++; // Contamos una fila más
		free(line); // Liberamos la memoria de la línea leída
		line = get_next_line(fd); // Leemos la siguiente línea
	}
	close(fd); // Cerramos el archivo
	return (rows); // Devolvemos el número de filas contadas
}

// Lee el archivo y rellena game->map.grid fila a fila
static int	fill_grid(t_game *game, char *file)
{
	int		fd; // Descriptor de archivo
	int		i; // Contador de filas
	char	*line; // Línea leída

	fd = open(file, O_RDONLY); // Abrimos el archivo en modo lectura
	if (fd < 0) // Si no se puede abrir el archivo
	{
		free(game->map.grid); // Liberamos la memoria del grid
		return (-1);
	}
	i = 0; // Contador de filas
	line = get_next_line(fd); // Leemos la primera línea
	while (line) // Mientras haya líneas que leer
	{
		game->map.grid[i] = ft_strtrim(line, "\r\n"); // Guardamos la línea leída en el grid del mapa, eliminando los caracteres de salto de línea y retorno de carro
		free(line); // Liberamos la memoria de la línea leída
		i++; // Contador de filas
		line = get_next_line(fd); // Leemos la siguiente línea
	}
	game->map.grid[i] = NULL; // Marcamos el final del grid con un puntero NULL
	game->map.cols = ft_strlen(game->map.grid[0]); // Guardamos el número de columnas del mapa, que es la longitud de la primera fila
	close(fd);
	return (0);
}

int	load_map(t_game *game, char *file) // Cargamos el mapa desde el archivo
{
	if (check_extension(file) < 0) // Comprobamos la extensión del archivo
		return (-1);
	game->map.rows = count_rows(file); // Contamos el número de filas del mapa
	if (game->map.rows < 0) // Si count_rows devuelve -1, hay un error
		return (-1);
	if (game->map.rows == 0) // Si no hay filas, el mapa está vacío
	{
		write(2, "Error\n-Map is empty.\n", 21);
		return (-1);
	}
	game->map.grid = malloc(sizeof(char *) * (game->map.rows + 1)); // Reservamos memoria para el grid del mapa, que es un array de punteros a char, con una fila extra para el NULL final
	if (game->map.grid == NULL) // Si malloc falla, devolvemos -1
		return (-1);
	if (fill_grid(game, file) < 0) // Llenamos el grid del mapa con las líneas del archivo, si fill_grid devuelve -1, hay un error al abrir el archivo o al leerlo, por lo que liberamos la memoria del grid y devolvemos -1
		return (-1);
	if (map_validator(game) < 0) // Validamos el mapa, si map_validator devuelve -1, hay un error en el mapa
	{
		free_map(game);
		return (-1);
	}
	return (0);
}

void	free_map(t_game *game) // Liberamos la memoria del mapa
{
	int	i;

	i = 0;
	while (game->map.grid[i]) // Mientras haya filas en el grid
	{
		free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
}

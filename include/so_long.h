/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:35:53 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/09 12:28:41 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h> // open y close
# include <stdio.h>

# define TILE_SIZE 64

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define IMG_WALL "assets/wall.xpm"
# define IMG_FLOOR "assets/floor.xpm"
# define IMG_PLAYER "assets/player.xpm"
# define IMG_COLLECTIBLE "assets/collectible.xpm"
# define IMG_EXIT "assets/exit.xpm"

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_images;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		collectibles;
	int		exit_count;
	int		player_count;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_images	images;
	int			player_x;
	int			player_y;
	int			moves;
	int			collected;
}			t_game;

int			load_map(t_game *game, char *file);
int			map_validator(t_game *game);
int			check_walls(t_game *game);
int			check_extension(char *file);
int			check_path(t_game *game);
void		free_map(t_game *game);

int			init_game(t_game *game, char *map_file);
int			handle_close(t_game *game);
int			handle_expose(t_game *game);

void		render(t_game *game);
void		load_images(t_game *game);

int			handle_keys(int keycode, t_game *game);

#endif

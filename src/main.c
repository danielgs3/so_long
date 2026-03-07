/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:33:50 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/07 12:53:16 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./so_long <map.ber>\n", 2);
		return (1);
	}
	if (init_game(&game, argv[1]) == -1)
		return (1);
	load_images(&game);
	render(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keys, &game);
	mlx_hook(game.win, 12, 1L << 15, handle_expose, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}

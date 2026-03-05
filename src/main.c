/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:33:50 by danielg3          #+#    #+#             */
/*   Updated: 2026/03/05 10:16:21 by danielg3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./so_long <map.ber>\n", 2);
		return (1);
	}
	if (init_game(&game, argv[1]) == -1)
	{
		ft_putstr_fd("Error initializing game. Check the map file.\n", 2);
		return (1);
	}
	mlx_loop(game.mlx);


}


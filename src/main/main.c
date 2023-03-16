/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:10:03 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:21:54 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_ms		game;
	t_parse		parse;
	t_config	config;
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error : Invalid number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	init_structs(&game, &parse, &mlx, &config);
	check_extension(argv[1], &game);
	parsing(&game);
	execute(&game);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:56 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	_norm_raycast(t_ms *game)
{
	int	ii;
	int	x;
	int	y;

	ii = 0;
	x = 0;
	y = 0;
	clear(game);
	while (x < WINDOWS_X)
	{
		raycast_1(game, x);
		raycast_2(game);
		raycast_3(game);
		raycast_4(game, &ii);
		raycast_5(game, y, x, ii);
		y = 0;
		fill_void(game, y, x);
		x++;
	}
}

int	set_up(t_ms *game)
{
	_norm_raycast(game);
	draw_again(game, game->config->buffer);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
	draw_sprite(game);
	mlx_destroy_image(game->mlx->mlx, game->mlx->img);
	return (0);
}

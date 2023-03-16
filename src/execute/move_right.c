/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:08 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ch_cos_x_right(t_ms *game)
{
	int		i;
	double	x;

	i = 1;
	x = 0.1;
	while (x <= MOVE_SPEED)
	{
		if (game->p->map_sp[(int)(game->config->posy)][(int)(game->config->posx
				+ game->config->diry * x)] == '1')
			return (0);
		x += 0.01;
		if (x > MOVE_SPEED && i)
		{
			i = 0;
			x = MOVE_SPEED;
		}
	}
	return (1);
}

static int	ch_cos_y_right(t_ms *game)
{
	int		i;
	double	x;

	i = 1;
	x = 0.1;
	while (x <= MOVE_SPEED)
	{
		if (game->p->map_sp[(int)(game->config->posy - game->config->dirx
				* x)][(int)(game->config->posx)] == '1')
			return (0);
		x += 0.01;
		if (x > MOVE_SPEED && i)
		{
			i = 0;
			x = MOVE_SPEED;
		}
	}
	return (1);
}

void	move_right(t_ms *game)
{
	if (ch_cos_y_right(game))
		game->config->posy -= game->config->dirx * MOVE_SPEED;
	if (ch_cos_x_right(game))
		game->config->posx += game->config->diry * MOVE_SPEED;
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	set_up(game);
}

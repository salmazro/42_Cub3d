/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:02:57 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_collosions_x(t_ms *game)
{
	int		i;
	double	x;

	i = 1;
	x = 0.1;
	while (x <= MOVE_SPEED)
	{
		if (game->p->map_sp[(int)(game->config->posy + game->config->diry * x)]
						[(int)(game->config->posx)] == '1')
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

static int	check_collosions_y(t_ms *game)
{
	int		i;
	double	x;

	i = 1;
	x = 0.1;
	while (x <= MOVE_SPEED)
	{
		if (game->p->map_sp[(int)game->config->posy]
			[(int)(game->config->posx + game->config->dirx
				* x)] == '1')
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

void	move_forward(t_ms *game)
{
	if (check_collosions_x(game))
		game->config->posy += game->config->diry * MOVE_SPEED;
	if (check_collosions_y(game))
		game->config->posx += game->config->dirx * MOVE_SPEED;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:42 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycast_1(t_ms *game, int x)
{
	game->config->camerax = 2 * x / (double)WINDOWS_X - 1;
	game->config->raydirx = game->config->dirx
		+ game->config->planex * game->config->camerax;
	game->config->raydiry = game->config->diry
		+ game->config->planey * game->config->camerax;
	game->config->mapx = (int)game->config->posx;
	game->config->mapy = (int)game->config->posy;
	if (game->config->raydirx == 0)
		game->config->deltadistx = 1e30;
	else
		game->config->deltadistx = fabs(1 / game->config->raydirx);
	if (game->config->raydiry == 0)
		game->config->deltadistx = 1e30;
	else
		game->config->deltadisty = fabs(1 / game->config->raydiry);
	game->config->hit = 0;
}

void	raycast_2(t_ms *game)
{
	if (game->config->raydirx < 0)
	{
		game->config->stepx = -1;
		game->config->sidedistx = (game->config->posx - game->config->mapx)
			* game->config->deltadistx;
	}
	else
	{
		game->config->stepx = 1;
		game->config->sidedistx = (game->config->mapx + 1.0
				- game->config->posx) * game->config->deltadistx;
	}
	if (game->config->raydiry < 0)
	{
		game->config->stepy = -1;
		game->config->sidedisty = (game->config->posy - game->config->mapy)
			* game->config->deltadisty;
	}
	else
	{
		game->config->stepy = 1;
		game->config->sidedisty = (game->config->mapy + 1.0
				- game->config->posy) * game->config->deltadisty;
	}
}

void	raycast_3(t_ms *game)
{
	char	c;

	while (game->config->hit == 0)
	{
		if (game->config->sidedistx < game->config->sidedisty)
		{
			game->config->sidedistx += game->config->deltadistx;
			game->config->mapx += game->config->stepx;
			game->config->side = 0;
		}
		else
		{
			game->config->sidedisty += game->config->deltadisty;
			game->config->mapy += game->config->stepy;
			game->config->side = 1;
		}
		c = game->p->map_sp[game->config->mapy][game->config->mapx];
		if (c != 'P' && c != '0')
			game->config->hit = 1;
	}
}

static void	fill_(t_ms *game, int x, int y)
{
	y = 0;
	while (y < WINDOWS_Y)
	{
		if (game->config->buffer[y][x] == 0 && game->config->mv_up_down > 0
			&& (y < game->config->draw_start || y > game->config->draw_end))
			game->config->buffer[y][x] = game->mlx->c_c;
		else if (game->config->buffer[y][x] == 0 && game->config->mv_up_down < 0
				&& (y < game->config->draw_start || y > game->config->draw_end))
			game->config->buffer[y][x] = game->mlx->f_c;
		y++;
	}
}

void	fill_void(t_ms *game, int y, int x)
{
	while (y < game->config->draw_start)
	{
		if (game->config->draw_start < 0
			|| game->config->draw_start > game->config->draw_end)
			break ;
		game->config->buffer[y][x] = game->mlx->c_c;
		y++;
	}
	y = game->config->draw_end;
	while (y < WINDOWS_Y)
	{
		if (game->config->draw_end < 0
			|| game->config->draw_end < game->config->draw_start)
			break ;
		game->config->buffer[y][x] = game->mlx->f_c;
		y++;
	}
	fill_(game, x, y);
}

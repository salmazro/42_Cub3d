/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:46 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ray_utils(t_ms *game)
{
	if (game->config->side == 0)
		game->config->perpwalldist = game->config->sidedistx
			- game->config->deltadistx;
	else
		game->config->perpwalldist = game->config->sidedisty
			- game->config->deltadisty;
	game->config->line_height = (int)(WINDOWS_Y
			/ game->config->perpwalldist);
	game->config->draw_start = -game->config->line_height / 2
		+ (WINDOWS_Y / 2) + game->config->mv_up_down;
	if (game->config->draw_start < 0)
		game->config->draw_start = 0;
	game->config->draw_end = game->config->line_height / 2
		+ (WINDOWS_Y / 2) + game->config->mv_up_down;
	if (game->config->draw_end >= WINDOWS_Y)
		game->config->draw_end = WINDOWS_Y - 1;
}

void	raycast_4(t_ms *game, int *i)
{
	ray_utils(game);
	if (game->config->side == 0
		&& game->p->map_sp[game->config->mapy][game->config->mapx] == '1')
	{
		game->config->wallx = game->config->posy
			+ game->config->perpwalldist * game->config->raydiry;
		if (game->config->raydirx > 0)
			*i = 2;
		else
			*i = 1;
	}
	else
	{
		game->config->wallx = game->config->posx
			+ game->config->perpwalldist * game->config->raydirx;
		if (game->config->raydiry > 0)
			*i = 3;
		else
			*i = 4;
	}
}

void	set_texture_color(t_ms *game, int i)
{
	if (i == 1)
		game->config->texture_color = mlx_get_color_value(game->mlx,
				game->config->north_data[game->config->texture_y * TEXTURE_W
				+ game->config->texture_x]);
	else if (i == 2)
		game->config->texture_color = mlx_get_color_value(game->mlx,
				game->config->south_data[game->config->texture_y * TEXTURE_W
				+ game->config->texture_x]);
	else if (i == 3)
		game->config->texture_color = mlx_get_color_value(game->mlx,
				game->config->east_data[game->config->texture_y * TEXTURE_W
				+ game->config->texture_x]);
	else if (i == 4)
		game->config->texture_color = mlx_get_color_value(game->mlx,
				game->config->west_data[game->config->texture_y * TEXTURE_W
				+ game->config->texture_x]);
}

void	raycast_5(t_ms *game, int y, int x, int i)
{
	game->config->wallx = (double)game->config->wallx
		- (int)(game->config->wallx);
	game->config->texture_x = (int)(game->config->wallx * (double)TEXTURE_W);
	if (game->config->side == 0 && game->config->raydirx > 0)
		game->config->texture_x = TEXTURE_W - game->config->texture_x - 1;
	if (game->config->side == 1 && game->config->raydiry < 0)
		game->config->texture_x = TEXTURE_W - game->config->texture_x - 1;
	game->config->step = 1.0 * TEXTURE_H / game->config->line_height;
	game->config->texture_pos = (game->config->draw_start - ((WINDOWS_Y / 2)
				+ game->config->mv_up_down) + game->config->line_height / 2)
		* game->config->step;
	y = game->config->draw_start;
	while (y < game->config->draw_end)
	{
		game->config->texture_y = (int)game->config->texture_pos & (TEXTURE_W
				- 1);
		game->config->texture_pos += game->config->step;
		set_texture_color(game, i);
		game->config->buffer[y][x] = game->config->texture_color;
		y++;
	}
}

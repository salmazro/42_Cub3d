/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:36 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_buffer(int ***buffer, t_ms *game)
{
	int	i;

	i = 2;
	while (++i < 13)
		(*buffer)[WINDOWS_Y / 2 - i][WINDOWS_X / 2] = 0x00FF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WINDOWS_Y / 2 + i][WINDOWS_X / 2] = 0x00FF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WINDOWS_Y / 2][WINDOWS_X / 2 - i] = 0x00FF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WINDOWS_Y / 2][WINDOWS_X / 2 + i] = 0x00FF0000;
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
}

void	draw_again(t_ms *game, int **buffer)
{
	int	i;
	int	x;

	i = 0;
	update_buffer(&buffer, game);
	game->mlx->img = mlx_new_image(game->mlx->mlx, WINDOWS_X, WINDOWS_Y);
	game->mlx->data = (int *)mlx_get_data_addr(game->mlx->img, &game->mlx->bpp,
			&game->mlx->size_l, &game->mlx->endian);
	while (i < WINDOWS_Y)
	{
		x = 0;
		while (x < WINDOWS_X)
		{
			game->mlx->data[i * WINDOWS_X + x] = buffer[i][x];
			x++;
		}
		i++;
	}
}

void	clear(t_ms *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WINDOWS_Y)
	{
		j = 0;
		while (j < WINDOWS_X)
		{
			game->config->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

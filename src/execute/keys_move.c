/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:02:47 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate(double angle, t_ms *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->config->dirx;
	game->config->dirx = game->config->dirx * cos(angle) - game->config->diry
		* sin(angle);
	game->config->diry = old_dirx * sin(angle) + game->config->diry
		* cos(angle);
	old_planex = game->config->planex;
	game->config->planex = game->config->planex * cos(angle)
		- game->config->planey * sin(angle);
	game->config->planey = old_planex * sin(angle) + game->config->planey
		* cos(angle);
	set_up(game);
}

int	move_mouse(int x, int y, t_ms *game)
{
	double	angle_r;

	(void)y;
	if (game->mouse_mode == true)
		mlx_mouse_hide();
	else if (game->mouse_mode == false)
		mlx_mouse_show();
	if (game->mouse_mode == true)
	{
		angle_r = -(x - WINDOWS_X / 2) / 1000.69;
		rotate(angle_r, game);
		mlx_mouse_move(game->mlx->win, WINDOWS_X / 2, WINDOWS_Y / 2);
	}
	return (0);
}

int	move_key(int key, t_ms *game)
{
	if (key == KEY_W)
		move_forward(game);
	if (key == KEY_S)
		move_backward(game);
	if (key == KEY_A)
		move_left(game);
	if (key == KEY_D)
		move_right(game);
	if (key == KEY_LEFT)
		rotate(ROTATE_SPEED, game);
	if (key == KEY_RIGHT)
		rotate(ROTATE_SPEED * -1, game);
	if (key == KEY_ESC)
		quit_game(game);
	return (0);
}

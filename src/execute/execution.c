/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:02:41 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	gun_shoot(int key, int x, int y, t_ms *game)
{
	(void)x;
	(void)y;
	(void)key;
	game->gun = !game->gun;
	set_up(game);
	return (0);
}

void	ft_mlx(t_ms *game)
{
	mlx_hook(game->mlx->win, ON_KEYDOWN, ON_KEYPRESS, move_key, game);
	mlx_hook(game->mlx->win, ON_KEYUP, ON_KEYPRESS, key_press, game);
	mlx_hook(game->mlx->win, ON_MOUSEMOVE, ON_MOUSEENTER, move_mouse, game);
	mlx_hook(game->mlx->win, ON_MOUSEDOWN, ON_BUTTONPRESS, gun_shoot, game);
	mlx_hook(game->mlx->win, ON_MOUSEUP, ON_BUTTONRELE, gun_shoot, game);
	mlx_hook(game->mlx->win, ON_DESTROY, ON_BUTTONPRESS, quit_game, game);
	mlx_loop_hook(game->mlx->mlx, set_up, game);
	mlx_loop(game->mlx->mlx);
}

void	execute(t_ms *game)
{
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
	{
		ft_putstr_fd("Error : mlx_init failed\n", 2);
		quit_game(game);
	}
	game->mlx->win = mlx_new_window(game->mlx->mlx, WINDOWS_X, WINDOWS_Y,
			game->p->map_path);
	if (!game->mlx->win)
	{
		ft_putstr_fd("Error : mlx_new_window failed\n", 2);
		quit_game(game);
	}
	intialize_textures(game);
	set_up(game);
	ft_mlx(game);
}

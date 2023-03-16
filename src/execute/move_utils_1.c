/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:30 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_arrfree(int **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < WINDOWS_Y)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int	key_press(int key, t_ms *game)
{
	if (key == KEY_U)
		game->mouse_mode = !game->mouse_mode;
	if (game->mouse_mode == true)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
	return (0);
}

static void	destroy_images(t_ms *game)
{
	if (game->mlx->win)
		mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	if (game->config->w_t)
		mlx_destroy_image(game->mlx->mlx, game->config->w_t);
	if (game->config->e_t)
		mlx_destroy_image(game->mlx->mlx, game->config->e_t);
	if (game->config->n_t)
		mlx_destroy_image(game->mlx->mlx, game->config->n_t);
	if (game->config->s_t)
		mlx_destroy_image(game->mlx->mlx, game->config->s_t);
	if (game->config->sprite1)
		mlx_destroy_image(game->mlx->mlx, game->config->sprite1);
	if (game->config->sprite2)
		mlx_destroy_image(game->mlx->mlx, game->config->sprite2);
	if (game->config->buffer)
		ft_arrfree(game->config->buffer);
}

int	quit_game(t_ms *game)
{
	destroy_images(game);
	if (game->p->map_path)
		free(game->p->map_path);
	game->p->map_path = NULL;
	if (game->p->map_sp)
		free_double(game->p->map_sp);
	if (game->p->color_sp)
		free_double(game->p->color_sp);
	if (game->p->text_sp)
		free_double(game->p->text_sp);
	if (game->p->parse_sp)
		free_double(game->p->parse_sp);
	exit(EXIT_SUCCESS);
	return (1);
}

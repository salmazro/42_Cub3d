/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:50 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	malloc_buffer(t_ms *game)
{
	int	i;

	i = 0;
	game->config->buffer = (int **)malloc(sizeof(int *) * WINDOWS_Y);
	while (i < WINDOWS_Y)
	{
		game->config->buffer[i] = (int *)malloc(sizeof(int) * WINDOWS_X);
		i++;
	}
}

static void	helper(t_ms *game)
{
	game->config->n_t = mlx_xpm_file_to_image(game->mlx->mlx,
			game->p->text_sp[0],
			&game->config->t_width,
			&game->config->t_height);
	game->config->s_t = mlx_xpm_file_to_image(game->mlx->mlx,
			game->p->text_sp[1],
			&game->config->t_width,
			&game->config->t_height);
	game->config->w_t = mlx_xpm_file_to_image(game->mlx->mlx,
			game->p->text_sp[2],
			&game->config->t_width,
			&game->config->t_height);
	game->config->e_t = mlx_xpm_file_to_image(game->mlx->mlx,
			game->p->text_sp[3],
			&game->config->t_width,
			&game->config->t_height);
	game->config->sprite1 = mlx_xpm_file_to_image(game->mlx->mlx,
			("Imgs/flower-idle.xpm"),
			&game->config->t_width,
			&game->config->t_height);
	game->config->sprite2 = mlx_xpm_file_to_image(game->mlx->mlx,
			("Imgs/flower-spark.xpm"),
			&game->config->t_width,
			&game->config->t_height);
}

void	intialize_textures(t_ms *game)
{
	helper(game);
	if (game->config->n_t == NULL || game->config->s_t == NULL
		|| game->config->w_t == NULL || game->config->e_t == NULL
		|| game->config->sprite1 == NULL || game->config->sprite2 == NULL)
		ft_error("Invalid texture", "Bad file", EXIT_FAILURE, game);
	game->config->north_data = (int *)mlx_get_data_addr(game->config->n_t,
			&game->config->bpp, &game->config->sl, &game->config->e);
	game->config->south_data = (int *)mlx_get_data_addr(game->config->s_t,
			&game->config->bpp, &game->config->sl, &game->config->e);
	game->config->west_data = (int *)mlx_get_data_addr(game->config->w_t,
			&game->config->bpp, &game->config->sl, &game->config->e);
	game->config->east_data = (int *)mlx_get_data_addr(game->config->e_t,
			&game->config->bpp, &game->config->sl, &game->config->e);
	malloc_buffer(game);
}

void	draw_sprite(t_ms *game)
{
	if (game->gun)
	{
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->config->sprite2, WINDOWS_X / 2, WINDOWS_Y / 2);
	}
	else
	{
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->config->sprite1, WINDOWS_X / 2, WINDOWS_Y / 2);
	}
}

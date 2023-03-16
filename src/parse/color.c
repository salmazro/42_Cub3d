/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.ae>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:00:44 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 03:06:41 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

ssize_t	ft_atoi_index(t_ms *game, const char *str, size_t i)
{
	size_t	nb;

	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (nb >= 9223372036854775807)
			ft_error("Invalid color", NULL, EXIT_FAILURE, game);
		nb = nb * 10 + str[i++] - 48;
	}
	return (nb);
}

static void	check_color_norm(t_ms *game, size_t *i, size_t *a, int *comma)
{
	if (!ft_isdigit(game->p->color_sp[*a][*i]))
		ft_error("Invalid color", NULL, EXIT_FAILURE, game);
	if (ft_atoi_index(game, game->p->color_sp[*a], *i) > 255
		|| ft_atoi_index(game, game->p->color_sp[*a], *i) < 0)
		ft_error("Invalid color", NULL, EXIT_FAILURE, game);
	while (game->p->color_sp[*a][*i] && ft_isdigit(game->p->color_sp[*a][*i]))
		*i = *i + 1;
	if (game->p->color_sp[*a][*i] && game->p->color_sp[*a][*i] == ',')
		*comma = *comma + 1;
	if (game->p->color_sp[*a][*i] && (game->p->color_sp[*a][*i] != ','
		|| !ft_isdigit(game->p->color_sp[*a][++(*i)])))
		ft_error("Invalid color", NULL, EXIT_FAILURE, game);
}

void	check_color(t_ms *game, size_t i, size_t a, int comma)
{
	if (game->p->color_sp[0][0] != 'F' || game->p->color_sp[1][0] != 'C'
		|| game->p->color_sp[0][1] != ' ' || game->p->color_sp[1][1] != ' ')
		ft_error("Invalid color", NULL, EXIT_FAILURE, game);
	while (a < 2)
	{
		comma = 0;
		i = 2;
		while (game->p->color_sp[a][i] == ' ')
			i++;
		while (game->p->color_sp[a][i])
			check_color_norm(game, &i, &a, &comma);
		if (++a && comma != 2)
			ft_error("Invalid color", NULL, EXIT_FAILURE, game);
	}
}

void	ft_color_parse(t_ms *game)
{
	char	*f_c;
	char	*c_c;

	check_color(game, 2, 0, 0);
	f_c = ft_convert_base(ft_rgb_to_hex(game, \
		game->p->color_sp[0], 2), HEX, DEC);
	c_c = ft_convert_base(ft_rgb_to_hex(game, \
		game->p->color_sp[1], 2), HEX, DEC);
	game->mlx->f_c = ft_atoi_index(game, f_c, 0);
	game->mlx->c_c = ft_atoi_index(game, c_c, 0);
	free(f_c);
	free(c_c);
}

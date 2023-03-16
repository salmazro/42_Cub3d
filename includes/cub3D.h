/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:19:39 by mealjnei          #+#    #+#             */
/*   Updated: 2023/03/12 12:09:46 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_SPACE 49
# define KEY_U 32
# define KEY_Q 12

# define TEXTURE_W 64
# define TEXTURE_H 64

# define DEC "0123456789"
# define HEX "0123456789abcdef"

# define MOVE_SPEED 0.5
# define ROTATE_SPEED 0.5

# define WINDOWS_X 800
# define WINDOWS_Y 600

typedef struct s_config
{
	int			checker;
	char		dir_fun;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltax;
	double		deltay;
	double		perpwalldist;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		wallx;
	double		step;
	double		texture_pos;
	int			texture_color;
	int			texture_x;
	int			texture_y;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			draw_start;
	int			draw_end;
	int			i;
	int			y;
	int			line_height;
	int			mv_up_down;
	void		*n_t;
	void		*s_t;
	void		*w_t;
	void		*e_t;
	void		*sprite1;
	void		*sprite2;
	int			*north_data;
	int			*south_data;
	int			*west_data;
	int			*east_data;
	int			t_width;
	int			t_height;
	int			bpp;
	int			sl;
	int			e;
	int			**buffer;
}				t_config;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			w;
	int			h;
	long long	f_c;
	long long	c_c;
}				t_mlx;

typedef struct s_parse
{
	char		*map_path;
	char		*map;
	char		**parse_sp;
	char		**map_sp;
	char		**color_sp;
	char		**text_sp;
}				t_parse;

typedef struct s_ms
{
	t_parse		*p;
	t_mlx		*mlx;
	t_config	*config;
	bool		mouse_mode;
	bool		gun;
}				t_ms;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	NOEVENTMASK = 0,
	ON_KEYPRESS = 1L << 0,
	ON_BUTTONPRESS = (1L << 2),
	ON_BUTTONRELE = (1L << 1),
	ON_MOUSEMOVE_ = 1L << 5,
	ON_MOUSEENTER = 1L << 6,
};

void			execute(t_ms *game);
void			ft_arrfree(int **arr);

int				move_key(int key, t_ms *game);
void			funny_rotate(t_ms *game);
void			rotate_down(t_ms *game);
void			rotate_up(t_ms *game);
void			rotate_right(t_ms *game);
void			rotate_left(t_ms *game);
void			move_right(t_ms *game);
void			move_left(t_ms *game);
void			move_backward(t_ms *game);
void			move_forward(t_ms *game);
int				move_mouse(int x, int y, t_ms *game);
int				quit_game(t_ms *game);
int				key_press(int key, t_ms *game);
void			rotate(double angle, t_ms *game);

void			parsing(t_ms *game);
void			read_map(t_ms *game);
void			check_extension(char *str, t_ms *game);

void			prepare_dir_color(t_ms *game);
int				ft_find_index(char **str, char *s, int len, t_ms *game);
char			*ft_replace(char *n, char *old);

char			*ft_rgb_to_hex(t_ms *game, char *rgb, size_t i);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
int				ft_lnbr(int nbr, int base_lenght);
int				ft_inbase(char c, char *base);
int				ft_checker(char *base);

char			*ft_put_nbr(int nbr, char *base, int sign, int i);
void			ft_putnbr_base(int nbr, int nbase, char *num_base, char *base);
char			*ft_char(char *dest, char src);

void			ft_color_parse(t_ms *game);
void			check_color(t_ms *game, size_t i, size_t a, int comma);
ssize_t			ft_atoi_index(t_ms *game, const char *str, size_t i);

void			ft_map_valid_char(t_ms *game, int i, size_t nl);
void			check_pos(char c, t_ms *game);
void			ft_map_valid_structure(t_ms *game, int *i, size_t *nl);
void			player_position(t_ms *game);

void			check_zero(t_ms *game);
void			check_space(t_ms *game, int i, int a);
void			check_walls(t_ms *game);

void			texture(t_ms *game);
void			replace_texture(t_ms *game, char *direction, int a);

void			init_structs(t_ms *game, t_parse *parse, t_mlx *mlx,
					t_config *config);
void			set_config(t_config *config);
void			ft_error(char *str, char *err, int status, t_ms *game);
int				fd_open(t_ms *game, char *str);

char			*ft_strjoin_freeall(char *s1, char *s2);
char			*ft_joinchar(char *s1, char c);
char			**ft_strdupp(char **str, int start, int size);
size_t			ft_strlenn(char **str);
char			**free_double(char **s);

int				set_up(t_ms *game);
void			clear(t_ms *game);
void			draw_again(t_ms *game, int **buffer);
void			update_buffer(int ***buffer, t_ms *game);
void			fill_void(t_ms *game, int y, int x);

void			raycast_1(t_ms *game, int x);
void			raycast_2(t_ms *game);
void			raycast_3(t_ms *game);

void			raycast_4(t_ms *game, int *i);
void			set_texture_color(t_ms *game, int i);
void			raycast_5(t_ms *game, int y, int x, int i);

void			malloc_buffer(t_ms *game);
void			intialize_textures(t_ms *game);
void			draw_sprite(t_ms *game);

void			update_buffer(int ***buffer, t_ms *game);
void			draw_again(t_ms *game, int **buffer);
void			clear(t_ms *game);

#endif

NAME		= cub3D
CC			= gcc
CFLAGS		= -g3 -O3 -Werror -Wall -Wextra -Imlx
RM			= /bin/rm -f
LIBFT_LIB 	= libft
LINK_LIBFT 	= -Llibft -lft
LINK_MLX = -Lmlx_macos -Imlx_macos -lmlx -framework OpenGL -framework AppKit
MLX_LIB = mlx_macos
MLX_STATIC_LIB = $(MLX_LIB)/libmlx.a
LIBFT_STATIC_LIB = $(LIBFT_LIB)/libft.a
DIR_SRCS	= src
DIR_OBJS	= obj
SUBDIRS		= main parse execute
SRCS_MAIN	= main
SRCS_PARSE	= parse valid_map texture valid_map_2 utils_1 utils_2 \
			color color_check color_utils_1 color_utils_2
SRCS_EXC = execution raycast raycast_utils_1 raycast_utils_2 \
			raycast_utils_3 raycast_utils_0 \
			keys_move move_forward move_backward \
			move_utils_1 move_left move_right
SRCS = $(addsuffix .c, $(addprefix src/main/, $(SRCS_MAIN))) \
		$(addsuffix .c, $(addprefix src/parse/, $(SRCS_PARSE))) \
		$(addsuffix .c, $(addprefix src/execute/, $(SRCS_EXC)))
SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))
INCLUDES	= -I includes
$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJS) ${MLX_STATIC_LIB} ${LIBFT_STATIC_LIB}
	@${CC} ${CFLAGS} $(OBJS) $(LINK_MLX) ${LINK_LIBFT} -o $(NAME)
$(LIBFT_STATIC_LIB):
	@$(MAKE) -sC $(LIBFT_LIB)
$(MLX_STATIC_LIB):
	@$(MAKE) -sC $(MLX_LIB)
clean:
	@$(MAKE) -sC $(LIBFT_LIB) clean
	@$(MAKE) -sC $(MLX_LIB) clean
	@$(RM) $(OBJS)
	@$(RM) -r $(DIR_OBJS)
fclean: clean
	@$(MAKE) -sC $(LIBFT_LIB) fclean
	@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
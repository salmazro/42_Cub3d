
NAME = libft.a

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= is to mem str put lst int printf gnl

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))
ECHO = -printf

INCLUDES	= -Iincludes

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM		= /bin/rm -f


$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@ $(ECHO) "\033[0;31m 					┊┊┊┊┊╭╭╭╮╮╮┊┊┊┊\n\
						┊┊┊┊┊╰╰╲╱╯╯┊┊┊┊\n\
						┊┏╮╭┓╭━━━━━━╮┊┊\n\
						┊╰╮╭╯┃┈┈┈┈┈┈┃┊┊\n\
						┊┊┃╰━╯┈┈╰╯┈┈┃┊┊\n\
						┊┊┃┈┈┈┈┈┈┈╰━┫┊┊\n\
						╲╱╲╱╲╱╲╱╲╱╲╱╲╱╲\n"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: ${NAME}

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@$(ECHO) "$(NO_COL)"

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norme:
	norminette ${wildcard srcs/*.c} ${wildcard srcs/*.h}

wh:
	@echo 	"\033[0;31m                 ┊┊┊┊┊╭╭╭╮╮╮┊┊┊┊\n\
			 ┊┊┊┊┊╰╰╲╱╯╯┊┊┊┊\n\
			 ┊┏╮╭┓╭━━━━━━╮┊┊\n\
			 ┊╰╮╭╯┃┈┈┈┈┈┈┃┊┊\n\
			 ┊┊┃╰━╯┈┈╰╯┈┈┃┊┊\n\
			 ┊┊┃┈┈┈┈┈┈┈╰━┫┊┊\n\
			 ╲╱╲╱╲╱╲╱╲╱╲╱╲╱╲"


whale:
	@echo 	"             __   __       "
	@echo	"            __ \ / __      "
	@echo	"           /  \ | /  \     "
	@echo	"               \|/         "
	@echo	"          _,.---v---._     "
	@echo	" /\__/\  /            \    "
	@echo	" \_  _/ /              \   "
	@echo	"  \ \_ /          @  __|   "
	@echo	"   \                 \_    "
	@echo	"    \     ,__/        /    "
	@echo	"  ~~~~~~~~~~~~~~~~~~~~~    "


#------------------------------------------------------------------------------#
#                  COLORS                                                      # 
#------------------------------------------------------------------------------#
RED	= \033[1;31m
GRE	= \033[1;32m
YEL	= \033[1;33m
BLU	= \033[1;34m
MAG	= \033[1;35m
CYA	= \033[1;36m
NO_COL = \033[0m
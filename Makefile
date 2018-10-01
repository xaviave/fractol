# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/05 18:53:52 by wgaetan      #+#   ##    ##    #+#        #
#    Updated: 2018/10/01 17:11:22 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

NAME = fractol
HEADERS = includes/fractol.h
FLAGS = -Wall -Wextra -Werror -g
INC = -I minilibx_macos -I libft
LIBS = minilibx_macos/libmlx.a libft/libft.a
EXT_LIBS = -framework OpenGl -framework AppKit


#PATH

SRCS = srcs/main.c \
	   srcs/menu.c \

OBJS = $(SRCS:.c=.o)


#RULES

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) -ggdb $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	@make -C ./libft
	@make -C ./minilibx_macos

./%.o: ./%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx_macos fclean

re: fclean all
	@make -C ./libft re
	@make -C ./minilibx_macos re

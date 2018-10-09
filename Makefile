# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/09 17:54:27 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2018/10/09 18:50:12 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

NAME = fractol
HEADERS = includes/fractol.h
FLAGS = -Wall -Wextra -Werror -g
CC = gcc -O3
INC = -I minilibx_macos -I libft
LIBS = minilibx_macos/libmlx.a libft/libft.a
EXT_LIBS = -framework OpenGl -framework AppKit


#PATH

SRCS = srcs/main.c\
	   srcs/init.c\
	   srcs/key.c\
	   srcs/img.c\
	   srcs/mouse.c\
	   srcs/move.c\
	   srcs/color.c\
	   srcs/julia.c\
	   srcs/mandelbrot.c\
	   srcs/burningship.c\

OBJS = $(SRCS:.c=.o)


#RULES

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

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
	@rm -f ./libft/libft.a
	@rm -f ./minilibx_macos/libmlx.a

re: fclean all

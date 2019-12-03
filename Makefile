# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/09 17:54:27 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 20:03:05 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

CC = gcc
LIBFT = libft/
MINILIBX = minilibx_macos/libmlx.a
NAME = fractol
INC = includes/fractol.h
LIB_FLAG = -framework OpenGl -framework AppKit
CFLAGS = -Wall -Wextra -Werror -O2


#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./srcs/

FILES = main.c\
	    init.c\
	    key_hook.c\
	    img.c\
	    mouse_hook.c\
	    zoom_hook.c\
	    color.c\
	    julia.c\
	    mandelbrot.c\
	    burningship.c\


SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))


#RULES

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(LIB_FLAG) -o $@ $(OBJS) $(MINILIBX) -L $(LIBFT) -lft


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@make -C $(LIBFT) clean
	@make -C minilibx_macos clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft/libft.a
	@rm -f minilibx_macos/libmlx.a
	@rm -f $(NAME)

re: fclean all

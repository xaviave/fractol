/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:01:27 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:17:40 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/header/libft.h"
# include <math.h>

# define WIDTH 1800
# define HEIGHT 1200 

/*
** functions
*/

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	int				i;
}					t_color;

typedef struct		s_win
{
	void			*win_ptr;
	int				width;
	int				height;
}					t_win;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_frac
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			tmp;
}					t_frac;

typedef struct		s_mem
{
	t_win			win;
	t_img			img;
	t_color			color;
	t_color			black;
	void			*mlx_ptr;
	int				map;
	long			x;
	long			y;
	long			z;
	int				option_x;
	int				option_y;
	int				mouse_stop;
	void			(*fractal)();
	unsigned int	max_iter;
	t_frac			*frac;
}					t_mem;


void				ft_create_img(t_mem *mem);
void				ft_put_pixel(t_mem *mem, int x, int y, t_color color);
t_color				get_color(int a, t_mem *mem);

int					key_hook(int key, t_mem *mem);
int					mouse_move_hook(int x, int y, t_mem *mem);
int					mouse_click_hook(int k, int x, int y, t_mem *mem);
int					loop_hook(t_mem *mem);
void				zoom_in(t_mem *mem);
void				zoom_out(t_mem *mem);

void				init(t_mem *mem);
void				free_all(t_mem *mem);

void				julia(t_mem *mem);
void				mandelbrot(t_mem *mem);
void				burningship(t_mem *mem);

/*
** keyboard touch value
*/

# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define TOUCH_1 18
# define TOUCH_2 19
# define TOUCH_3 20
# define TOUCH_4 21
# define TOUCH_5 23
# define TOUCH_6 22
# define TOUCH_7 26
# define TOUCH_8 28
# define TOUCH_9 25
# define TOUCH_0 29
# define TOUCH_Q 12
# define TOUCH_W 13
# define TOUCH_E 14
# define TOUCH_R 15
# define TOUCH_T 17
# define TOUCH_Y 16
# define TOUCH_A 0
# define TOUCH_S 1
# define TOUCH_D 2
# define TOUCH_F 3
# define TOUCH_G 5
# define TOUCH_Z 6
# define TOUCH_X 7
# define TOUCH_C 8
# define TOUCH_V 9
# define TOUCH_B 11
# define TOUCH_ECHAP 53
# define TOUCH_ENTER 36
# define TOUCH_LEFT 123
# define TOUCH_RIGHT 124
# define TOUCH_DOWN 125
# define TOUCH_UP 126
# define TOUCH_NUMPAD_0 82
# define TOUCH_NUMPAD_1 83
# define TOUCH_NUMPAD_2 84
# define TOUCH_NUMPAD_3 85
# define TOUCH_NUMPAD_4 86
# define TOUCH_NUMPAD_5 87
# define TOUCH_NUMPAD_6 88
# define TOUCH_NUMPAD_7 89
# define TOUCH_NUMPAD_8 91
# define TOUCH_NUMPAD_9 92
# define TOUCH_NUMPAD_POINT 65
# define TOUCH_NUMPAD_ENTER 76
# define TOUCH_NUMPAD_PLUS 69
# define TOUCH_NUMPAD_LESS 78
# define TOUCH_NUMPAD_TIMES 67
# define TOUCH_NUMPAD_DIVIDE 75
# define TOUCH_NUMPAD_NUM 71
# define TOUCH_NUMPAD_INSERT 114
# define TOUCH_NUMPAD_END 119
# define TOUCH_NUMPAD_DELL 117
# define TOUCH_NUMPAD_PAGEUP 116
# define TOUCH_NUMPAD_PAGEDOWN 121
# define TOUCH_NUMPAD_HOME 115
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

#endif

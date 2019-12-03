/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 15:28:23 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 13:29:35 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	key_move(int k, t_mem *mem)
{
	if (k == TOUCH_UP)
	{
		mem->y += 100;
		mem->fractal(mem);
	}
	if (k == TOUCH_DOWN)
	{
		mem->y -= 100;
		mem->fractal(mem);
	}
	if (k == TOUCH_LEFT)
	{
		mem->x += 100;
		mem->fractal(mem);
	}
	if (k == TOUCH_RIGHT)
	{
		mem->x -= 100;
		mem->fractal(mem);
	}
}

static void	key_zoom(int k, t_mem *mem)
{
	if (k == TOUCH_NUMPAD_PLUS)
		zoom_in(mem);
	if (k == TOUCH_NUMPAD_LESS)
		zoom_out(mem);
}

static void	key_reset(int k, t_mem *mem)
{
	if (k == TOUCH_R)
	{
		mem->z = 150;
		mem->x = -WIDTH / 3;
		mem->y = -HEIGHT / 3;
		mem->option_x = WIDTH / 2;
		mem->option_y = HEIGHT / 2;
		mem->color.i = 0;
		mem->max_iter = 50;
		mem->mouse_stop = 0;
	}
}

static void	key_color(int k, t_mem *mem)
{
	if (k == TOUCH_C)
		mem->color.i += 10;
	if (k == TOUCH_V)
		mem->color.i -= 10;
}

int			key_hook(int k, t_mem *mem)
{
	key_zoom(k, mem);
	key_move(k, mem);
	key_reset(k, mem);
	key_color(k, mem);
	if (k == TOUCH_2)
		mem->max_iter += 10;
	if (k == TOUCH_1)
		mem->max_iter -= 10;
	if (k == TOUCH_ECHAP)
	{
		free_all(mem);
		exit(1);
	}
	if (k == TOUCH_S)
		mem->mouse_stop = !mem->mouse_stop;
	mem->fractal(mem);
	return (0);
}

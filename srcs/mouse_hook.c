/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_hook.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:17:44 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:32:54 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_move_hook(int x, int y, t_mem *mem)
{
	if (x < 0 || x >= mem->win.width || y < 0 || y >= mem->win.height ||
			mem->mouse_stop == 1)
		return (0);
	mem->option_x = x;
	mem->option_y = y;
	mem->fractal(mem);
	return (0);
}

int		mouse_click_hook(int k, int x, int y, t_mem *mem)
{
	if (k == MOUSE_ZOOM_IN)
	{
		mem->x += x / 5;
		mem->y += y / 5;
		mem->z = mem->z * 1.2;
		mem->y = mem->y * 1.2;
		mem->x = mem->x * 1.2;
	}
	if (k == MOUSE_ZOOM_OUT)
	{
		mem->x -= x / 5;
		mem->y -= y / 5;
		mem->z = mem->z / 1.2;
		mem->y = mem->y / 1.2;
		mem->x = mem->x / 1.2;
	}
	mem->fractal(mem);
	return (0);
}

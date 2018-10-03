/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:26:51 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:56:12 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_move_hook(int x, int y, t_mem *mem)
{
	if (x < 0 || x >= mem->win.width || y < 0 || y >= mem->win.height)
		return (0);
	mem->color.r += x / y % 255;
	mem->color.b += x * y % 255;
	mem->color.g += x + y % 255;
	loop(mem);
	return (0);
}

int			mouse_click_hook(int k, int x, int y, t_mem *mem)
{
	x = y;
	if (k == 4)
		mem->zoom += 0.1;
	if (k == 5 && mem->zoom > 0.1)
		mem->zoom -= 0.1;
	loop(mem);
	//if (mem)
	//;
	return (0);
}

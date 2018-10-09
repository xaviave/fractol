/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/03/14 17:41:57 by adespond     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:50:43 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../include/fractol.h"

static int		julia_iter(t_mem *mem)
{
	int		i;

	i = -1;
	while (++i < mem->max_iter)
	{
		mem->frac->tmp = mem->frac->zr;
		mem->frac->zr = mem->frac->zr * mem->frac->zr - mem->frac->zi
			* mem->frac->zi - 0.8 + (0.6 /
			((double)mem->option_x / (double)mem->win.width));
		mem->frac->zi = 2 * mem->frac->zi * mem->frac->tmp + 0.27015 /
			((double)mem->option_y / (double)mem->win.height);
		if (mem->frac->zr * mem->frac->zr + mem->frac->zi * mem->frac->zi >= 4)
			return (i);
	}
	return (i);
}

void			julia(t_mem *mem)
{
	intmax_t	x;
	intmax_t	y;

	x = mem->x;
	while (++x < mem->win.width + mem->x)
	{
		y = mem->y;
		while (++y < mem->win.height + mem->y)
		{
			mem->frac->zr = (long double)x / mem->z + mem->frac->x1;
			mem->frac->zi = (long double)y / mem->z + mem->frac->y1;
			ft_put_pixel(mem, x - mem->x, y - mem->y,
				get_color(julia_iter(mem), mem));
		}
	}
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

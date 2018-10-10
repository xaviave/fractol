/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/03/14 17:41:57 by adespond     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:28:58 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

static int		julia_iter(t_mem *mem)
{
	int			i;

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

void			ft_fill_image(t_mem *mem)
{
	int			i;
	int			j;
	t_color		color;

	i = 0;
	j = 0;
	color.r = 0;
	color.g = 0;
	color.g = 0;
	color.a = 0;
	while (i < mem->win.height)
	{
		while (j < mem->win.width)
		{
			ft_put_pixel(mem, j, i, mem->black);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

void			julia(t_mem *mem)
{
	long		x;
	long		y;

	x = mem->x;
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_fill_image(mem);
	while (++x < mem->win.width + mem->x)
	{
		y = mem->y;
		while (++y < mem->win.height + mem->y)
		{
			mem->frac->zr = (double)x / mem->z + mem->frac->x1;
			mem->frac->zi = (double)y / mem->z + mem->frac->y1;
			ft_put_pixel(mem, x - mem->x, y - mem->y,
					get_color(julia_iter(mem), mem));
		}
	}
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

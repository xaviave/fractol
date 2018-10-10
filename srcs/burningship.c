/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burningship.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:14:05 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:23:36 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	burningship_iter(t_mem *mem)
{
	int		i;

	i = -1;
	while (++i < mem->max_iter)
	{
		mem->frac->tmp = mem->frac->zr;
		mem->frac->zr = mem->frac->zr * mem->frac->zr - mem->frac->zi
			* mem->frac->zi + mem->frac->cr;
		mem->frac->zi = 2 * fabsl(mem->frac->zi * mem->frac->tmp)
			+ mem->frac->ci;
		if (mem->frac->zr * mem->frac->zr + mem->frac->zi * mem->frac->zi >= 4)
			return (i);
	}
	return (i);
}

void		burningship(t_mem *mem)
{
	long	x;
	long	y;

	x = mem->x;
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_fill_image(mem);
	while (++x < mem->win.width + mem->x)
	{
		y = mem->y;
		while (++y < mem->win.height + mem->y)
		{
			mem->frac->zr = 0;
			mem->frac->zi = 0;
			mem->frac->cr = (double)x / mem->z + mem->frac->x1;
			mem->frac->ci = (double)y / mem->z + mem->frac->y1;
			ft_put_pixel(mem, x - mem->x, y - mem->y,
				get_color(burningship_iter(mem), mem));
		}
	}
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:28:45 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 17:35:41 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_put_pixel(t_mem *mem, t_color color, int x, int y)
{
	int		bpp;

	bpp = mem->img.bpp / 8;
	if ((x > 0 && x < mem->win.width) && (y > 0 && y < mem->win.height))
	{
		mem->img.data[(x * bpp) + (mem->img.sizeline * y)] = color.b;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 1] = color.g;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 2] = color.r;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 3] = color.a;
	}
}

void		ft_fill_image(t_mem *mem)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.a = 0;
	while (i < mem->win.height)
	{
		j = 0;
		while (j < mem->win.width)
		{
			ft_put_pixel(mem, color, j, i);
			j++;
		}
		i++;
	}
}

void		ft_create_img(t_mem *mem)
{
	mem->img.ptr = mlx_new_image(mem->mlx_ptr, mem->win.width, mem->win.height);
	mem->img.data = mlx_get_data_addr(mem->img.ptr, &mem->img.bpp,
		&mem->img.sizeline, &mem->img.endian);
}

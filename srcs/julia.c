/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:56:49 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:59:15 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int COLOR_TABLE[] = {
 	0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
 	0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
    0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
    0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
    0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
    0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
    0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
    0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
    0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
    0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
    0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
    0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
    0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
    0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
    0xffe0, 0x9e66, 0x0000
};

void julia(t_mem *mem)
{
	int				x;
	int				y;
	double			p_r;
	double			p_i;
	double			new_i;
	double			new_r;
	double			old_i;
	double			old_r;
	unsigned int	color;
	unsigned int	i;

	x = 0;
	ft_fill_image(mem);
	while (x < mem->win.width)
	{
		y = 0;
	    p_r = 1.5 * (x - mem->win.height / 2.0) / (0.5 * mem->zoom * mem->win.height) + mem->x;
		while (y < mem->win.height)
		{
	        p_i = (y - mem->win.height / 2.0) / (0.5 * mem->zoom * mem->win.height) + mem->y;
	        new_r = new_i = old_r = old_i = 0;
	        i = 0;
	        while (((new_r * new_r) + (new_i * new_i) < 4.0) && i < mem->max_iter)
			{
	            old_r = new_r;
	            old_i = new_i;
	            new_r = old_r * old_r - old_i * old_i + p_r;
	            new_i = 2.0 * old_r * old_i + p_i;
	            i++;
			}
	        color = COLOR_TABLE[i];
	        mem->color.r = ((color >> 11) & 0x1F) << 3;
	        mem->color.g = ((color >> 5) & 0x3F) << 2;
	        mem->color.b = (color & 0x1F) << 3;
	        ft_put_pixel(mem, mem->color, x, y);
			y++;
		}
		x++;
	}
}

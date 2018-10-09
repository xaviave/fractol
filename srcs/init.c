/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:22:14 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:49:47 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void				free_all(t_mem *mem)
{
	free(mem->frac);
}

static t_frac		*init_frac(void)
{
	t_frac	*frac;

	if (!(frac = (t_frac *)malloc(sizeof(t_frac))))
		return (NULL);
	frac->x1 = -2.1;
	frac->x2 = 0.6;
	frac->y1 = -1.2;
	frac->y2 = 1.2;
	frac->zr = 0;
	frac->zi = 0;
	frac->cr = 0;
	frac->ci = 0;
	frac->tmp = 0;
	return (frac);
}

void			init(t_mem *mem)
{
	mem->win.width = WIDTH;
	mem->win.height = HEIGHT;
	mem->x = -WIDTH / 3;
	mem->y = -HEIGHT / 3;
	mem->z = 150;
	mem->option_x = WIDTH / 2;
	mem->option_y = HEIGHT / 2;
	mem->mlx_ptr = mlx_init();
	mem->max_iter = 50;
	mem->mouse_stop = 0;
	ft_create_img(mem);
	mem->frac = init_frac();
}

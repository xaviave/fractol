/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 11:00:58 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:59:27 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		loop(t_mem *mem)
{
	ft_fill_image(mem);
	choose_frac(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

void		init_struct(t_mem *mem)
{
	mem->x = -0.75;
	mem->y = -0.0;
	mem->zoom = 0.8;
	mem->max_iter = 30;
	mem->color.r = 0;
	mem->color.g = 20;
	mem->color.b = 199;
	mem->color.a = 0;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "fract'ol");
	ft_create_img(mem);
}

void		choose_frac(t_mem *mem)
{
	if (mem->map == 1)
		julia(mem);
	else if (mem->map == 2)
		mandelbrot(mem);
	else if (mem->map == 3)
		burningship(mem);
}

void		menu(t_mem *mem)
{
	init_struct(mem);
	loop(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_hook(mem->win.win_ptr, 6, OPTION, mouse_move_hook, mem);
	mlx_mouse_hook(mem->win.win_ptr, mouse_click_hook, mem);
	mlx_loop_hook(mem->mlx_ptr, loop_hook, mem);
	mlx_loop(mem->mlx_ptr);
}

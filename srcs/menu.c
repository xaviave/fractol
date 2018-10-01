/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 11:00:58 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 17:05:52 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_pixel(t_mem *mem, t_color color, int x, int y)
{
	int				bpp;

	bpp = mem->img.bpp / 8;
	if ((x > 0 && x < mem->win.width) && (y > 0 && y < mem->win.height))
	{
		mem->img.data[(x * bpp) + (mem->img.sizeline * y)] = color.b;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 1] = color.g;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 2] = color.r;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 3] = color.a;
	}
}

static void	ft_fill_image(t_mem *mem)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	color.r = 0;
	color.g = 50;
	color.b = 100;
	color.a = 0;
	while (i < 900)
	{
		j = 0;
		while (j < 1800)
		{
			ft_put_pixel(mem, color, j, i);
			j++;
		}
		i++;
	}
}

void	ft_create_img(t_mem *mem)
{
	mem->img.ptr = mlx_new_image(mem->mlx_ptr, mem->win.width, mem->win.height);
	mem->img.data = mlx_get_data_addr(mem->img.ptr, &mem->img.bpp,
		&mem->img.sizeline, &mem->img.endian);
}

void		test_aff(t_mem *mem)
{
	int i;
	int j = -1;
	while (++j < mem->size)
	{
		i = -1;
	while (++i < mem->size)
	{
		if (mem->test_x < mem->win.width)
			ft_put_pixel(mem, mem->color, mem->test_x + i, mem->test_y + j);
		else
			mem->test_x = 0;
	}
	}
}

void		loop(t_mem *mem)
{
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_fill_image(mem);
	test_aff(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

int			ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_RIGHT)
		mem->test_x += 10;
	if (key == TOUCH_LEFT)
		mem->test_x -= 10;
	if (key == TOUCH_UP)
		mem->test_y -= 10;
	if (key == TOUCH_DOWN)
		mem->test_y += 10;
	if (key == TOUCH_ECHAP)
		exit(0);
	loop(mem);
	return (0);
}

int			mouse_move_hook(int x, int y, t_mem *mem)
{
	if (x < 0 || x >= mem->win.width || y < 0 || y >= mem->win.height)
		return (0);
	mem->test_x = x;
	mem->test_y = y;
	mem->color.r += x / y % 255;
	mem->color.b += x * y % 255;
	mem->color.g += x + y % 255;
	loop(mem);
	return (0);
}

int		mouse_click_hook(int k, int x, int y, t_mem *mem)
{
	x = y;
	if (k == 5)
		mem->size *= 2 % mem->win.height;
	if (k == 4)
		mem->size /= 2 % mem->win.height;
	if (mem->size < 1)
	mem->size = 1;
	loop(mem);
	return (0);
}

int		loop_hook(t_mem *mem)
{
	//faire un zoom infini si plus rien n est touché
	loop(mem);
	return (0);
}

void		menu(t_mem *mem)
{
	mem->size = 25;
	mem->test_x = 0;
	mem->test_y = 10;
	mem->color.r = 155;
	mem->color.g = 200;
	mem->color.b = 100;
	mem->color.a = 0;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "fractol");
	ft_create_img(mem);
	ft_fill_image(mem);
	loop(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_hook(mem->win.win_ptr, 6, 1L<<6, mouse_move_hook, mem);
	mlx_mouse_hook(mem->win.win_ptr, mouse_click_hook, mem);
	mlx_loop_hook(mem->mlx_ptr, loop_hook, mem);
	mlx_loop(mem->mlx_ptr);
	//free_mem();
}
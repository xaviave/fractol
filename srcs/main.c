/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/03/14 20:09:39 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:29:59 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	usage(void)
{
	ft_printf("Usage : ./fractol [ map ]\n\n");
	ft_printf("map = [ Julia / Mandelbrot / Burning ship ]\n");
	return (0);
}

static int	choose_fractal(t_mem *mem, char *av)
{
	if (!ft_strcmp("Julia", av))
	{
		mem->map = 1;
		mem->fractal = julia;
	}
	else if (!ft_strcmp("Burning ship", av))
	{
		mem->map = 3;
		mem->fractal = burningship;
	}
	else if (!ft_strcmp("Mandelbrot", av))
	{
		mem->fractal = mandelbrot;
		mem->map = 2;
	}
	else
		return (0);
	return (1);
}

static int	cross_close(t_mem *mem)
{
	free_all(mem);
	exit(1);
}

static void	fractol(t_mem *mem)
{
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "Fractol du swag");
	mem->fractal(mem);
	mlx_hook(mem->win.win_ptr, 17, 0L, cross_close, mem);
	mlx_hook(mem->win.win_ptr, MOTION_NOTIFY, PTR_MOTION_MASK,
			mouse_move_hook, mem);
	mlx_mouse_hook(mem->win.win_ptr, mouse_click_hook, mem);
	mlx_key_hook(mem->win.win_ptr, key_hook, mem);
	mlx_loop(mem->mlx_ptr);
}

int			main(int ac, char *av[])
{
	t_mem	mem;

	if (ac != 2 || !choose_fractal(&mem, av[ac - 1]))
		return (usage());
	init(&mem);
	fractol(&mem);
	return (0);
}

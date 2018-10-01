/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 10:58:23 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 17:05:54 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			usage(void)
{
	ft_printf("Usage : ./fractol [ map ]\n\n");
	ft_printf("map = [ Julia / Mandelbrot / Burning ship ]\n");
	return (0);
}

int			choose_fractale(t_mem *mem, char *av)
{
	if (!ft_strcmp("Julia", av))
		mem->map = 1;
	else if (!ft_strcmp("Burning ship", av))
		mem->map = 2;
	else if (!ft_strcmp("mandelbrot", av))
		mem->map = 3;
	else
		return (usage());
	return (1);
}

int			main(int ac, char **av)
{
	t_mem	mem;
	
	if (!choose_fractale(&mem, av[ac - 1]))
		return (0);
	menu(&mem);
	return (1);
}
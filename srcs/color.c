/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:23:13 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:49:44 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color				get_color(int a, t_mem *mem)
{
	t_color			color;

	if (a == mem->max_iter)
		return (mem->black);
	color.r = (a * 5) + 30 + mem->color.i;
	color.g = (255 - (a * 10)) + 150 + mem->color.i;
	color.b = (255 - (a * 2)) + 150 + mem->color.i;
	return (color);
}

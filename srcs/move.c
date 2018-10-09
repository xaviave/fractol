/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:17:06 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:16:52 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_mem *mem)
{
	mem->x += mem->win.width / 12;
	mem->y += mem->win.height / 12;
	mem->z = mem->z * 1.2;
	mem->x = mem->x * 1.2;
	mem->y = mem->y * 1.2;
}

void	zoom_out(t_mem *mem)
{
	if (mem->z / 1.2 < 10)
		return ;
	mem->x -= mem->win.width / 12;
	mem->y -= mem->win.height / 12;
	mem->z = mem->z / 1.2;
	mem->x = mem->x / 1.2;
	mem->y = mem->y / 1.2;
}

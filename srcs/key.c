/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <xamartin@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:29:14 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:00:48 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_RIGHT)
		mem->x -= 0.1;
	if (key == TOUCH_LEFT)
		mem->x += 0.1;
	if (key == TOUCH_DOWN)
		mem->y -= 0.1;		
	if (key == TOUCH_UP)
		mem->y += 0.1;
	if (key == TOUCH_NUMPAD_PLUS)
		mem->max_iter += 10;
	if (key == TOUCH_NUMPAD_LESS && mem->max_iter > 10)
		mem->max_iter -= 10;
	if (key == TOUCH_ECHAP)
		exit(0);
	loop(mem);
	return (0);
}

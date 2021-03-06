/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:59 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 14:56:35 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	fractol_map(int value, float min1, float max1, float min2, float max2)
{
	float	a;
	float	b;
	float	c;
	float	res;

	a = value - min1;
	b = max1 - min1;
	c = max2 - min2;
	res = a / b * c + min2;
	return (res);
}

void	draw_burningship(t_node *tool)
{
	int		x;
	int		y;
	float	a;
	float	aa;
	float	b;
	float	bb;
	float	ca;
	float	cb;
	int		n;
	int		maxiterations;
	float	color;

	maxiterations = 100;
	y = 0;
	while (y < WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_SIZE_WIDTH)
		{
			a = fractol_map(x, 0, WINDOW_SIZE_WIDTH, -2, 2);
			b = fractol_map(y, 0, WINDOW_SIZE_HEIGHT, -2, 2);
			ca = a;
			cb = b;
			n = 0;
			while (n < maxiterations)
			{
				aa = a * a - b * b;
				bb = 2.0 * ft_fabs(a * b);
				a = aa + ca;
				b = bb + cb;
				if (ft_fabs(a + b) > 16.0)
					break ;
				n++;
			}
			if (n == maxiterations)
			{
				color = 0;
			}
			else
			{
				color = fractol_map(n, 0, maxiterations, 0, 255255255);
			}
			image_pixel_put(tool, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
											tool->img_ptr, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/12 14:50:31 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse(double x, double y, void *vdata)
{
	t_data			*data;
	static double	scale;

	(void)x;
	if (scale == 0)
		scale = 1;
	data = (t_data *)vdata;
	if (y > 0)
		scale -= 0.01;
	else if (y < 0)
		scale += 0.01;
	data->scale = scale;
	ft_draw_fractal(data);
}

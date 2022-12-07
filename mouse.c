/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/07 22:06:11 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse(double x, double y, void *vdata)
{
	t_data	*data;

	data = vdata;
	//printf("X: %f Y: %f\n", x, y);
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	printf("X: %d Y: %d\n", data->mouse_x, data->mouse_y);
	printf("X: %f Y: %f\n", x, y);
	//data->mouse_x = x;
	//data->mouse_y = y;
}

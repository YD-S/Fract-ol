/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/08 19:05:10 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse(double x, double y, void *vdata)
{
	t_data	*data;

	data = vdata;
	(void)data;
	//printf("X: %f Y: %f\n", x, y);;
	printf("X: %f Y: %f\n", x, y);
	//data->mouse_x = x;
	//data->mouse_y = y;
}

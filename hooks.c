/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:41 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 03:08:33 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(data->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP)
			data->y_y -= 0.50;
		if (keydata.key == MLX_KEY_DOWN)
			data->y_y += 0.50;
		if (keydata.key == MLX_KEY_LEFT)
			data->x_x -= 0.50;
		if (keydata.key == MLX_KEY_RIGHT)
			data->x_x += 0.50;
		ft_color_hook(keydata, data);
		if (data->fractal == 0)
			hook_move(keydata, data);
		ft_draw_fractal(data);
	}
}

void	ft_color_hook(struct mlx_key_data keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_P)
		data->max_iter += 10;
	if (keydata.key == MLX_KEY_L)
		data->max_iter -= 10;
	if (keydata.key == MLX_KEY_N)
	{
		data->hue_off = 0.;
		data->rainbow = 0;
	}
	if (keydata.key == MLX_KEY_M)
		data->rainbow = !data->rainbow;
}

void	hook_move(struct mlx_key_data keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_Y)
		data->v2 += 0.01f;
	if (keydata.key == MLX_KEY_H)
		data->v2 -= 0.01f;
	if (keydata.key == MLX_KEY_G)
		data->v1 += 0.01f;
	if (keydata.key == MLX_KEY_T)
		data->v1 -= 0.01f;
	free(data->complex);
	data->complex = ft_create_complex(data->v1, data->v2);
}

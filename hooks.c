/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:41 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/08 23:43:12 by ysingh           ###   ########.fr       */
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
		if (keydata.key == MLX_KEY_W)
			data->y_y -= 0.50;
		if (keydata.key == MLX_KEY_S)
			data->y_y += 0.50;
		if (keydata.key == MLX_KEY_A)
			data->x_x -= 0.50;
		if (keydata.key == MLX_KEY_D)
			data->x_x += 0.50;
		if (keydata.key == MLX_KEY_N)
		{
			data->hue_off = 0.;
			data->rainbow = 0;
		}
		if (keydata.key == MLX_KEY_M)
			data->rainbow = !data->rainbow;
		hook_scale(keydata, data);
	}
	hook_move(keydata, data);
	ft_draw_fractal(data);
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
	data->complex = ft_create_complex(data->v1, data->v2);
}

void	hook_scale(struct mlx_key_data keydata, t_data *mlx)
{
	if (keydata.key == MLX_KEY_DOWN)
		mlx->scale *= 1.25f;
	if (keydata.key == MLX_KEY_UP)
		mlx->scale *= 0.75f;
	if (keydata.key == MLX_KEY_L)
		mlx->max_iter += 2;
	if (keydata.key == MLX_KEY_P)
		mlx->max_iter -= 2;
}

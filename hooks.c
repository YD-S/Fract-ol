/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:41 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/07 21:59:13 by ysingh           ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_W)
		data->y_y -= 0.50;
	if (keydata.key == MLX_KEY_S)
		data->y_y += 0.50;
	if (keydata.key == MLX_KEY_A)
		data->x_x -= 0.50;
	if (keydata.key == MLX_KEY_D)
		data->x_x += 0.50;
	hook_scale(keydata, data);
	ft_draw_fractal(data);
}

void	hook_scale(struct mlx_key_data keydata, t_data *mlx)
{
	if (keydata.key == MLX_KEY_DOWN)
		mlx->scale *= 1.25f;
	if (keydata.key == MLX_KEY_UP)
		mlx->scale *= 0.75f;
	if (keydata.key == MLX_KEY_L)
		mlx->max_iter += 5;
	if (keydata.key == MLX_KEY_P)
		mlx->max_iter -= 5;
}

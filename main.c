/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:49 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 01:56:28 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1 || argc > 4)
	{
		ft_arg_error(data.mlx);
		exit(EXIT_FAILURE);
	}
	data = ft_fractal_init();
	if (!ft_choose_fractal(argv, argc, &data))
	{
		exit(EXIT_FAILURE);
		mlx_terminate(data.mlx);
	}
	ft_draw_fractal(&data);
	mlx_scroll_hook(data.mlx, &ft_mouse, &data);
	mlx_key_hook(data.mlx, &hook, &data);
	mlx_loop_hook(data.mlx, &ft_color_shift, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

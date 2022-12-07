/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:49 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/06 22:02:48 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
	{
		ft_printf("There are no valid arguments");
		exit(EXIT_FAILURE);
	}
	data = ft_fractal_init();
	if (!ft_choose_fractal(argv, &data))
	{
		mlx_terminate(data.mlx);
		exit(EXIT_FAILURE);
	}
	ft_draw_fractal(&data);
	mlx_cursor_hook(data.mlx, &ft_mouse, &data);
	mlx_key_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	system("leaks -q fractol");
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

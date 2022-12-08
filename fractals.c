/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:26 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/08 16:12:45 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	ft_fractal_init(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Fract-Ol", false);
	data.scale = 1;
	data.x_off = -WIDTH / 2;
	data.y_off = -HEIGHT / 2;
	data.max_iter = 40;
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	return (data);
}

int	ft_choose_fractal(char **argv, int argc, t_data *data)
{
	if (!ft_strncmp(argv[1], "julia", 5))
		farctol_julia(data, argv);
	else if (!ft_strncmp(argv[1], "mandelbrot", 10))
		fractol_mandelbrot(data, argc);
	else if (!ft_strncmp(argv[1], "burningship", 11))
		data->fractal = 2;
	else
	{
		ft_arg_error();
		return (0);
	}
	return (1);
}

void	ft_draw_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	*complex;

	complex = ft_create_complex(0, 0);
	x = 0;
	while ((unsigned int)x < WIDTH)
	{
		y = 0;
		while ((unsigned int)y < HEIGHT)
		{
			ft_check_fractal(data, complex, x, y);
			y++;
		}
		x++;
	}
	free(complex);
}

void	ft_check_fractal(t_data *data, t_complex *complex, int x, int y)
{
	complex->real = (double)(-2 + data->x_x + (x * data->scale / (double)WIDTH)
			* 3);
	complex->imagine = (double)(-1 + data->y_y + (y * data->scale
				/ (double)HEIGHT) * 2);
	if (data->fractal == 1)
		mlx_put_pixel(data->img, x, y, ft_fractal_color(ft_mandelbrot(complex,
					data), data));
	else if (data->fractal == 0)
		mlx_put_pixel(data->img, x, y, ft_fractal_color(ft_julia(data->complex,
					complex, data), data));
	// else
	// 	mlx_put_pixel(data->img, x, y,
	// 		ft_fractal_color(ft_burning_ship(complex, data), data));
}

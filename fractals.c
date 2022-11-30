#include "fractol.h"

t_data	ft_fractal_init(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Fract-Ol", false);
	data.scale = 1;
	data.x_off = -WIDTH / 2;
	data.y_off = -HEIGHT / 2;
	data.max_iter = 50;
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	return (data);
}

int	ft_choose_fractal(char **argv, t_data *data)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		data->fractal = 1;
	else if (!ft_strncmp(argv[1], "julia", 5))
		data->fractal = 0;
	else
	{
		ft_printf("No hay argumenos valido");
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
			ft_transform_pixel(x, y, data);
			complex->real = (double)(((-2 + data->x_x) / (double)WIDTH) * 3);
			complex->imagine = (double)(((-1 + data->y_y) / (double)HEIGHT)
					* 2);
			if (data->fractal)
				mlx_put_pixel(data->img, x, y,
					ft_fractal_color(ft_mandelbrot(complex, data), data));
			// else
			// 	mlx_put_pixel(data->img, x, y,
			// 		ft_fractal_color(ft_julia(complex)));
			y++;
		}
		x++;
	}
	free(complex);
}

#include "fractol.h"

double	ft_mandelbrot(t_complex *complex)
{
	t_complex	*j;
	int			n;
	double		result;

	j = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(j) <= 2 && n < MAX_ITERATIONS)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, complex);
		n++;
	}
	if (n == MAX_ITERATIONS)
		return (free(j), MAX_ITERATIONS);
	result = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (result);
}

t_data	*ft_stuct_mandelbrot(mlx_image_t *img)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->x_off = 0;
	data->y_off = 0;
	data->scale = 1;
	data->img = img;
	return (data);
}

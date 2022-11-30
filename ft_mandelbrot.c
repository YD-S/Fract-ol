#include "fractol.h"

double	ft_mandelbrot(t_complex *complex, t_data *data)
{
	t_complex	*j;
	int			n;
	double		result;

	j = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(j) <= 2 * 2 && n < data->max_iter)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, complex);
		n++;
	}
	if (n == data->max_iter)
		return (free(j), data->max_iter);
	result = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (result);
}

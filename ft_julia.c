#include "fractol.h"

double	ft_julia(t_complex *c, t_complex *z0, t_data *data)
{
	t_complex	*j;
	int			n;
	double		result;

	j = ft_create_complex(z0->real, z0->imagine);
	n = 0;
	while (ft_complex_module(j) <= 2 * 2 && n < data->max_iter)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, c);
		n++;
	}
	if (n == data->max_iter)
		return (free(j), data->max_iter);
	result = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:37 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 01:28:41 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_mandelbrot(t_complex *complex, t_data *data)
{
	t_complex	*j;
	int			n;
	double		result;

	j = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(j) <= 4 && n < data->max_iter)
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

void	fractol_mandelbrot(t_data *data, int argc)
{
	if (argc > 2)
	{
		ft_arg_error(data->mlx);
		exit(EXIT_FAILURE);
	}
	data->fractal = 1;
}

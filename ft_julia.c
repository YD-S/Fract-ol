/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:00:45 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/08 03:08:09 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_julia(t_complex *c, t_complex *z0, t_data *data)
{
	t_complex	*j;
	int			n;
	double		module;

	z0->real += 0.5f;
	j = ft_create_complex(z0->real, z0->imagine);
	n = 0;
	while (ft_complex_module(j) <= 4 && n < data->max_iter)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, c);
		n++;
	}
	if (n == data->max_iter)
		return (free(j), data->max_iter);
	module = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (module);
}

void	farctol_julia(t_data *data, char **argv)
{
	double	v1;
	double	v2;

	if (!ft_is_double(argv[2]) || !ft_is_double(argv[3]))
	{
		ft_arg_error();
		exit(EXIT_FAILURE);
	}
	v1 = atof(argv[2]);
	v2 = atof(argv[3]);
	data->fractal = 0;
	data->complex = ft_create_complex(v1, v2);
}

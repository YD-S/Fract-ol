/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:00:45 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 01:28:35 by ysingh           ###   ########.fr       */
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

void	fractol_julia(t_data *data, char **argv)
{
	data->v1 = ft_atof(argv[2]);
	data->v2 = ft_atof(argv[3]);
	if (!ft_is_double(argv[2]) || !ft_is_double(argv[3]))
	{
		ft_arg_error(data->mlx);
		exit(EXIT_FAILURE);
	}
	data->fractal = 0;
	data->complex = ft_create_complex(data->v1, data->v2);
}

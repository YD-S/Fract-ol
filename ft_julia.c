/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:00:45 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/07 22:28:06 by ysingh           ###   ########.fr       */
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

double	ft_atof(char *str)
{
	double	mod;
	double	dec;
	int		i;
	int		sign;

	i = 0;
	mod = 0;
	dec = 0;
	sign = 1;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] && str[i] != '.')
	{
		mod = mod * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i++])
		dec = dec * 10 + str[i] - '0';
	while (dec > 2)
		dec /= 10;
	return (mod + dec * sign);
}

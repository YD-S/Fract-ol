/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:07:44 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/08 03:08:13 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_double(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
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

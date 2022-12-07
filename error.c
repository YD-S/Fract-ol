/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:08:25 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/07 22:14:11 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_arg_error(void)
{
	ft_printf("\nUsage: ./fractol [fractal name]\n");
	ft_printf("Available fractals: mandelbrot,");
	ft_printf(" julia [Complex Nº], burning_ship\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:11 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 00:03:09 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractal_color(double n, t_data *data)
{
	double	hue;
	double	sat;
	double	value;

	hue = 255 * n / data->max_iter;
	sat = 255;
	if (n == (double)data->max_iter)
		value = 0;
	else
		value = 255;
	hue = (int)((hue / 255.) * 360. + data->hue_off) % 360;
	sat /= 255.;
	value /= 255.;
	return (hsv2rgb((t_hsv){hue, sat, value}));
}

static t_rgb	hsv2rgb2(t_hsv hsv, t_pqt pqt)
{
	t_rgb	rgb;

	if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.r = hsv.v, .g = pqt.t, .b = pqt.p};
	else if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.r = pqt.q, .g = hsv.v, .b = pqt.p};
	else if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.r = pqt.p, .g = hsv.v, .b = pqt.t};
	else if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.r = pqt.p, .g = pqt.q, .b = hsv.v};
	else if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.r = pqt.t, .g = pqt.p, .b = hsv.v};
	else if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.r = hsv.v, .g = pqt.p, .b = pqt.q};
	else
		rgb = (t_rgb){.r = 0., .g = 0., .b = 0.};
	return (rgb);
}

uint32_t	hsv2rgb(t_hsv hsv)
{
	t_rgb	rgb;
	t_pqt	pqt;
	double	fract;

	if (hsv.h == 360.)
		hsv.h = 0.;
	else
		hsv.h /= 60.;
	fract = hsv.h - floor(hsv.h);
	pqt = (t_pqt){hsv.v * (1. - hsv.s), hsv.v * (1. - hsv.s * fract), hsv.v
		* (1. - hsv.s * (1. - fract))};
	rgb = hsv2rgb2(hsv, pqt);
	return ((int)(rgb.r * 255) << 24 | (int)(rgb.g * 255) << 16 | (int)(rgb.b
			* 255) << 8 | 255);
}

void	ft_color_shift(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->rainbow)
	{
		data->hue_off += 8.;
		ft_draw_fractal(data);
	}
}

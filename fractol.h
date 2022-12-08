/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:36:32 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/09 00:28:39 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 400
# define SPEED 25

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct s_pqt
{
	double		p;
	double		q;
	double		t;
}				t_pqt;

typedef struct s_complex
{
	double		imagine;
	double		real;
}				t_complex;

typedef struct s_data
{
	int			fractal;
	int			max_iter;
	int			rainbow;
	double		x_x;
	double		y_y;
	double		x_off;
	double		y_off;
	double		scale;
	double		v1;
	double		v2;
	double		hue_off;
	t_complex	*complex;
	mlx_image_t	*img;
	mlx_t		*mlx;
}				t_data;

int				ft_choose_fractal(char **argv, int argc, t_data *data);
double			ft_mandelbrot(t_complex *complex, t_data *data);
void			ft_draw_fractal(t_data *data);
int				ft_fractal_color(double n, t_data *data);
t_complex		*ft_create_complex(double real, double imagine);
void			ft_complex_addnum(t_complex *n1, t_complex *n2);
void			ft_complex_mul(t_complex *n1, t_complex *n2);
float			ft_complex_module(t_complex *complex);
void			ft_mouse(double x, double y, void *vdata);
uint32_t		hsv2rgb(t_hsv hsv);
t_data			ft_fractal_init(void);
void			hook_scale(struct mlx_key_data keydata, t_data *mlx);
void			hook_move(struct mlx_key_data keydata, t_data *data);
void			hook(struct mlx_key_data keydata, void *data);
double			ft_julia(t_complex *c, t_complex *z0, t_data *data);
double			ft_atof(char *str);
void			fractol_julia(t_data *data, char **argv);
void			ft_arg_error(void);
void			ft_check_fractal(t_data *data, t_complex *complex, int x,
					int y);
void			fractol_mandelbrot(t_data *data, int argc);
int				ft_is_double(char *str);
void			ft_color_shift(void *param);
#endif
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
# define MAX_ITERATIONS 250
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

typedef struct s_data
{
	int			fractal;
	double		x_x;
	double		y_y;
	double		mouse_x;
	double		mouse_y;
	double		x_off;
	double		y_off;
	double		scale;
	double		scalechange;
	mlx_image_t	*img;
	mlx_t		*mlx;
}				t_data;

typedef struct s_complex
{
	double		imagine;
	double		real;
}				t_complex;

int				ft_choose_fractal(char **argv, t_data *data);
double			ft_mandelbrot(t_complex *complex);
t_data			*ft_stuct_mandelbrot(mlx_image_t *img);
void			ft_draw_fractal(t_data *data);
int				ft_fractal_color(double n);
int				get_rgba(int r, int g, int b, int a);
t_complex		*ft_create_complex(double real, double imagine);
void			ft_complex_addnum(t_complex *n1, t_complex *n2);
void			ft_complex_mul(t_complex *n1, t_complex *n2);
float			ft_complex_module(t_complex *complex);
void			ft_calc_pixel(int x, int y, t_data *data);
void			ft_mouse(double x, double y, void *vdata);
uint32_t		hsv2rgb(t_hsv hsv);
t_data			ft_fractal_init(void);
void			hook_scale(struct mlx_key_data keydata, t_data *mlx);
void			hook(struct mlx_key_data keydata, void *data);

#endif
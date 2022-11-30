#include "fractol.h"

void	hook(struct mlx_key_data keydata, void *data)
{
	t_data	*mlx;

	mlx = data;
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(mlx->mlx);
		if (keydata.key == MLX_KEY_W)
			mlx->y_off -= SPEED;
		if (keydata.key == MLX_KEY_S)
			mlx->y_off += SPEED;
		if (keydata.key == MLX_KEY_A)
			mlx->x_off -= SPEED;
		if (keydata.key == MLX_KEY_D)
			mlx->x_off += SPEED;
		hook_scale(keydata, mlx);
		ft_draw_fractal(mlx);
	}
}

void	hook_scale(struct mlx_key_data keydata, t_data *mlx)
{
	if (keydata.key == MLX_KEY_DOWN)
	{
		mlx->scalechange = mlx->scale;
		mlx->scale *= 1.25f;
		mlx->scalechange = mlx->scale - mlx->scalechange;
	}
	if (keydata.key == MLX_KEY_UP)
	{
		mlx->scalechange = mlx->scale;
		mlx->scale *= 0.75f;
		mlx->scalechange = mlx->scale - mlx->scalechange;
	}
	if (keydata.key == MLX_KEY_L)
		mlx->max_iter += 5;
	if (keydata.key == MLX_KEY_P)
		mlx->max_iter -= 5;
}

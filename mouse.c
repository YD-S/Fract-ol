#include "fractol.h"

void	ft_mouse(double x, double y, void *vdata)
{
	t_data	*data;

	data = vdata;
	data->mouse_x = x;
	data->mouse_y = y;
}

void	ft_transform_pixel(int x, int y, t_data *data)
{
	data->x_x = x + data->x_off - data->mouse_x * data->scalechange;
	data->x_x *= data->scale;
	data->x_x += data->mouse_x * data->scalechange;
	data->y_y = y + data->y_off - data->mouse_y * data->scalechange;
	data->y_y -= data->mouse_y * data->scalechange;
	data->y_y *= data->scale;
	data->y_y += data->mouse_y * data->scalechange;
}

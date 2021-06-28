#include "micro3D.h"

int		ft_valid_point(t_data *data, float y, float x)
{
	if (y < 0 || x < 0)
		return (0);
	if (y >= data->map_height * SCALE)
		return (0);
	if (x >= ft_strlen(data->map[(int)(y / SCALE)]) * SCALE)
		return (0);
	return (1);
}

void	ft_wall_collision(t_data *data, t_ray *ray, float *y, float *x)
{
	while (ft_valid_point(data, *y, *x) &&
	(data->map[(int)(*y / SCALE)][(int)(*x / SCALE)] != '1'))
	{
		*y += ray->y_step;
		*x += ray->x_step;
	}
}

float	ft_horisontal_cast(t_data *data, t_ray *ray, float ang, float *offset_x)
{
	float	pnt_x;
	float	pnt_y;

	pnt_x = (int)(data->plr->x / SCALE) * SCALE + SCALE;
	ray->x_step = SCALE;
	if ((ang > 0.5 * M_PI) && (ang < 1.5 * M_PI))
	{
		pnt_x = pnt_x - SCALE - 0.001;
		ray->x_step = -SCALE;
	}
	pnt_y = data->plr->y + (pnt_x - data->plr->x) * tan(ang);
	ray->y_step = ray->x_step * tan(ang);
	ft_wall_collision(data, ray, &pnt_y, &pnt_x);
	*offset_x = ray->x_step > 0 ?
	(data->skin->text[4]->width * ((int)pnt_y % SCALE)) / SCALE :
	(data->skin->text[3]->width * (SCALE - ((int)pnt_y % SCALE))) /
	SCALE - 0.01;
	data->ray->dir_x = ray->x_step > 0 ? 4 : 3;
	return (sqrtf(pow(pnt_x - data->plr->x, 2)
	+ pow(pnt_y - data->plr->y, 2)));
}

float	ft_vertical_cast(t_data *data, t_ray *ray, float ang, float *offset_y)
{
	float	pnt_x;
	float	pnt_y;

	pnt_y = (int)(data->plr->y / SCALE) * SCALE + SCALE;
	ray->y_step = SCALE;
	if ((ang > M_PI) && (ang < 2 * M_PI))
	{
		pnt_y = pnt_y - SCALE - 0.001;
		ray->y_step = -SCALE;
	}
	pnt_x = data->plr->x + (pnt_y - data->plr->y) / tan(ang);
	ray->x_step = ray->y_step / tan(ang);
	ft_wall_collision(data, ray, &pnt_y, &pnt_x);
	*offset_y = ray->y_step < 0 ?
	(data->skin->text[1]->width * ((int)pnt_x % SCALE)) / SCALE :
	(data->skin->text[2]->width * (SCALE - ((int)pnt_x % SCALE))) /
	SCALE - 0.01;
	data->ray->dir_y = ray->y_step > 0 ? 2 : 1;
	return (sqrtf(pow(pnt_x - data->plr->x, 2)
	+ pow(pnt_y - data->plr->y, 2)));
}

void	ft_ray_cast(t_data *data, float angle)
{
	float	dist_x;
	float	dist_y;
	float	offset_x;
	float	offset_y;

	angle += data->plr->pov;
	while (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	while (angle < 0)
		angle += 2 * M_PI;
	dist_x = ft_horisontal_cast(data, data->ray, angle, &offset_x);
	dist_y = ft_vertical_cast(data, data->ray, angle, &offset_y);
	data->ray->dir_x = dist_x < dist_y ?
						data->ray->dir_x : data->ray->dir_y;
	data->ray->dist = dist_x < dist_y ? dist_x : dist_y;
	data->ray->offset = dist_x < dist_y ? offset_x : offset_y;
}

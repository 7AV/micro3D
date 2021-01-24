/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:51:55 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/23 14:16:49 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int		ft_shadow(t_data *data, int color)
{
	int		r;
	int		g;
	int		b;
	float	dark;
	
	dark = 1 - (data->ray->dist / (SCALE * 10));
	dark = dark < 0 ? 0 : dark;
	r = (color / (256 * 256) % 256) * dark;
	g = (color / 256 % 256) * dark;
	b = (color % 256) * dark;
	return (r * 256 * 256 + g * 256 + b);
}

void	ft_text_mapping(t_data *data, t_text **text, int column, int y)
{
	int		column_height;
	float	text_step;
	int		ind;
	float	y_pos;
	int		color;
	
	ind = data->ray->dir_x;
	column_height = (SCALE * data->win->height) / data->ray->dist;
	text_step = (float)text[ind]->height / (float)column_height;
	y_pos = (y - (float)data->win->height / 2 + (float)column_height / 2)
	* text_step;
	color = *(unsigned int *)(text[ind]->addr
	+ (((int)y_pos * text[ind]->line_len) + ((int)data->ray->offset
	* (text[ind]->bpp / 8))));

	ft_my_pixel_put(data, column, y, ft_shadow(data, color));
}

void	ft_put_column(t_data *data, int column)
{
	float	ceiling;
	float	floor;
	int		y;

	y = 0;
	ceiling = data->win->height / 2 - data->win->height
	* SCALE / data->ray->dist / 2;
	floor = data->win->height - ceiling - 1;
	while (y < data->win->height)
	{
		if (y < ceiling)
			ft_my_pixel_put(data, column, y++, data->skin->ceil_color);
		else if (y > ceiling && y < floor)
			ft_text_mapping(data, data->skin->text, column, y++);
		else
			ft_my_pixel_put(data, column, y++, data->skin->flo_color);
	}
}

float		*ft_init_save(t_data *data)
{
	int	i;
	
	i = 0;
	if (data->save == NULL)
	{
		data->save = (float*)malloc(data->win->width * sizeof(float));
		data->save[0] = 0;
	}
	else
	{
		while (data->save[i])
		{
			data->save[i] = 0;
			i++;
		}
	}
	return(data->save);
}

int		ft_field_of_view_put(t_data *data)
{
	float	angle;
	int		column;
	float	column_angle;
	t_ray	ray;
	
	ft_init_save(data);
	data->ray = &ray;
	column = 0;
	column_angle = data->plr->fov / data->win->width;
	while (column < data->win->width)
	{
		angle = column * column_angle - data->plr->fov / 2;
		ft_ray_cast(data, angle);
		data->save[column] = ray.dist;
		ray.dist *= cos(angle);
		ft_put_column(data, column);
		column++;
	}
	ft_sprites(data);
	return (0);
}

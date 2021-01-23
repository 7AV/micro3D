/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:32:06 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/20 09:27:51 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_scale(t_data *data, int x, int y)
{
	int	a;
	int	b;
	
	a = (x + 1) * RAD_SCALE;
	b = (y + 1) * RAD_SCALE;
	x = x * RAD_SCALE;
	y = y * RAD_SCALE;
	while (y < b)
	{
		while (x < a)
		{
			ft_my_pixel_put(data, x, y, 0x666666);
			x++;
		}
		x = x - RAD_SCALE;
		y++;
	}
}

void	ft_scale_2(t_data *data, int x, int y)
{
	int	a;
	int	b;
	
	a = (x + 1) * RAD_SCALE;
	b = (y + 1) * RAD_SCALE;
	x = x * RAD_SCALE;
	y = y * RAD_SCALE;
	while (y < b)
	{
		while (x < a)
		{
			ft_my_pixel_put(data, x, y, 0xFFFFFF);
			x++;
		}
		x = x - RAD_SCALE;
		y++;
	}
}

void		ft_put_sprite(t_data *data)
{
	t_spr	*tmp;
	int	a, b, x, y;

	tmp = data->spr;
	while (tmp)
	{
		x = (tmp->x / SCALE - 0.5) + RAD_X*2;
		y = (tmp->y / SCALE - 0.5) + RAD_Y*2;
	
		a = (x + 1) * RAD_SCALE;
		b = (y + 1) * RAD_SCALE;
		x = x * RAD_SCALE;
		y = y * RAD_SCALE;
		while (y < b)
		{
			while (x < a)
			{
				ft_my_pixel_put(data, x, y, 0xDC143C);
				x++;
			}
			x = x - RAD_SCALE;
			y++;
		}
		tmp = tmp->next;
	}
}

int		ft_put_wall(t_data *data, char **map)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while ((map[y])[x])
		{
			if ((map[y])[x] == '1')
				ft_scale(data, x + RAD_X, y + RAD_Y);
			else
				ft_scale_2(data, x + RAD_X, y + RAD_Y);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_put_player(t_data *data)
{
	t_plr	plr = *data->plr;

	plr.x = data->plr->x / SCALE;
	plr.y = data->plr->y / SCALE;
	while (ft_valid_point(data, plr.y, plr.x) &&
	(data->map[(int)(plr.y)][(int)(plr.x)] != '1'))
	{
		plr.x += cos(plr.pov) / RAD_SCALE;
		plr.y += sin(plr.pov) / RAD_SCALE;
		ft_my_pixel_put(data, (plr.x + RAD_X) * RAD_SCALE, 
		(plr.y + RAD_Y) * RAD_SCALE, 0xB22222);
	}
}

int		ft_put_radar(t_data *data)
{
	ft_put_wall(data, data->map);
	ft_put_sprite(data);
	ft_put_player(data);
	return (0);
}

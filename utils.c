/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:38:00 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/24 09:53:14 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_norm_angle(float ang)
{
	if (ang > 2 * M_PI)
		while (ang > 2 * M_PI)
			ang -= 2 * M_PI;
	else if (ang < 0)
		while (ang < 0)
			ang += 2 * M_PI;
	return (ang);
}

void	ft_move_check(t_data *data, t_plr *plr, int flag, float offset)
{
	if (flag)
	{
		if (!(data->map[(int)plr->y / SCALE][(int)plr->x / SCALE] != '1'
		&& data->map[(int)plr->y / SCALE][(int)plr->x / SCALE] != '2'))
			plr->x += offset * MOVE_SPEED;
	}
	else if (!(data->map[(int)plr->y / SCALE][(int)plr->x / SCALE] != '1'
			&& data->map[(int)plr->y / SCALE][(int)plr->x / SCALE] != '2'))
		plr->y += offset * MOVE_SPEED;
}

void	ft_my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win->addr + (y * data->win->line_len
	+ x * (data->win->bpp / 8));
	*(unsigned int*)dst = color;
}

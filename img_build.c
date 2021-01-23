/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:38:00 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/23 09:55:51 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float		ft_norm_angle(float ang)
{
	if (ang > 2 * M_PI)
		while (ang > 2 * M_PI)
			ang -= 2 * M_PI;
	else if (ang < 0)
		while (ang < 0)
			ang += 2 * M_PI;
	return (ang);
}

void		ft_my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win->addr + (y * data->win->line_len
	+ x * (data->win->bpp / 8));
	*(unsigned int*)dst = color;
}

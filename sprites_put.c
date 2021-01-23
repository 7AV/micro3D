/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:30:07 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/23 09:57:01 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_sprdist(t_data *data)
{
	t_spr	*tmp;

	tmp = data->spr;
	while (tmp)
	{
		printf("%5.d | %d -> %d\n", tmp->x, tmp->y, tmp->dist);
		tmp = tmp->next;
	}
}

void	ft_swap_sprites(t_data *data, t_spr *a, t_spr *b)
{
	t_spr	*tmp;

	tmp = ft_sprnew(0, 0);
	tmp->x = a->x;
	tmp->y = a->y;
	tmp->dist = a->dist;
	tmp->dir = a->dir;
	
	a->x = b->x;
	a->y = b->y;
	a->dist = b->dist;
	a->dir = b->dir;
	
	b->x = tmp->x;
	b->y = tmp->y;
	b->dist = tmp->dist;
	b->dir = tmp->dir;
	free(tmp);
}

void	ft_sort_sprites(t_data *data)
{
	t_spr	*tmp;
	int		swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		tmp = data->spr;
		while (tmp->next)
		{
			if (tmp->dist < tmp->next->dist)
			{
				ft_swap_sprites(data, tmp, tmp->next);
				swap = 1;

			}
			else
				tmp = tmp->next;
		}
	}
}

void	ft_draw_sprites(t_data *data, t_point *point, float coef, t_spr *spr)
{
	char	*col;
	int		x;
	int		y;

	y = -1;
	while (++y < spr->height)
	{
		x = 0;
		while (++x < spr->height)
		{
			if (point->x + y < data->win->width && point->x + y >= 0
			&& point->y + x >= 0 && point->y + x < data->win->height
			&& data->save[point->x + y] > spr->dist)
			{
				col = data->skin->text[0]->addr + (((int)(x * coef) * data->skin->text[0]
				->line_len) + ((int)(y * coef) * (data->skin->text[0]->bpp / 8)));
				if ((*(unsigned int *)col & 0xFFFFFF) != 0 && point->y + x >
			0 && point->x + y > 0 && point->x + y < data->win->width
				&& point->y + x < data->win->height)
					ft_my_pixel_put(data, point->x + y, point->y + x,
						*(unsigned int *)col);
			}
			
		}
	}
}

void	ft_calc_sprites_2(t_data *data, t_spr *spr)
{
	int		proj_plane;
	float	coef;
	t_point	point;

	spr->dir = spr->dir - ft_norm_angle(data->plr->pov);
	if ((spr->dir > -PLAYER_FOV_2) && (spr->dir < PLAYER_FOV_2))
	{
		proj_plane = data->win->width / (2 * tan(PLAYER_FOV_2));
		spr->height = fabs((SCALE * proj_plane) / (spr->dist * cos(spr->dir))) / 1.2;
		coef = (float)(SCALE) / spr->height;
		point.x = spr->dir * (data->win->width / 2) / (PLAYER_FOV_2) + data->win->width / 2 - spr->height / 2;
		point.y = data->win->height / 2 - spr->height / 3;
		ft_draw_sprites(data, &point, coef, spr);
	}
}

void	ft_calc_sprites(t_data *data)
{
	t_spr	*tmp;

	tmp = data->spr;
	while (tmp)
	{
		tmp->dist = sqrtf((tmp->x - data->plr->x) * (tmp->x - data->plr->x)
		+ (tmp->y - data->plr->y) * (tmp->y - data->plr->y));
		tmp->dir = atan2(tmp->y - data->plr->y, tmp->x - data->plr->x);
		tmp->dir = ft_norm_angle(tmp->dir);
		tmp = tmp->next;
	}
	ft_sort_sprites(data);
	tmp = data->spr;
	while (tmp != NULL)
	{
		ft_calc_sprites_2(data, tmp);
		tmp = tmp->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:30:07 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/25 20:22:34 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap_sprites(t_spr *a, t_spr *b)
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
				ft_swap_sprites(tmp, tmp->next);
				swap = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}

void	ft_put_sprite(t_data *data, t_spr *spr, t_point *pnt, float scale)
{
	char	*color;
	int		x;
	int		y;

	y = -1;
	while (++y < spr->height)
	{
		x = -1;
		while (++x < spr->height)
		{
			if (pnt->x + y < data->win->width && pnt->x + y >= 0
			&& pnt->y + x >= 0 && pnt->y + x < data->win->height
			&& data->save[(int)pnt->x + y] > spr->dist)
			{
				color = (data->skin->text[0]->addr
				+ (((int)(x * scale) * data->skin->text[0] ->line_len)
				+ ((int)(y * scale) * (data->skin->text[0]->bpp / 8))));
				if (pnt->x + y < data->win->width && pnt->y + x
					< data->win->height && pnt->y + x > 0 && pnt->x + y > 0
					&& (*(unsigned int *)color & 0xFFFFFF) != 0)
					ft_my_pixel_put(data, pnt->x + y, pnt->y + x,
					*(unsigned int *)color);
			}
		}
	}
}

void	ft_sprite_options(t_data *data, t_spr *spr)
{
	t_point		pnt;
	int			depth;
	float		scale;

	spr->dir = spr->dir - ft_norm_angle(data->plr->pov);
	if ((spr->dir > -PLAYER_FOV_2) && (spr->dir < PLAYER_FOV_2))
	{
		depth = data->win->width / (2 * tan(PLAYER_FOV_2));
		spr->height = (SCALE * depth) / (spr->dist * cos(spr->dir));
		scale = (float)SCALE / spr->height;
		pnt.x = spr->dir * (data->win->width / 2) / (PLAYER_FOV_2)
		+ data->win->width / 2 - spr->height / 2;
		pnt.y = data->win->height / 2 - spr->height / 2;
		ft_put_sprite(data, spr, &pnt, scale);
	}
}

void	ft_sprites(t_data *data)
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
		ft_sprite_options(data, tmp);
		tmp = tmp->next;
	}
}

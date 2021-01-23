/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:30:04 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/23 14:17:08 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_spr	*ft_sprnew(float x, float y)
{
	t_spr	*spr;

	spr = (t_spr*)malloc(sizeof(t_spr));
	spr->x = (x + 0.5) * SCALE;
	spr->y = (y + 0.5) * SCALE;
	spr->dir = 0;
	spr->dist = 0;
	spr->height = 0;
	spr->next = NULL;
	return (spr);
}

void	ft_spradd_back(t_spr **spr, t_spr *new)
{
	t_spr	*head;

	head = *spr;
	if (head == NULL)
		*spr = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}

void	ft_set_sprite(t_data *data, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->spr = NULL;
	while (map[y])
	{
		x = 0;
		while ((map[y])[x])
		{
			if ((map[y])[x] == '2')
			{
				ft_spradd_back(&data->spr, ft_sprnew(x, y));
			}
			x++;
		}
		y++;
	}
}

void	ft_set_player(char **map, t_data *data, t_plr *plr)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->plr = plr;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				data->plr->x = (x + 0.5) * SCALE;
				data->plr->y = (y + 0.5) * SCALE;
				data->plr->fov = PLAYER_FOV_2 * 2;
				map[y][x] == 'N' ? data->plr->pov = -M_PI / 2 : 0;
				map[y][x] == 'S' ? data->plr->pov = M_PI / 2 : 0;
				map[y][x] == 'W' ? data->plr->pov = M_PI : 0;
			}
			x++;
		}
		y++;
	}
}

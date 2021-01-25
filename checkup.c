/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:00:12 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/25 20:26:33 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_path_check(t_skin *skin)
{
	int		ind;
	int		fd;
	int		x;

	ind = -1;
	while (++ind < 5)
		(fd = open(skin->path[ind], O_RDONLY)) < 0 ?
		ft_error(ER_FD) : close(fd);
	x = -1;
	ind = -1;
	while (x++ < 5)
	{
		while (ind++ < 5)
			if (ft_strncmp(skin->path[x], skin->path[ind],
			ft_strlen(skin->path[x])) == 0 && (ind != x))
				ft_error(ER_DUP_TEXT);
		ind = -1;
	}
}

int		ft_check_tool(int x, int y, t_data *data)
{
	if (((data->map[y][x + 1]) == ' ') || (data->map[y][x + 1] == '\0') ||
	((data->map[y + 1][x + 1]) == ' ') || (data->map[y + 1][x + 1] == '\0') ||
	((data->map[y + 1][x]) == ' ') || (data->map[y + 1][x] == '\0') ||
	((data->map[y + 1][x - 1]) == ' ') || (data->map[y + 1][x - 1] == '\0') ||
	((data->map[y][x - 1]) == ' ') || (data->map[y][x - 1] == '\0') ||
	((data->map[y - 1][x - 1]) == ' ') || (data->map[y - 1][x - 1] == '\0') ||
	((data->map[y - 1][x]) == ' ') || (data->map[y - 1][x] == '\0') ||
	((data->map[y - 1][x + 1]) == ' ') || (data->map[y - 1][x + 1] == '\0'))
		return (1);
	return (0);
}

void	ft_map_check(t_data *data)
{
	int		x;
	int		y;
	int		plr;

	x = 0;
	y = 0;
	plr = 0;
	while (y < data->map_height)
	{
		data->map_width = ft_strlen(data->map[y]);
		while (x < data->map_width)
		{
			if (data->map[y][x] == '0')
				ft_check_tool(x, y, data) ? ft_error(ER_MAP) : 0;
			!ft_strchr("012NSWE ", data->map[y][x]) ? ft_error(ER_MAP) : 0;
			ft_strchr("NSWE", data->map[y][x]) ? plr += 1 : 0;
			x++;
		}
		x = 0;
		y++;
	}
	plr != 1 ? ft_error(ER_PLR) : 0;
}

void	ft_opt_check(t_data *data)
{
	((data->skin->ceil_color == -1) || (data->skin->flo_color == -1)
	|| data->win->width == -1 || data->win->height == -1
	|| !data->skin->path[1] || !data->skin->path[2]
	|| !data->skin->path[3] || !data->skin->path[4]
	|| !data->skin->path[0]) ? ft_error(ER_BAD_OPT) : 0;
}

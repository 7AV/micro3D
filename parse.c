/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:55:47 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/25 20:28:36 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_options(char **opt, t_data *data)
{
	if (ft_strncmp(opt[0], "F", 2) == 0)
	{
		(data->skin->flo_color != -1) ? ft_error(ER_BAD_OPT) : 0;
		ft_color_calc(opt, data);
	}
	else if (ft_strncmp(opt[0], "C", 2) == 0)
	{
		(data->skin->ceil_color != -1) ? ft_error(ER_BAD_OPT) : 0;
		ft_color_calc(opt, data);
	}
}

void	ft_texture_options(char **opt, t_skin *skin)
{
	if (ft_strncmp(opt[0], "S", 2) == 0)
	{
		(skin->path[0] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		skin->path[0] = ft_strdup(opt[1]);
	}
	else if (ft_strncmp(opt[0], "NO", 2) == 0)
	{
		(skin->path[1] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		skin->path[1] = ft_strdup(opt[1]);
	}
	else if (ft_strncmp(opt[0], "SO", 2) == 0)
	{
		(skin->path[2] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		skin->path[2] = ft_strdup(opt[1]);
	}
	else if (ft_strncmp(opt[0], "WE", 2) == 0)
	{
		(skin->path[3] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		skin->path[3] = ft_strdup(opt[1]);
	}
	else if (ft_strncmp(opt[0], "EA", 2) == 0)
	{
		(skin->path[4] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		skin->path[4] = ft_strdup(opt[1]);
	}
}

void	ft_window_options(char **opt, t_win *win)
{
	if (ft_strncmp(opt[0], "R", 1) == 0)
	{
		(win->height != -1) && (win->width != -1) ? ft_error(ER_BAD_OPT) : 0;
		win->width = (ft_atoi(opt[1]) > 2560) ? 2560 : ft_atoi(opt[1]);
		win->height = (ft_atoi(opt[2]) > 1440) ? 1440 : ft_atoi(opt[2]);
		(win->height <= 200) && (win->width <= 200) ? ft_error(ER_BAD_RES) : 0;
	}
	else
		ft_error(ER_BAD_OPT);
}

void	ft_input_parse(t_data *data)
{
	char	**tmp;
	int		ind;
	int		count;
	int		flag;

	ind = -1;
	count = 0;
	flag = 0;
	while (data->input[++ind])
	{
		while (data->input[ind][count] == ' ')
			count++;
		if (!flag && (data->input[ind][count] == '1'))
		{
			data->map = &data->input[ind];
			flag = 1;
			break ;
		}
		count = 0;
		tmp = ft_split(data->input[ind], ' ');
		while (tmp[count])
			count++;
		if (count == 3)
			ft_window_options(tmp, data->win);
		else if (count == 2)
		{
			ft_texture_options(tmp, data->skin);
			ft_color_options(tmp, data);
		}
		else if (count == 1 && tmp[0][0])
			ft_error(ER_MAP);
	}
	if (!flag)
		ft_error(ER_MAP);
	ind = 0;
	while (data->map[ind])
		ind++;
	data->map_height = ind;
	ft_opt_check(data);
	ft_map_check(data);
	ft_path_check(data->skin);
}

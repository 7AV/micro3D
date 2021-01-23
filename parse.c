/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:55:47 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/23 14:17:04 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_colour_options(char **opt, t_data *data)
{
	char	**tmp;

	tmp = ft_split(opt[1], ',');
	if (tmp[0] && tmp[1] && tmp[2]
	&& ft_atoi(tmp[0]) >= 0 && ft_atoi(tmp[0]) <= 255
	&& ft_atoi(tmp[1]) >= 0 && ft_atoi(tmp[1]) <= 255
	&& ft_atoi(tmp[2]) >= 0 && ft_atoi(tmp[2]) <= 255)
	{
		if (*opt[0] == 'F')
			data->skin->flo_color = (ft_atoi(tmp[0]) * 256 * 256) +
			(ft_atoi(tmp[1]) * 256) + ft_atoi(tmp[2]);
		if (*opt[0] == 'C')
			data->skin->ceil_color = (ft_atoi(tmp[0]) * 256 * 256) +
			(ft_atoi(tmp[1]) * 256) + ft_atoi(tmp[2]);
	}
}

void	ft_texture_options(char **opt, t_data *data, t_skin *skin)
{
	if (ft_strncmp(opt[0], "S", 2) == 0)
		skin->text_path[0] = ft_strdup(opt[1]);
	else if (ft_strncmp(opt[0], "NO", 2) == 0)
		skin->text_path[1] = ft_strdup(opt[1]);
	else if (ft_strncmp(opt[0], "SO", 2) == 0)
		skin->text_path[2] = ft_strdup(opt[1]);
	else if (ft_strncmp(opt[0], "WE", 2) == 0)
		skin->text_path[3] = ft_strdup(opt[1]);
	else if (ft_strncmp(opt[0], "EA", 2) == 0)
		skin->text_path[4] = ft_strdup(opt[1]);
	ft_colour_options(opt, data);
}

void	ft_window_options(char **opt, t_win *win)
{
	if (ft_strncmp(opt[0], "R", 1) == 0)
	{
		win->width = (ft_atoi(opt[1]) > 2560) ?
		2560 : ft_atoi(opt[1]);
		win->height = (ft_atoi(opt[2]) > 1440) ?
		1440 : ft_atoi(opt[2]);
	}
}

void	ft_input_parse(t_data *data)
{
	char	**tmp;
	int		ind;
	int		count;
	int		flag;

	ind = 0;
	count = 0;
	flag = 0;
	data->map_height = 0;
	while (data->input[ind])
	{
		tmp = ft_split(data->input[ind], ' ');
		while (tmp[count])
			count++;
		if (count == 3)
			ft_window_options(tmp, data->win);
		else if (count == 2)
			ft_texture_options(tmp, data, data->skin);
		else if (count == 1 && (tmp[0][0] == '1' || tmp[0][0] == ' '))
		{
			if (!flag)
			{
				data->map = &data->input[ind];
				flag = 1;
			}
			data->map_height += 1;
		}
		count = 0;
		ind++;
	}
}

void	ft_input_build(t_list **input_head, t_data *data)
{
	int		list_count;
	int		ind;
	t_list	*tmp;

	ind = 0;
	list_count = ft_lstsize(*input_head);
	data->input = ft_calloc(list_count + 1, sizeof(char *));
	tmp = *input_head;
	while (tmp)
	{
		data->input[ind] = tmp->content;
		tmp = tmp->next;
		ind++;
	}
}

void	ft_read_input(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	t_list	*input_head;

	fd = open(argv, O_RDONLY);
	line = NULL;
	input_head = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&input_head, ft_lstnew(line));
	}
	ft_lstadd_back(&input_head, ft_lstnew(line));
	close(fd);
	ft_input_build(&input_head, data);
	ft_input_parse(data);
}

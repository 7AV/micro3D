#include "micro3D.h"

void	ft_texture_options(char **opt, t_skin *skin)
{
	if (ft_strncmp(opt[0], "S", 2) == 0)
	{
		(skin->path[0] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		(skin->path[0] = ft_strdup(opt[1])) ? 0 : ft_error(ER_MALLOC);
	}
	else if (ft_strncmp(opt[0], "NO", 2) == 0)
	{
		(skin->path[1] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		(skin->path[1] = ft_strdup(opt[1])) ? 0 : ft_error(ER_MALLOC);
	}
	else if (ft_strncmp(opt[0], "SO", 2) == 0)
	{
		(skin->path[2] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		(skin->path[2] = ft_strdup(opt[1])) ? 0 : ft_error(ER_MALLOC);
	}
	else if (ft_strncmp(opt[0], "WE", 2) == 0)
	{
		(skin->path[3] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		(skin->path[3] = ft_strdup(opt[1])) ? 0 : ft_error(ER_MALLOC);
	}
	else if (ft_strncmp(opt[0], "EA", 2) == 0)
	{
		(skin->path[4] != NULL) ? ft_error(ER_BAD_OPT) : 0;
		(skin->path[4] = ft_strdup(opt[1])) ? 0 : ft_error(ER_MALLOC);
	}
}

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
	else
		ft_texture_options(opt, data->skin);
	ft_free(opt);
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
	ft_free(opt);
}

int		ft_find_map(t_data *data, int ind, int *flag)
{
	int		count;

	count = 0;
	while (data->input[ind][count] == ' ')
		count++;
	if (!(*flag) && (data->input[ind][count] == '1'))
	{
		data->map = &data->input[ind];
		*flag = 1;
	}
	return (*flag ? 1 : 0);
}

void	ft_input_parse(t_data *data)
{
	char	**tmp;
	int		ind;
	int		flag;

	ind = 0;
	flag = 0;
	while (data->input[ind])
	{
		if (ft_find_map(data, ind, &flag))
			break ;
		tmp = ft_split(data->input[ind], ' ');
		if (tmp[0] && tmp[1] && tmp[2])
			ft_window_options(tmp, data->win);
		else if (tmp[0] && tmp[1] && !tmp[2])
			ft_color_options(tmp, data);
		else if (tmp[0] && tmp[0][0])
			ft_error(ER_MAP);
		else if (!tmp[0])
			free(tmp);
		ind++;
	}
	if (!flag)
		ft_error(ER_MAP);
	ft_checkup(data);
}

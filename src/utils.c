#include "among3D.h"

int		ft_shadow(float dist, int color)
{
	int		r;
	int		g;
	int		b;
	float	dark;

	dark = 1 - (dist / (SCALE * 10));
	dark = dark < 0 ? 0 : dark;
	r = (color / (256 * 256) % 256) * dark;
	g = (color / 256 % 256) * dark;
	b = (color % 256) * dark;
	return (r * 256 * 256 + g * 256 + b);
}

void	ft_color_calc(char **opt, t_data *data)
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
	else
		ft_error(ER_COLOR);
	ft_free(tmp);
}

float	ft_norm_angle(float ang)
{
	while (ang > 2 * M_PI)
		ang -= 2 * M_PI;
	while (ang < 0)
		ang += 2 * M_PI;
	return (ang);
}

void	ft_my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->win->addr + (y * data->win->line_len
	+ x * (data->win->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_map_height(t_data *data)
{
	int		ind;

	ind = 0;
	while (data->map[ind])
		ind++;
	data->map_height = ind;
}

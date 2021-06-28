#include "micro3D.h"

void	ft_set_textures(t_data *data, t_text **text)
{
	int		ind;

	ind = 0;
	while (ind < 5)
	{
		text[ind]->img = mlx_xpm_file_to_image(data->win->mlx,
		data->skin->path[ind], &text[ind]->width,
		&text[ind]->height);
		text[ind]->addr = mlx_get_data_addr(text[ind]->img,
		&text[ind]->bpp, &text[ind]->line_len, &text[ind]->end);
		ind++;
	}
}

int		ft_render_next_frame(t_data *data)
{
	ft_field_of_view_put(data);
	RADAR ? ft_put_radar(data) : 0;
	(data->scrn) ? ft_screenshot(data) : 0;
	mlx_put_image_to_window(data->win->mlx, data->win->win,
		data->win->img, 0, 0);
	mlx_do_sync(data->win->mlx);
	return (0);
}

void	ft_init_str(t_data *data, t_win *win, t_skin *skin, t_text *text)
{
	int		ind;

	win->width = -1;
	win->height = -1;
	ind = 0;
	while (ind < 5)
	{
		skin->path[ind] = NULL;
		ind++;
	}
	ind = 0;
	while (ind < 5)
	{
		skin->text[ind] = &text[ind];
		ind++;
	}
	skin->ceil_color = -1;
	skin->flo_color = -1;
	data->win = win;
	data->skin = skin;
	data->map_height = 0;
}

void	ft_init_win(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "micro3D");
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img, &win->bpp,
	&win->line_len, &win->end);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_win		win;
	t_skin		skin;
	t_plr		plr;
	t_text		text[4];

	data.save = NULL;
	data.plr = &plr;
	data.scrn = (argc == 3 && !ft_strncmp(argv[2], "--save", 6)) ? 1 : 0;
	argc < 2 || argc > 3 || (argc == 3 && !data.scrn) ? ft_error(ER_ARG) : 0;
	ft_init_str(&data, &win, &skin, &text[0]);
	ft_read_input(argv[1], &data);
	ft_init_win(&win);
	ft_set_player(data.map, &data, &plr);
	ft_set_sprite(&data, data.map);
	ft_set_textures(&data, data.skin->text);
	mlx_loop_hook(win.mlx, ft_render_next_frame, &data);
	mlx_hook(win.win, 2, (1L << 0), &ft_button_press, &data);
	mlx_hook(win.win, 17, 0L, &ft_close, &data);
	mlx_loop(win.mlx);
	ft_free_data(&data);
	return (0);
}

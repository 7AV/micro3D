#include "among3D.h"

static int	ft_get_color(t_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->win->addr + (y * data->win->line_len
	+ x * (data->win->bpp / 8));
	color = *(int*)dst;
	return (color);
}

static void	ft_itoc(int i, unsigned char *arr)
{
	arr[0] = (unsigned char)(i);
	arr[1] = (unsigned char)(i >> 8);
	arr[2] = (unsigned char)(i >> 16);
	arr[3] = (unsigned char)(i >> 24);
}

static void	ft_put_color(t_data *data, int fd)
{
	int		x;
	int		y;
	int		color;

	y = data->win->height - 1;
	while (0 <= y)
	{
		x = 0;
		while (x < data->win->width)
		{
			color = ft_get_color(data, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
	}
}

void		ft_screenshot(t_data *data)
{
	int				fd;
	int				filesize;
	unsigned char	arr[54];
	int				count;

	filesize = ((data->win->height * data->win->width)
			* 4) + 54;
	((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC |
		O_APPEND, 0666)) < 0) ? ft_error(ER_SCRNSHT) : 0;
	count = 0;
	while (count < 54)
		arr[count++] = 0;
	arr[0] = 'B';
	arr[1] = 'M';
	ft_itoc(filesize, &arr[2]);
	arr[10] = (unsigned char)(54);
	arr[14] = (unsigned char)(40);
	ft_itoc(data->win->width, &arr[18]);
	ft_itoc(data->win->height, &arr[22]);
	arr[26] = (unsigned char)(1);
	arr[28] = (unsigned char)(24);
	write(fd, arr, 54);
	ft_put_color(data, fd);
	close(fd);
	exit(0);
}

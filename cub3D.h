/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:53:23 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/24 16:40:19 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# define SCALE 500
# define RADAR 1
# define RAD_SCALE 10
# define RAD_X 1
# define RAD_Y 1
# define PLAYER_FOV_2 M_PI / 2.7 / 2
# define MOVE_SPEED 100

# define ER_ARG			0	//неверный аргумент при запуске main
# define ER_FD			1	//открытие файла
# define ER_MALLOC		2	//маллок
# define ER_BAD_OPT		3	//неверные ключи в инпуте
# define ER_BAD_RES		4	//совпадение разрешений
# define ER_PATH		5	//путь к текстурам
# define ER_BAD_TEXT	6	//текстуры не открываются
# define ER_DUP_TEXT	7	//повтор текстур
# define ER_COLOR		8	//дурной тонr
# define ER_MAP			9	//невалидная карта
# define ER_PLR			10	//ошибки игрока
# define ER_SCRNSHT		11	//ошибка скриншота

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_spr
{
	int				x;
	int				y;
	int				dist;
	float			dir;
	int				height;
	struct s_spr	*next;
}					t_spr;

typedef struct		s_text
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				line_len;
	int				bpp;
	int				end;

}					t_text;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*img;
	char			*addr;
	int				line_len;
	int				bpp;
	int				end;
}					t_win;

typedef struct		s_plr
{
	float			x;
	float			y;
	float			pov;
	float			fov;
}					t_plr;

typedef struct		s_skin
{
	int				ceil_color;
	int				flo_color;
	char			*path[5];
	t_text			*text[5];

}					t_skin;

typedef struct		s_ray
{
	float			x_step;
	float			y_step;
	float			dist;
	int				dir_x;
	int				dir_y;
	float			offset;
}					t_ray;

typedef struct		s_data
{
	char			**input;
	char			**map;
	int				map_height;
	int				map_width;
	int				scrn;
	t_spr			*spr;
	t_skin			*skin;
	t_win			*win;
	t_plr			*plr;
	t_ray			*ray;
	float			*save;
}					t_data;

void				ft_error(char code);
void				ft_floor(t_data *data);
float				ft_norm_angle(float ang);
t_spr				*ft_sprnew(float x, float y);
void				ft_sprites(t_data *data);
void				ft_spr_put(t_data *data);
void				ft_set_sprite(t_data *data, char **map);
int					ft_valid_point(t_data *data, float y, float x);
void				ft_ray_cast(t_data *data, float angle);
void				ft_init_img(t_data *data);
void				ft_my_pixel_put(t_data *data, int x, int y, int color);
void				ft_put_player(t_data *data);
int					ft_field_of_view_put(t_data *data);
int					ft_screen_put(t_data *data);
int					ft_button_press(int button, t_data *data);
int					ft_put_radar(t_data *data);
void				ft_set_player(char **map, t_data *data, t_plr *plr);
void				ft_map_set(char *argv, t_data *data);
void				ft_read_input(char *argv, t_data *data);
void				ft_move_check(t_data *data, t_plr *plr, int flag,
float offset);

#endif

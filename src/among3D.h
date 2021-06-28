#ifndef AMONG3D_H
# define AMONG3D_H

# include <stdio.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# define SCALE 500
# define RADAR 0
# define RAD_SCALE 5
# define RAD_X 1
# define RAD_Y 1
# define PLAYER_FOV_2 M_PI / 5.4
# define MOVE_SPEED 100

# define ER_ARG			0
# define ER_FD			1
# define ER_MALLOC		2
# define ER_BAD_OPT		3
# define ER_BAD_RES		4
# define ER_PATH		5
# define ER_BAD_TEXT	6
# define ER_DUP_TEXT	7
# define ER_COLOR		8
# define ER_MAP			9
# define ER_PLR			10
# define ER_SCRNSHT		11

typedef struct		s_point
{
	int			x;
	int			y;
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

void				ft_map_height(t_data *data);
void				ft_free_data(t_data *data);
void				ft_free(char **trash);
int					ft_close(t_data *data);
void				ft_input_parse(t_data *data);
void				ft_input_build(t_list **input_head, t_data *data);
void				ft_color_calc(char **opt, t_data *data);
int					ft_shadow(float dist, int color);
void				ft_path_check(t_skin *skin);
int					ft_check_tool(int x, int y, t_data *data);
void				ft_map_check(t_data *data);
void				ft_checkup(t_data *data);
void				ft_screenshot(t_data *data);
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

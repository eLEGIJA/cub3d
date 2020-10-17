/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:49:05 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:24:48 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "keys.h"
# include "../libft/inc/libft.h"
# include <math.h>
# include <stdlib.h>

# define F 0.01
# define MOVEMENT 0.06
# define ROTATE 0.04

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_tex {
	void			*img;
	int				*addr;
	int				width;
	int				height;
	int				bpp;
	int				l_len;
	int				enan;
	int				x;
	int				y;
}					t_tex;

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bpp;
	int				l_len;
	int				enan;
}					t_data;

typedef struct		s_conf
{
	void			*mlx;
	int				height;
	int				width;
	int				map_size;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprt;
	int				floor_cl;
	int				ceil_cl;
	char			**map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plx;
	double			ply;
	int				num_sprs;
	int				spawns;
	char			error;
	char			ymp;
	t_sprite		*sprite;
	t_data			data;
	t_tex			tex[5];
}					t_conf;

typedef struct		s_game {
	void			*win;
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	t_conf			conf;
}					t_game;

typedef struct		s_sc {
	double			x;
	double			y;
	double			inv_det;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}					t_sc;

typedef struct		s_rc{
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			s_dist_x;
	double			s_dist_y;
	double			d_dist_x;
	double			d_dist_y;
	double			perp_wal_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_hgt;
	int				drw_strt;
	int				drw_end;
	double			wl_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				x;
	int				y;
}					t_rc;

int					get_next_line(int fd, char **line);
void				parsing(char *file, t_conf *conf);
void				rc_tex_x(t_rc *rc, t_conf *conf, t_tex *tex);
void				rc_tex_step(t_rc *rc, t_tex *tex);
void				rc_paint_walls(t_rc *rc, t_conf *conf, t_tex tex);
void				rc_walls(t_rc *rc, t_conf *conf, t_tex *tx);
void				tex_init(t_tex *tex, t_conf *conf);
void				sprite_cast(t_conf *conf, double *z_buff, t_tex tex);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_sort(int *sprite_queue, double *sprite_dest, int amount);
void				free_split(char **output);
void				ft_error(t_conf *conf, t_list *lst,
						char *line, char **spl_line);
char				*check_strdup(const char *s, t_conf *conf);
int					ft_color(char **col_line, t_conf *conf, int *color);
void				list_add(t_conf *conf, t_list *lst, char *line);
void				frame_res(char **spl_line, t_conf *conf);
void				check_pos(t_conf *conf, int i, int j);
void				map(t_list *lst, t_conf *conf,
						char *line, char **spl_line);
void				check_tag(t_conf *conf, char *s, char *tag);
void				raycasting(t_conf *conf);
void				check_state(t_game *game);
int					ft_close(t_conf *conf);
void				ft_bitmap(t_conf *cfg);
int					key_unpress(int key, t_game *game);
int					key_press(int key, t_game *game);
void				nval(t_conf *conf, int error);
void				code_error(t_conf *conf);

#endif

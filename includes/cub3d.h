/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:49:05 by msafflow          #+#    #+#             */
/*   Updated: 2021/02/21 11:09:14 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define ROTATE 0.04
# define F 0.01
# define MOVEMENT 0.06

/*
** keycodes for keys that are independent of keyboard layout
*/

enum {
	kVK_Return = 0x24,
	kVK_Tab = 0x30,
	kVK_Space = 0x31,
	kVK_Delete = 0x33,
	kVK_Escape = 0x35,
	kVK_Command = 0x37,
	kVK_Shift = 0x38,
	kVK_CapsLock = 0x39,
	kVK_Option = 0x3A,
	kVK_Control = 0x3B,
	kVK_RightShift = 0x3C,
	kVK_RightOption = 0x3D,
	kVK_RightControl = 0x3E,
	kVK_Function = 0x3F,
	kVK_F17 = 0x40,
	kVK_VolumeUp = 0x48,
	kVK_VolumeDown = 0x49,
	kVK_Mute = 0x4A,
	kVK_F18 = 0x4F,
	kVK_F19 = 0x50,
	kVK_F20 = 0x5A,
	kVK_F5 = 0x60,
	kVK_F6 = 0x61,
	kVK_F7 = 0x62,
	kVK_F3 = 0x63,
	kVK_F8 = 0x64,
	kVK_F9 = 0x65,
	kVK_F11 = 0x67,
	kVK_F13 = 0x69,
	kVK_F16 = 0x6A,
	kVK_F14 = 0x6B,
	kVK_F10 = 0x6D,
	kVK_F12 = 0x6F,
	kVK_F15 = 0x71,
	kVK_Help = 0x72,
	kVK_Home = 0x73,
	kVK_PageUp = 0x74,
	kVK_ForwardDelete = 0x75,
	kVK_F4 = 0x76,
	kVK_End = 0x77,
	kVK_F2 = 0x78,
	kVK_PageDown = 0x79,
	kVK_F1 = 0x7A,
	kVK_LeftArrow = 0x7B,
	kVK_RightArrow = 0x7C,
	kVK_DownArrow = 0x7D,
	kVK_UpArrow = 0x7E
};

/*
**  Summary:
**    Virtual keycodes
**
**	 Discussion:
**    These constants are the virtual keycodes defined originally in
**    Inside Mac Volume V, pg. V-191. They identify physical keys on a
**    keyboard. Those constants with "ANSI" in the name are labeled
**    according to the key position on an ANSI-standard US keyboard.
**    For example, kVK_ANSI_A indicates the virtual keycode for the key
**    with the letter 'A' in the US keyboard layout. Other keyboard
**    layouts may have the 'A' key label on a different physical key;
**    in this case, pressing 'A' will generate a different virtual
**    keycode.
*/

enum
{
	kVK_ANSI_A = 0x00,
	kVK_ANSI_S = 0x01,
	kVK_ANSI_D = 0x02,
	kVK_ANSI_F = 0x03,
	kVK_ANSI_H = 0x04,
	kVK_ANSI_G = 0x05,
	kVK_ANSI_Z = 0x06,
	kVK_ANSI_X = 0x07,
	kVK_ANSI_C = 0x08,
	kVK_ANSI_V = 0x09,
	kVK_ANSI_B = 0x0B,
	kVK_ANSI_Q = 0x0C,
	kVK_ANSI_W = 0x0D,
	kVK_ANSI_E = 0x0E,
	kVK_ANSI_R = 0x0F,
	kVK_ANSI_Y = 0x10,
	kVK_ANSI_T = 0x11,
	kVK_ANSI_1 = 0x12,
	kVK_ANSI_2 = 0x13,
	kVK_ANSI_3 = 0x14,
	kVK_ANSI_4 = 0x15,
	kVK_ANSI_6 = 0x16,
	kVK_ANSI_5 = 0x17,
	kVK_ANSI_Equal = 0x18,
	kVK_ANSI_9 = 0x19,
	kVK_ANSI_7 = 0x1A,
	kVK_ANSI_Minus = 0x1B,
	kVK_ANSI_8 = 0x1C,
	kVK_ANSI_0 = 0x1D,
	kVK_ANSI_RightBracket = 0x1E,
	kVK_ANSI_O = 0x1F,
	kVK_ANSI_U = 0x20,
	kVK_ANSI_LeftBracket = 0x21,
	kVK_ANSI_I = 0x22,
	kVK_ANSI_P = 0x23,
	kVK_ANSI_L = 0x25,
	kVK_ANSI_J = 0x26,
	kVK_ANSI_Quote = 0x27,
	kVK_ANSI_K = 0x28,
	kVK_ANSI_Semicolon = 0x29,
	kVK_ANSI_Backslash = 0x2A,
	kVK_ANSI_Comma = 0x2B,
	kVK_ANSI_Slash = 0x2C,
	kVK_ANSI_N = 0x2D,
	kVK_ANSI_M = 0x2E,
	kVK_ANSI_Period = 0x2F,
	kVK_ANSI_Grave = 0x32,
	kVK_ANSI_KeypadDecimal = 0x41,
	kVK_ANSI_KeypadMultiply = 0x43,
	kVK_ANSI_KeypadPlus = 0x45,
	kVK_ANSI_KeypadClear = 0x47,
	kVK_ANSI_KeypadDivide = 0x4B,
	kVK_ANSI_KeypadEnter = 0x4C,
	kVK_ANSI_KeypadMinus = 0x4E,
	kVK_ANSI_KeypadEquals = 0x51,
	kVK_ANSI_Keypad0 = 0x52,
	kVK_ANSI_Keypad1 = 0x53,
	kVK_ANSI_Keypad2 = 0x54,
	kVK_ANSI_Keypad3 = 0x55,
	kVK_ANSI_Keypad4 = 0x56,
	kVK_ANSI_Keypad5 = 0x57,
	kVK_ANSI_Keypad6 = 0x58,
	kVK_ANSI_Keypad7 = 0x59,
	kVK_ANSI_Keypad8 = 0x5B,
	kVK_ANSI_Keypad9 = 0x5C
};

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_tex {
	void			*img;
	int				*addr;
	int				width;
	int				l_len;
	int				enan;
	int				height;
	int				bpp;
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
	double			dir_y;
	double			plx;
	double			ply;
	int				height;
	int				width;
	int				map_size;
	char			*we;
	char			*ea;
	t_sprite		*sprite;
	t_data			data;
	t_tex			tex[5];
	char			*sprt;
	int				floor_cl;
	int				ceil_cl;
	char			**map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	char			*no;
	char			*so;
	int				num_sprs;
	int				spawns;
	char			error;
	char			ymp;
}					t_conf;

typedef struct		s_game {
	void			*win;
	int				left;
	int				right;
	t_conf			conf;
	int				w;
	int				a;
	int				s;
	int				d;
}					t_game;

typedef struct		s_sc {
	double			x;
	double			y;
	int				screen_x;
	int				height;
	int				width;
	double			trans_x;
	double			trans_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	double			inv_det;
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
	double			perp_wal_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			d_dist_x;
	double			d_dist_y;
	int				drw_end;
	double			wl_x;
	int				line_hgt;
	int				drw_strt;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				x;
	int				y;
}					t_rc;

int					get_next_line(int fd, char **line);
void				parsing(char *file, t_conf *conf);
void				my_mlx_pixel_put(t_data *data, int x, int y, \
						int color);
void				ft_sort(int *sprite_queue, double *sprite_dest, \
						int amount);
void				rc_tex_x(t_rc *rc, t_conf *conf, t_tex *tex);
int					key_press(int key, t_game *game);
void				nval(t_conf *conf, int error);
void				tex_init(t_tex *tex, t_conf *conf);
void				raycasting(t_conf *conf);
void				check_state(t_game *game);
void				read_line(char ***spl_line, char **line, \
						t_conf *conf, t_list *lst);
void				check_valid(int i, int j, t_conf *conf, int *spr);
int					ft_close(t_conf *conf);
void				ft_bitmap(t_conf *cfg);
void				sprite_cast(t_conf *conf, double *z_buff, \
						t_tex tex);
void				free_split(char **output);
void				ft_error(t_conf *conf, t_list *lst, \
						char *line, char **spl_line);
char				*check_strdup(const char *s, t_conf *conf);
int					ft_color(char **col_line, t_conf *conf, \
						int *color);
void				list_add(t_conf *conf, t_list *lst, char *line);
void				chk_empty(t_conf *conf, t_list *lst);
void				frame_res(char **spl_line, t_conf *conf);
void				check_pos(t_conf *conf, int i, int j);
void				check_path(t_conf *conf, char **line, char **s);
void				map(t_list *lst, t_conf *conf, \
						char *line, char **spl_line);
void				rc_tex_step(t_rc *rc, t_tex *tex);
void				ft_flags(char **spl_line, char *line, t_list *lst, t_conf *conf);
void				rc_paint_walls(t_rc *rc, t_conf *conf, \
						t_tex tex);
void				rc_walls(t_rc *rc, t_conf *conf, t_tex *tx);
void				check_tag(t_conf *conf, char *s, char *tag);
int					key_unpress(int key, t_game *game);
void				code_error(t_conf *conf);

#endif

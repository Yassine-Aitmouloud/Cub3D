/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:04:17 by anas              #+#    #+#             */
/*   Updated: 2025/10/09 19:52:52 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIDTH 1920
# define MINIMAP_SCALE 16
# define HEIGHT 1080
# define TILE_SIZE 64
# define M_PI 3.141592653589793238462643383279502984
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdbool.h>

enum		e_keycode
{
	ESC = 65307,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	KEY_UP = 119,
	CROSS = 17,
	CAMERA_R = 65363,
	CAMERA_L = 65361,
};

enum e_Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

typedef struct s_texture
{
	void	*img;
	int		*pixels;
	int		width;
	int		height;
}	t_texture;

typedef struct s_player
{
	int					map_x;
	int					map_y;
	double				side_distx;
	double				side_disty;
	double				px;
	double				py;
	double				ray_x;
	double				ray_y;
	double				raydirx;
	double				raydiry;
	double				pov;
	double				angle;
	double				angle_rad;
	double				ray_angle;
	double				delta_x;
	double				delta_y;
	double				step_x;
	double				step_y;
	int					side;
	int					hit;
	enum e_Direction	vue;
}	t_player;

typedef struct s_keys
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	arrow_right;
	int	arrow_left;
	int	mouse_moved;
	int	needs_redraw;
}	t_keys;

typedef struct s_cub
{
	t_player	info;
	t_keys		keys;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*win;
	void		*player;
	void		*wall;
	void		*sky;
	void		*flor;
	char		**map;
	int			x;
	int			y;
	t_texture	textures[4];
	void		*gun_img;
	int			*gun_pixels;
	int			gun_width;
	int			gun_height;
	int			gun_x;
	int			gun_y;
	float		gun_scale;
}	t_cup;

typedef struct s_texture_params
{
	double	prep_dist;
	int		i;
	double	line_height;
	double	draw_start;
	double	draw_end;
}	t_texture_params;

typedef struct s_minimap
{
	int		center_x;
	int		center_y;
	int		radius;
	int		map_height;
	int		map_width;
	double	player_x;
	double	player_y;
}	t_minimap;

typedef struct t_GC
{
	void		*ptr;
	struct t_GC	*next;
}				t_garcol;

typedef struct file_content
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	int			red;
	int			green;
	int			blue;
	t_garcol	*g_head;
	int			x;
	int			y;
}				t_content;

typedef struct s_parse
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			c;
	int			f;
	int			map_flag;
	int			flag_c_f;
	int			flag;
	int			tex_num;
	int			colors_num;
	int			map_end;
	int			len_up;
	int			len_down;
}				t_parse;

typedef struct point
{
	int			x;
	int			y;
}				t_point;

typedef struct queue
{
	t_point		*data;
	int			front;
	int			back;
	int			capacity;
}				t_queue;

void			clear_textures(void);
void			pixel_put(int x, int y, int color);
void			clear_mlx(void);
void			error(char *msg);
int				check_file(char *file);
int				valid_name(char *file, char *extention);
t_content		*content(void);
t_parse			*parse(void);
void			*gc_malloc(size_t size);
void			gc_collect(void);
int				check_texturs(char *line);
int				empty_line(char *line);
int				add_key(char *line);
int				valid_content(int fd);
int				check_colors(char *line);
void			floor_color(char **str);
int				valid_map(char *file);
int				valid_h_w_walls(void);
void			print_content(void);
int				player_number(void);
int				texturs_or_colors(int key, char *tmp);
int				map_lines(char *line);
int				add_colors(void);
int				count_commas(char *color, int *i);
void			all_colors(char *identifier);
int				process_line(char *line);
int				change_space(int x, int y, int height, int width);
int				closed(void);
int				valid_map_line(char *line);
void			add_in_queue(t_queue *q, t_point point);
int				init_queue(t_queue *q, int capacity);
t_point			out_of_queue(t_queue *q);
int				up(int i, int y);
int				init_map(void);
void			draw_minimap_cell(int map_x, int map_y, t_minimap *mini);
void			get_map_size(int *height, int *width);
void			draw_square(int x, int y, int color);
void			side_step(void);
void			draw_wall(int i);
void			load_texture(t_texture *tex, char *path);
void			load_gun_texture(void);
void			draw_gun_column(int screen_y, int scaled_width);
void			calculate_wall_x(double prep_dist, t_texture *tex, int *tex_x);
void			draw_floor_ceiling(t_texture_params *params);
void			draw_wall_texture(t_texture_params *p, t_texture *tt, int t);
void			determine_texture(int *tex_num);
int				redraw(void);
int				is_wall(double x, double y);
void			ft_up(void);
void			ft_right(void);
void			ft_down(void);
void			ft_left(void);
int				moves(void);
void			pixel_put(int x, int y, int color);
void			game_init(void);
t_cup			*g_game(void);
int				ft_close(void);
int				get_the_vue(char **map, int i, int j);
void			find_player_position(char **map);
void			cast_rays(void);
void			prepare_data(void);
void			draw_minimap(void);
void			draw_gun(void);

#endif
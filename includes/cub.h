#ifndef CUB_H
#define CUB_H

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 64
# define M_PI 3.141592653589793238462643383279502984
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

extern char *map[];
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

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

typedef struct s_player
{
	int mapX;
	int mapY;
	double sideDistx;
	double sideDisty;
    double	px;
    double	py;
    double	ray_x;
    double	ray_y;
	double raydirx;
	double raydiry;
	double pov;
	double angle;
	double angle_rad;
	double ray_angle;
	double delta_x;
	double delta_y;
	double step_x;
	double step_y;
	int side;
	int hit;
	enum Direction vue;
}   t_player;

typedef struct s_keys
{
	int up;
	int down;
	int right;
	int left;
	int arrow_right;
	int arrow_left;	
} t_keys;

typedef struct s_cub
{
	t_player info;
	t_keys keys;
    void *mlx;
    void *img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void *win;
	void	*player;
	void	*wall;
	void	*sky;
	void	*flor;
	char	**map;
	int x;
	int y;
} t_cup;

// void	cast_ray();

// void	draw(int wall_height, int col);
void	pixel_put(int x, int y, int color);
void    game_init();
t_cup	*g_game(void);
int	ft_close();
int get_the_vue(char **map,int i, int j);
void	find_player_position(char **map);
void	cast_rays();
void	prepare_data();

#endif
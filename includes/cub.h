#ifndef CUB_H
#define CUB_H

#define WIDTH 1920
#define HEIGHT 1080
#define TILE_SIZE 64
#define M_PI 3.141592653589793238462643383279502984
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>

extern char **map;
enum		e_keycode
{
	ESC = 65307,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_UP = 65362,
	CROSS = 17,
};

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

typedef struct s_player
{
    double	px;
    double	py;
    double	ray_x;
    double	ray_y;
	double dx;
	double dy;
	double pov;
	double angle;
	double ray_angle;
	double dist;
	double projection;
	enum Direction vue;
}   t_player;

typedef struct s_sizes
{
    int	w_player;
    int	h_player;
	int wall;
}   t_sizes;

typedef struct s_cub
{
	t_player info;
	t_sizes sizes;
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
void	cast_rays();

void	draw(int wall_height, int col);
void	pixel_put(int x, int y, int color);
void    game_init();
t_cup	*g_game(void);
int	ft_close();
int get_the_vue(char **map,int i, int j);
void	find_player_position(char **map);
void	start_game();


#endif
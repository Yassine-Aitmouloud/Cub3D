#ifndef CUB_H
#define CUB_H

#define WIDTH 1920
#define HEIGHT 1080

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>

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
    int	x;
    int	y;
	enum Direction vue;
}   t_player;

typedef struct s_cub
{
	t_player player;
    void *mlx;
    void *img;
    void *win;
	void	*wall;
	void	*sky;
	void	*flor;
	char	**map;
    
} t_cup;
void    game_init();
t_cup	*g_game(void);
int close();


#endif
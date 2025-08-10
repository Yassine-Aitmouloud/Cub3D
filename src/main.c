#include "../includes/cub.h"

char *map[] = {
    "1111111",
    "10101001",
    "1000001",
    "1000001",
    "1000001",
    "110P011",
    "1000001",
    "1111111",
    NULL
};

t_cup	*g_game(void)
{
    	static t_cup	infos;
    
    	return (&infos);
}



int close2(int key)
{
    printf("key hit => %d\n",key);
    if (key == ESC)
        exit(0);
    // if (key == 	KEY_UP)
    //     g_game()->info.py += 0.1;
    // if (key == KEY_DOWN)
    //     ft_down();
    // if (key == KEY_LEFT)
    //     ft_left();
    // if (key == KEY_RIGHT)
    //     ft_right();
    cast_rays();
    return 1;
}
int ft_close()
{
    exit(175);
}

void    game_init()
{
    g_game()->mlx = mlx_init();
    g_game()->win = mlx_new_window(g_game()->mlx,WIDTH,HEIGHT,"hello");
    // mlx_string_put(g_game()->mlx, g_game()->win, (WIDTH / 2) - 70, 20, 0xFFFFFF, "welcome to the game");
    g_game()->img = mlx_new_image(g_game()->mlx,WIDTH,HEIGHT);
    g_game()->addr = mlx_get_data_addr(g_game()->img,&g_game()->bits_per_pixel,
            &g_game()->line_length,&g_game()->endian);
}

void	pixel_put(int x, int y, int color)
{
	char	*dst;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = g_game()->addr + (y * g_game()->line_length + x * (g_game()->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    game_init();
    prepare_data();
    cast_rays();
    mlx_hook(g_game()->win,CROSS,0,ft_close,NULL);
    mlx_key_hook(g_game()->win,close2,NULL);
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    mlx_loop(g_game()->mlx);
    return (0);
}


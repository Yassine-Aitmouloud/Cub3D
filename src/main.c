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

void    ft_down()
{
    double moveSpeed = 0.1;
    double rad = g_game()->info.angle * M_PI / 180;
    g_game()->info.px -= cos(rad) * moveSpeed;
    g_game()->info.py -= sin(rad) * moveSpeed;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

void    ft_up()
{
    double moveSpeed = 0.1;
    double rad = g_game()->info.angle * M_PI / 180;
    g_game()->info.px += cos(rad) * moveSpeed;
    g_game()->info.py += sin(rad) * moveSpeed;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

void    ft_right()
{
    double moveSpeed = 0.1;
    double rad = (g_game()->info.angle + 90)* M_PI / 180;
    g_game()->info.px += cos(rad) * moveSpeed;
    g_game()->info.py += sin(rad) * moveSpeed;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

void    ft_left()
{
    double moveSpeed = 0.1;
    double rad = (g_game()->info.angle + 90)* M_PI / 180;
    g_game()->info.px -= cos(rad) * moveSpeed;
    g_game()->info.py -= sin(rad) * moveSpeed;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

int ft_close()
{
    exit(175);
}

void    game_init()
{
    g_game()->mlx = mlx_init();
    g_game()->win = mlx_new_window(g_game()->mlx,WIDTH,HEIGHT,"GO GO GO");
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

int    key_pressed(int key)
{
    if (key == ESC)
        exit(0);
    if (key == KEY_UP)
        g_game()->keys.up = 1;
    if (key == KEY_DOWN)
        g_game()->keys.down = 1;
    if (key == KEY_RIGHT)
        g_game()->keys.right = 1;
    if (key == KEY_LEFT)
        g_game()->keys.left = 1;
    if (key == CAMERA_R)
        g_game()->keys.arrow_right = 1;
    if (key == CAMERA_L)
        g_game()->keys.arrow_left = 1;
    return 0;
}

int    key_unpressed(int key)
{
    if (key == KEY_UP)
        g_game()->keys.up = 0;
    if (key == KEY_DOWN)
        g_game()->keys.down = 0;
    if (key == KEY_RIGHT)
        g_game()->keys.right = 0;
    if (key == KEY_LEFT)
        g_game()->keys.left = 0;
    if (key == CAMERA_R)
        g_game()->keys.arrow_right = 0;
    if (key == CAMERA_L)
        g_game()->keys.arrow_left = 0;
    return 0;
}

int moves()
{
    if (g_game()->keys.up)
        ft_up();
    if (g_game()->keys.down)
        ft_down();
    if (g_game()->keys.right)
        ft_right();
    if (g_game()->keys.left)
        ft_left();
    if (g_game()->keys.arrow_left)
    {
        g_game()->info.angle -= 3;
        mlx_clear_window(g_game()->mlx,g_game()->win);
        cast_rays();
        mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    }
    if (g_game()->keys.arrow_right)
    {
        g_game()->info.angle += 3;
        mlx_clear_window(g_game()->mlx,g_game()->win);
        cast_rays();
        mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    }
    return 0;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    game_init();
    prepare_data();
    cast_rays();
    mlx_hook(g_game()->win,CROSS,0,ft_close,NULL);
    // mlx_key_hook(g_game()->win,close2,NULL);
    mlx_hook(g_game()->win,2,1L<<0,key_pressed,NULL);
    mlx_hook(g_game()->win,3,1L<<1,key_unpressed,NULL);
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    mlx_loop_hook(g_game()->mlx, moves,NULL);
    mlx_loop(g_game()->mlx);
    return (0);
}


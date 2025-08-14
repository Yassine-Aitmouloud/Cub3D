#include "../includes/cub.h"

char *map[] = {
    "11111111111",
    "10010000001",
    "10000010001",
    "10100P00101",
    "10001000001",
    "11111111111",
    NULL
};

t_cup	*g_game(void)
{
    	static t_cup	infos;
    
    	return (&infos);
}
int is_wall(double x, double y)
{
    double radius = 0.3;
    int map_x;
    int map_y;
    map_x = (int)(x + radius);
    map_y = (int)(y - radius);
    if (map_y < 0 || map_x < 0 || !map[map_y] || !map[map_y][map_x] || map[map_y][map_x] == '1')
        return 1;

    map_x = (int)(x - radius);
    map_y = (int)(y + radius);
    if (map_y < 0 || map_x < 0 || !map[map_y] || !map[map_y][map_x] || map[map_y][map_x] == '1')
        return 1;

    map_x = (int)(x + radius);
    map_y = (int)(y + radius);
    if (map_y < 0 || map_x < 0 || !map[map_y] || !map[map_y][map_x] || map[map_y][map_x] == '1')
        return 1;

    return 0;
}


void    ft_up()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.3;
    double rad = g_game()->info.angle * M_PI / 180;
    NEXTx += cos(rad) * moveSpeed;
    NEXTy += sin(rad) * moveSpeed;
    // ("nexty => %f nextx => %f\n",NEXTy,NEXTy);
    // if (!is_wall(NEXTx,NEXTy))
    // {
    //     g_game()->info.px = NEXTx;
    //     g_game()->info.py = NEXTy;
    // } 
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}
void    ft_down()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.3;
    double rad = g_game()->info.angle * M_PI / 180;
    NEXTx -= cos(rad) * moveSpeed;
    NEXTy -= sin(rad) * moveSpeed;
    // ("nexty => %f nextx => %f\n",NEXTy,NEXTy);
    // ("%d\n",is_wall(NEXTx,NEXTy));
    // if (!is_wall(NEXTx,NEXTy))
    // {
    //     g_game()->info.px = NEXTx;
    //     g_game()->info.py = NEXTy;
    // } 
    // ("PX: %.2f  PY: %.2f  NX: %.2f  NY: %.2f\n",
    // g_game()->info.px, g_game()->info.py, NEXTx, NEXTy);
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

void    ft_right()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.3;
    double rad = (g_game()->info.angle + 90) * M_PI / 180;
    NEXTx += cos(rad) * moveSpeed;
    NEXTy += sin(rad) * moveSpeed;
    // ("nexty => %f nextx => %f\n",NEXTy,NEXTy);
    // if (!is_wall(NEXTx,NEXTy))
    // {
    //     g_game()->info.px = NEXTx;
    //     g_game()->info.py = NEXTy;
    // } 
    // ("PX: %.2f  PY: %.2f  NX: %.2f  NY: %.2f\n",
    // g_game()->info.px, g_game()->info.py, NEXTx, NEXTy);
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    mlx_clear_window(g_game()->mlx,g_game()->win);
    cast_rays();
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
}

void    ft_left()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.3;
    double rad = (g_game()->info.angle + 90) * M_PI / 180;
    NEXTx -= cos(rad) * moveSpeed;
    NEXTy -= sin(rad) * moveSpeed;
    // ("nexty => %f nextx => %f\n",NEXTy,NEXTy);
    // ("%d\n",is_wall(NEXTx,NEXTy));
    // if (!is_wall(NEXTx,NEXTy))
    // {
    //     g_game()->info.px = NEXTx;
    //     g_game()->info.py = NEXTy;
    // } 
    // ("PX: %.2f  PY: %.2f  NX: %.2f  NY: %.2f\n",
    // g_game()->info.px, g_game()->info.py, NEXTx, NEXTy);
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
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
        g_game()->info.angle -= 5;
        mlx_clear_window(g_game()->mlx,g_game()->win);
        cast_rays();
        mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    }
    if (g_game()->keys.arrow_right)
    {
        g_game()->info.angle += 5;
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


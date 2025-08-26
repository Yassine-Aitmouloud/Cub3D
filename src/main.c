#include "../cub.h"

char *map[81] = {
"11111",
"10101",
"10001",
"10P01",
"10001",
"11111",
NULL

    // "                   1                                                   1",
    // "                  101                                                 101",
    // "                 10001                                               10001",
    // "                1000001                                             1000001",
    // "               100000001                                           100000001",
    // "              10000000001                                         10000000001",
    // "             1000000000001                                       1000000000001",
    // "            100000000000001                                     100000000000001",
    // "           10000000000000001                                   10000000000000001",
    // "          1000000000000000001              111111111111       1000000000000000001",
    // "         100000000000000000001             100000000001      100000000000000000001",
    // "        10000000000000000000001            101111111101     10000000000000000000001",
    // "       1000000000000000000000001     111111101    10001    1000000000000000000000001",
    // "      100000000000000000000000001    100001101    1011    100000000000000000000000001",
    // "     10000000000000000000000000001   101100001   1001    10000000000000000000000000001",
    // "    1000000000000000000000000000001  101 1111   1001    1000000000000000000000000000001",
    // "   100000000000000111111110000000001 101        101    100000000000000111111110000000001",
    // "  1000000000000001        10000000001101        101   1000000000000001        10000000001",
    // " 1000000000000001          1000000    01        101111000000000000001          10000000001",
    // "1000000000000001            1000 1  P 01        100000000000000000001           1000000001",
    // " 1000000000000001            1000     11        111111000000000000001            1000000001",
    // "  1000000000000001            10000001                1000000000000001            10000001",
    // "   10000000000000011111111    1000001                  10000000000000011111111    1000001",
    // "    10000000000000000000001    11111                    10000000000000000000001    11111",
    // "     100000000000000000000011  1                         100000000000000000000011  1",
    // "      10000000000000000000001  1                          10000000000000000000001  1",
    // "       1000000000000000000001  1                           1000000000000000000001  1",
    // "        100000000000000000001  1                            100000000000000000001 1",
    // "         1000000000000000001   1                             1000000000000000001   1",
    // "          10000000000000001   1                               10000000000000001   1",
    // "           100000000000001    1                                100000000000001    1",
    // "            1000000000001    1                                  1000000000001    1",
    // "             10000000001    1                                    10000000001    1",
    // "              100000001    1                                      100000001    1",
    // "               1000001                                             1000001",
    // "                10001                                               10001",
    // "                 101                                                 111",
    // "                  1"
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
    double moveSpeed = 0.1;
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
    draw_gun();
}
void    ft_down()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.1;
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
    draw_gun();
}

void    ft_right()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.1;
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
    draw_gun();
}

void    ft_left()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.1;
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
    draw_gun();
}


int ft_close()
{
    exit(175);
}

void    game_init()
{
    g_game()->mlx = mlx_init();
    if (!g_game()->mlx)
    {
        printf("Failed to initialize MLX\n");
        exit(1);
    }
    g_game()->win = mlx_new_window(g_game()->mlx,WIDTH,HEIGHT,"GO GO GO");
    if (!g_game()->win)
    {
        printf("Failed to create window\n");
        exit(1);
    }
    g_game()->img = mlx_new_image(g_game()->mlx,WIDTH,HEIGHT);
    if (!g_game()->img)
    {
        printf("Failed to create image\n");
        exit(1);
    }
    g_game()->addr = mlx_get_data_addr(g_game()->img,&g_game()->bits_per_pixel,
    &g_game()->line_length,&g_game()->endian);
    printf("Game initialized successfully\n");
    load_gun_texture();
}

void	pixel_put(int x, int y, int color)
{
    char	*dst;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    return;
	dst = g_game()->addr + (y * g_game()->line_length + x * (g_game()->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	load_gun_texture()
{
	int width, height;
	
	printf("Loading gun texture...\n");
	g_game()->gun = mlx_xpm_file_to_image(g_game()->mlx, "textures/gun.xpm", &width, &height);
	if (!g_game()->gun)
	{
		printf("Failed to load gun texture\n");
		exit(1);
	}
	printf("Gun texture loaded successfully (%dx%d)\n", width, height);
}

void	draw_gun()
{
	int gun_width = 64;
	int gun_height = 64;
	int gun_x = WIDTH - gun_width - 50;  // Bottom-right corner with some margin
	int gun_y = HEIGHT - gun_height - 50;
	
	if (g_game()->gun)
		mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->gun, gun_x, gun_y);
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
        draw_gun();
    }
    if (g_game()->keys.arrow_right)
    {
        g_game()->info.angle += 3;
        mlx_clear_window(g_game()->mlx,g_game()->win);
        cast_rays();
        mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
        draw_gun();
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
    draw_gun();
    mlx_loop_hook(g_game()->mlx, moves,NULL);
    mlx_loop(g_game()->mlx);
    return (0);
}

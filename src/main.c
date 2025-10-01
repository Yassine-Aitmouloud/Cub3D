#include "../cub.h"
// char *map[81] = {
// // "11111",
// // "10101",
// // "10001",
// // "10P01",
// // "10001",
// // "11111"

//     "                   1                                                   1",
//     "                  101                                                 101",
//     "                 10001                                               10001",
//     "                1000001                                             1000001",
//     "               100000001                                           100000001",
//     "              10000000001                                         10000000001",
//     "             1000000000001                                       1000000000001",
//     "            100000000000001                                     100000000000001",
//     "           10000000000000001                                   10000000000000001",
//     "          1000000000000000001              111111111111       1000000000000000001",
//     "         100000000000000000001             100000000001      100000000000000000001",
//     "        10000000000000000000001            101111111101     10000000000000000000001",
//     "       1000000000000000000000001     111111101    10001    1000000000000000000000001",
//     "      100000000000000000000000001    100001101    1011    100000000000000000000000001",
//     "     10000000000000000000000000001   101100001   1001    10000000000000000000000000001",
//     "    1000000000000000000000000000001  101 1111   1001    1000000000000000000000000000001",
//     "   100000000000000111111110000000001 101        101    100000000000000111111110000000001",
//     "  1000000000000001        10000000001101        101   1000000000000001        10000000001",
//     " 1000000000000001          1000000    01        101111000000000000001          10000000001",
//     "1000000000000001            1000 1  P 01        100000000000000000001           1000000001",
//     " 1000000000000001            1000     11        111111000000000000001            1000000001",
//     "  1000000000000001            10000001                1000000000000001            10000001",
//     "   10000000000000011111111    1000001                  10000000000000011111111    1000001",
//     "    10000000000000000000001    11111                    10000000000000000000001    11111",
//     "     100000000000000000000011  1                         100000000000000000000011  1",
//     "      10000000000000000000001  1                          10000000000000000000001  1",
//     "       1000000000000000000001  1                           1000000000000000000001  1",
//     "        100000000000000000001  1                            100000000000000000001 1",
//     "         1000000000000000001   1                             1000000000000000001   1",
//     "          10000000000000001   1                               10000000000000001   1",
//     "           100000000000001    1                                100000000000001    1",
//     "            1000000000001    1                                  1000000000001    1",
//     "             10000000001    1                                    10000000001    1",
//     "              100000001    1                                      100000001    1",
//     "               1000001                                             1000001",
//     "                10001                                               10001",
//     "                 101                                                 111",
//     "                  1"
// };

t_content	*content(void)
{
	static t_content	c;

	return (&c);
}

t_parse	*parse(void)
{
	static t_parse	c;

	return (&c);
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	gc_collect();
	exit(EXIT_FAILURE);
}

t_cup	*g_game(void)
{
    	static t_cup	infos;
    
    	return (&infos);
}

int is_wall(double x, double y)
{
    double radius = 0.2; 
    int map_x;
    int map_y;

    map_x = (int)(x - radius);
    map_y = (int)(y - radius);
    if (map_y < 0 || map_x < 0 || !content()->map[map_y] || !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
        return 1;

    map_x = (int)(x + radius);
    map_y = (int)(y - radius);
    if (map_y < 0 || map_x < 0 || !content()->map[map_y] || !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
        return 1;

    map_x = (int)(x - radius);
    map_y = (int)(y + radius);
    if (map_y < 0 || map_x < 0 || !content()->map[map_y] || !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
        return 1;

    map_x = (int)(x + radius);
    map_y = (int)(y + radius);
    if (map_y < 0 || map_x < 0 || !content()->map[map_y] || !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
        return 1;

    return 0; 
}


void    ft_up()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.2;
    double rad = g_game()->info.angle * M_PI / 180;
    NEXTx += cos(rad) * moveSpeed;
    NEXTy += sin(rad) * moveSpeed;
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    g_game()->keys.needs_redraw = 1;
}
void    ft_down()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.2;
    double rad = g_game()->info.angle * M_PI / 180;
    NEXTx -= cos(rad) * moveSpeed;
    NEXTy -= sin(rad) * moveSpeed;
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    g_game()->keys.needs_redraw = 1;
}

void    ft_right()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.2;
    double rad = (g_game()->info.angle + 90) * M_PI / 180;
    NEXTx += cos(rad) * moveSpeed;
    NEXTy += sin(rad) * moveSpeed;
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    g_game()->keys.needs_redraw = 1;
}

void    ft_left()
{
    double NEXTx = g_game()->info.px;
    double NEXTy = g_game()->info.py;
    double moveSpeed = 0.2;
    double rad = (g_game()->info.angle + 90) * M_PI / 180;
    NEXTx -= cos(rad) * moveSpeed;
    NEXTy -= sin(rad) * moveSpeed;
    if (!is_wall(NEXTx, g_game()->info.py))
        g_game()->info.px = NEXTx;
    if (!is_wall(g_game()->info.px, NEXTy))
        g_game()->info.py = NEXTy;
    g_game()->keys.needs_redraw = 1;
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
    g_game()->keys.up = 0;
    g_game()->keys.down = 0;
    g_game()->keys.left = 0;
    g_game()->keys.right = 0;
    g_game()->keys.arrow_left = 0;
    g_game()->keys.arrow_right = 0;
    g_game()->keys.mouse_moved = 0;
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
    if (key == ESC)
        exit(0);
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
        g_game()->keys.needs_redraw = 1;
    }
    if (g_game()->keys.arrow_right)
    {
        g_game()->info.angle += 3;
        g_game()->keys.needs_redraw = 1;
    }
    if (g_game()->keys.mouse_moved)
        g_game()->keys.mouse_moved = 0;    
    if (g_game()->keys.needs_redraw)
    {
        mlx_clear_window(g_game()->mlx,g_game()->win);
        cast_rays();
        mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    }
    draw_minimap();
    draw_gun();
    return 0;
}

int mouse_move(int x)
{
    static int last_x = -1;
    
    mlx_mouse_hide(g_game()->mlx, g_game()->win);
    if (last_x == -1)
        last_x = x;

    int delta_x = x - last_x;
    last_x = x;
 
    if (abs(delta_x) < 2)
        return (0);
    double sensitivity = 0.3;
    if (abs(delta_x) > 10)
        sensitivity = 0.6;
    
    g_game()->info.angle += (delta_x * sensitivity);
    
    g_game()->keys.mouse_moved = 1;
    g_game()->keys.needs_redraw = 1;
    return (0);
}


int main(int ac, char **av)
{
    if (ac != 2)
	{
		printf("[usage]: ./cub3D {file.cub}\n");
		return (1);
	}
	if (check_file(av[1]) == 0)
		error("Error\nInvalid file name or content\n");
	if (valid_map(av[1]) == 0 || valid_h_w_walls() == 0)
		error("Error\nInvalid Map\n");    
    game_init();
    prepare_data();
    cast_rays();
    moves();
    mlx_hook(g_game()->win,CROSS,0,ft_close,NULL);
    mlx_hook(g_game()->win, 6, 1L<<6, mouse_move, NULL);
    mlx_hook(g_game()->win,2,1L<<0,key_pressed,NULL);
    mlx_hook(g_game()->win,3,1L<<1,key_unpressed,NULL);
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    mlx_loop_hook(g_game()->mlx, moves,NULL);
    mlx_loop(g_game()->mlx);
    gc_collect();
    return (0);
}


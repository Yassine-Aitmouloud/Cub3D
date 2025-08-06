// int width = WIDTH;
// int height = HEIGHT;
// while(width != 0)
// {
//     pixel_put(width, height, 0x0000FF);
//     height = HEIGHT;
//     while(height != 0)
//     {
//         pixel_put(width, height, 0x0000FF);
//         height--;
//     }    
//     width--;
// }
#include "../includes/cub.h"

char *map[] = {
    "111111",
    "100001",
    "10P001",
    "100001",
    "111111",
    NULL
};

t_cup	*g_game(void)
{
    	static t_cup	infos;
    
    	return (&infos);
}

void    ft_up()
{
    printf("up\n");
    double rad = g_game()->info.angle * (M_PI / 180.0);
    double move_speed = 5.0;
    g_game()->info.px += cos(rad) * move_speed;
    g_game()->info.py += sin(rad) * move_speed;
    g_game()->img = mlx_new_image(g_game()->mlx,WIDTH,HEIGHT);
    g_game()->addr = mlx_get_data_addr(g_game()->img,&g_game()->bits_per_pixel,
            &g_game()->line_length,&g_game()->endian);
    start_game();
    mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->img, 0, 0);

}

int close2(int key)
{
    if (key == ESC)
        exit(0);
    if (key == 	KEY_UP)
        ft_up();
    // if (key == KEY_DOWN)
    //     ft_down();
    // if (key == KEY_LEFT)
    //     ft_left();
    // if (key == KEY_RIGHT)
    //     ft_right();
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
    start_game();
    mlx_hook(g_game()->win,CROSS,0,ft_close,NULL);
    mlx_key_hook(g_game()->win,close2,NULL);
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    mlx_loop(g_game()->mlx);
    return (0);
}


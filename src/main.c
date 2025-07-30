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

char *mapp[] = {
    "11111111111111111111111111",
    "10111111110111111100010001",
    "10111111110111111111010101",
    "10111111110111111110000101",
    "11111111110111111111111111",
    "10111111110111111100000101",
    "11111111110111111111111101",
    "1011111111P111111100000001",
    "11111111111111111111111101",
    "11111111111111111111111111"
};

char **map = mapp;

t_cup	*g_game(void)
{
    	static t_cup	infos;
    
    	return (&infos);
}
int close2(int key)
{
    if (key == ESC)
        exit(0);
    return 1;
}
int ft_close()
{
    exit(175);
}

void    game_init()
{
    g_game()->mlx = mlx_init();
    g_game()->win = mlx_new_window(g_game()->mlx,WIDTH,HEIGHT,"hallo");
    mlx_string_put(g_game()->mlx, g_game()->win, (WIDTH / 2) - 70, 20, 0xFFFFFF, "welcome to the game");
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
    mlx_put_image_to_window(g_game()->mlx,g_game()->win,g_game()->img,0,0);
    mlx_hook(g_game()->win,CROSS,0,ft_close,NULL);
    mlx_key_hook(g_game()->win,close2,NULL);
    start_game();
    mlx_loop(g_game()->mlx);
    return (0);
}


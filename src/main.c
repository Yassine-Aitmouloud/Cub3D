#include "../includes/cub.h"
char *map[] = {
    "1111111111",
    "1000010001",
    "1011010101",
    "1010000101",
    "1010110101",
    "1000000101",
    "1011111101",
    "1000000001",
    "1111111101",
    "1111111111"
};


t_cup	*g_game(void)
{
	static t_cup	infos;

	return (&infos);
}

int close()
{
    exit(0);
}

void    game_init()
{
    g_game()->mlx = mlx_init();
    g_game()->win = mlx_new_window(g_game()->mlx,WIDTH,HEIGHT,"hallo");
    mlx_hook(g_game()->win,CROSS,0,close,NULL);
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    game_init();
    mlx_loop(g_game()->mlx);
    return (0);
}
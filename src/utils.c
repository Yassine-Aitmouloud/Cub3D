#include "../includes/cub.h"

int get_the_vue(char **map,int i, int j)
{
    if (!map)
        return (1);
    if (map[i][j] == 'S')
        return (g_game()->info.vue = SOUTH, 0);
    if (map[i][j] == 'N')
        return(g_game()->info.vue = NORTH, 0);
    if (map[i][j] == 'W')
        return (g_game()->info.vue = WEST, 0);
    if (map[i][j] == 'E')
        return (g_game()->info.vue = EAST, 0);
    return (1);
}

void	find_player_position(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (get_the_vue(map,i,j) == 0 || map[i][j] == 'P')
			{
				g_game()->info.x = j;
				g_game()->info.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_images(int i, int j)
{
	if (map[i][j] == '1')
		mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->wall, j * 64, i
			* 64);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->player, j * 64, i
			* 64);
	else
		mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->flor, j * 64, i
			* 64);
}

void	create_images()
{
	g_game()->wall = mlx_xpm_file_to_image(g_game()->mlx,"/home/yaaitmou/Desktop/Cub3D/textures/wall.xpm",&g_game()->sizes.wall,&g_game()->sizes.wall);
	if (!g_game()->wall)
		printf("hello\n");
	g_game()->player = mlx_xpm_file_to_image(g_game()->mlx,"/home/yaaitmou/Desktop/Cub3D/textures/coin.xpm",&g_game()->sizes.w_player,&g_game()->sizes.h_player);
	if (!g_game()->player)
		printf("player\n");
	g_game()->flor = mlx_xpm_file_to_image(g_game()->mlx,"/home/yaaitmou/Desktop/Cub3D/textures/space.xpm",&g_game()->sizes.wall,&g_game()->sizes.wall);
	if (!g_game()->flor)
		printf("flor\n");
}

void	start_game()
{
	int	i = 0;
	int	j = 0;

	g_game()->sizes.w_player = 10;
	g_game()->sizes.h_player = 14;
	g_game()->sizes.wall = 64;

	create_images();
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_images(i, j);
			j++;
		}
		i++;
	}
}
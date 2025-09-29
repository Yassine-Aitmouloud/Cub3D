#include "../cub.h"

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
			if (map[i][j] == 'N' || 
                        map[i][j] == 'W' || map[i][j] == 'S' || 
                        map[i][j] == 'E')
			{
				g_game()->info.px = j + 0.5;
				g_game()->info.py = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

void draw(int x,int start,int end,int color)
{
	while(start < end)
	{
		pixel_put(x,start,color);
		start++;
	}
}

void load_gun_texture()
{
    int bpp;
    int size_line;
    int endian;

    g_game()->gun_img = mlx_xpm_file_to_image(g_game()->mlx, "textures/tile000.xpm", 
                                             &g_game()->gun_width, &g_game()->gun_height);
    if (!g_game()->gun_img)
		error("Error\nCould not load gun texture\n");
    g_game()->gun_pixels = (int *)mlx_get_data_addr(g_game()->gun_img, &bpp, &size_line, &endian);
    g_game()->gun_scale = 2.0;
    int scaled_width = g_game()->gun_width * g_game()->gun_scale;
    int scaled_height = g_game()->gun_height * g_game()->gun_scale;
    g_game()->gun_x = (WIDTH - scaled_width) / 2;
    g_game()->gun_y = HEIGHT - scaled_height;
}
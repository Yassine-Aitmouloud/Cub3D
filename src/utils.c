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
				g_game()->info.px = j;
				g_game()->info.py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw(int x,int y,int color)
{
	int x1 = 0;
	int y1 = 0;
	while(x1 != 10)
	{
		y1 = 0;
		while(y1 != 100)
		{
			pixel_put(x + x1,y + y1,color);
			y1++;
			
		}
		x1++;
	}
}

void	prepare_data()
{
	g_game()->info.angle = 270;
	g_game()->info.px = 950.0;
	g_game()->info.py = 540.0;
	g_game()->info.pov = 60.0;
}

void	start_game()
{
	int i = 0;
	int step = 0;
	int j = 1;
	// double rad;
	prepare_data();
	while(i < WIDTH)
	{
		step = 0;
		g_game()->info.ray_x = g_game()->info.px;
		g_game()->info.ray_y = g_game()->info.py;
		g_game()->info.ray_angle = (g_game()->info.angle - (g_game()->info.pov / 2) + (g_game()->info.pov * i / WIDTH));
		g_game()->info.angle_rad = g_game()->info.ray_angle * (M_PI / 180);
		g_game()->info.dx = cos(g_game()->info.angle_rad);
		g_game()->info.dy = sin(g_game()->info.angle_rad);
		while(step < 10000)
		{
			if (j == 255)
				j = 1;
			pixel_put(g_game()->info.ray_x,g_game()->info.ray_y,j);
			g_game()->info.ray_x += g_game()->info.dx * 0.03; 
			g_game()->info.ray_y += g_game()->info.dy * 0.03; 
			step++;
			j += 4;
		}
		i+= 95;
	}
}
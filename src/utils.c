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

void	draw(int wall_height,int x)
{
	int y;
	int start;
	int end;
	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);
	y = start;
	printf("->start = %d",start);
	while(y < end && y < HEIGHT)
	{
		pixel_put(x, abs(y),0xFFFF00);
		y++;
	}
}

void	cast_rays(int col)
{
	g_game()->info.ray_x = g_game()->info.px;
	g_game()->info.ray_y = g_game()->info.py;
	g_game()->info.dx = cos(g_game()->info.ray_angle);
	g_game()->info.dy = sin(g_game()->info.ray_angle);
	while(1)
	{
		g_game()->info.ray_x += g_game()->info.dx;
		g_game()->info.ray_y += g_game()->info.dy;
		g_game()->x = (int)(g_game()->info.ray_x / TILE_SIZE);
		g_game()->y = (int)(g_game()->info.ray_y / TILE_SIZE);
		if (map[g_game()->y][g_game()->x] == '1')
			break;
	}
	g_game()->info.dist = sqrt((g_game()->info.ray_x - g_game()->info.px)*(g_game()->info.ray_x - g_game()->info.px) + (g_game()->info.ray_y - g_game()->info.py)*(g_game()->info.ray_y - g_game()->info.py));
	g_game()->info.dist = g_game()->info.dist * cos(g_game()->info.ray_angle - g_game()->info.angle);
	int wall_height = (TILE_SIZE * g_game()->info.projection) / g_game()->info.dist;
	draw(wall_height,col);
}

void	start_game()
{
	int col;
	col = 0;
	find_player_position(map);
	g_game()->info.px = g_game()->info.px * TILE_SIZE + TILE_SIZE / 2;
	g_game()->info.py = g_game()->info.py * TILE_SIZE + TILE_SIZE / 2;
	g_game()->info.angle = 90 * M_PI / 180;
	g_game()->info.pov = 60 * M_PI / 180;
	g_game()->info.projection = (WIDTH / 2) / tan(g_game()->info.pov / 2);
	while(col < WIDTH)
	{
		g_game()->info.ray_angle = (g_game()->info.angle - (g_game()->info.pov / 2)) + (col * (g_game()->info.pov / WIDTH));
		cast_rays(col);
		// printf("->>> col = %d",col);
		col++;
	}
}
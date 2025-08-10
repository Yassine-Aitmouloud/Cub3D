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
	// if (!map)
	// 	return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
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

void draw(int x,int start,int end,int color)
{
	while(start < end)
	{
		pixel_put(x,start,color);
		start++;
	}
}


void	draw_wall(int i)
{
	double drawStart;
	double drawEnd;
	double lineHeight;
	double perpDist;
	if (g_game()->info.side == 0)
		perpDist = (g_game()->info.mapX - g_game()->info.px + (1 - g_game()->info.step_x) / 2) / g_game()->info.raydirx;
	else
		perpDist = (g_game()->info.mapY - g_game()->info.py + (1 - g_game()->info.step_y) / 2) / g_game()->info.raydiry;
	lineHeight = (HEIGHT / perpDist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	drawEnd   =  lineHeight / 2 + HEIGHT / 2;
	if (g_game()->info.side == 0)
		draw(i,(int)drawStart,(int)drawEnd,0xFFFFFF);
	else
		draw(i,(int)drawStart,(int)drawEnd,0x808080);
	draw(i,drawEnd,HEIGHT,0x00FF00);
	draw(i, 0, drawStart,0x0000FF);
}


void	side_step()
{
	if (g_game()->info.raydirx < 0)
	{
		g_game()->info.step_x = -1;
		g_game()->info.sideDistx = (g_game()->info.px - g_game()->info.mapX) * g_game()->info.delta_x;
	}
	else
	{
		g_game()->info.step_x = 1;
		g_game()->info.sideDistx = (g_game()->info.mapX + 1.0 - g_game()->info.px) * g_game()->info.delta_x;
	}

	if (g_game()->info.raydiry < 0)
	{
		g_game()->info.step_y = -1;
		g_game()->info.sideDisty = (g_game()->info.py - g_game()->info.mapY) * g_game()->info.delta_y;
	}
	else
	{
		g_game()->info.step_y = 1;
		g_game()->info.sideDisty = (g_game()->info.mapY + 1.0 - g_game()->info.py) * g_game()->info.delta_y;
	}

}


void	cast_ray(int i)
{
	g_game()->info.hit = 0;
	g_game()->info.side = -1;
	side_step();
	while(g_game()->info.hit != 1)
	{
		// printf("sideDistX => %f _ sideDistY => %f | deltax => %f deltay => %f\n",g_game()->info.sideDistx,g_game()->info.sideDisty,g_game()->info.delta_x,g_game()->info.delta_y);	
		if (g_game()->info.sideDistx < g_game()->info.sideDisty)
		{
			g_game()->info.sideDistx += g_game()->info.delta_x;
        	g_game()->info.mapX += g_game()->info.step_x;
        	g_game()->info.side = 0;
		}
		else
		{
			g_game()->info.sideDisty += g_game()->info.delta_y;
			g_game()->info.mapY += g_game()->info.step_y;
			// printf("map y => %d\n",g_game()->info.mapY);
			g_game()->info.side = 1;
			// printf("%d\n",g_game()->info.side);
		}
		if ((g_game()->info.mapY < 0  || g_game()->info.mapX < 0) || map[g_game()->info.mapY][g_game()->info.mapX] == '1')
			g_game()->info.hit = 1;		
	}
	draw_wall(i);
}

void	prepare_data()
{
	g_game()->info.angle = 270;
	find_player_position(map);
	g_game()->info.pov = 60.0;
	g_game()->info.step_x = 1;
	g_game()->info.step_y = 1;
	
}


void	cast_rays()
{
	int i = 0;
	while(i < WIDTH)
	{
		g_game()->info.mapX = (int)g_game()->info.px;
		g_game()->info.mapY = (int)g_game()->info.py;
		g_game()->info.ray_angle = (g_game()->info.angle - (g_game()->info.pov / 2) + (g_game()->info.pov * i / WIDTH));
		g_game()->info.angle_rad = g_game()->info.ray_angle * (M_PI / 180);
		g_game()->info.raydirx = cos(g_game()->info.angle_rad);
		g_game()->info.raydiry = sin(g_game()->info.angle_rad);
		g_game()->info.delta_x = fabs(1 / g_game()->info.raydirx);
		g_game()->info.delta_y = fabs(1 / g_game()->info.raydiry);
		// printf("px => %f | py => %f | map_x => %d | map_y => %d | ray_angle => %f | angle_rad => %f | raydirx => %f | raydiry => %f \n",g_game()->info.px,g_game()->info.py,g_game()->info.mapX,g_game()->info.mapY,
		// 	g_game()->info.ray_angle,g_game()->info.angle_rad,g_game()->info.raydirx,g_game()->info.raydiry);
		cast_ray(i);
		i++;
	}
}

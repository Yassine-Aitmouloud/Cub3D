# include "../cub.h"

void	draw_minimap_rows(t_minimap *mini)
{
	int	map_y;
	int	map_x;
	int	grid_radius;

	grid_radius = mini->radius / MINIMAP_SCALE;
	map_y = mini->player_y - grid_radius;
	while (map_y <= mini->player_y + grid_radius)
	{
		map_x = mini->player_x - grid_radius;
		while (map_x <= mini->player_x + grid_radius)
		{
			draw_minimap_cell(map_x, map_y, mini);
			map_x++;
		}
		map_y++;
	}
}

void	draw_minimap(void)
{
	t_minimap	mini;

	mini.center_x = 100;
	mini.center_y = 100;
	mini.radius = 100;
	get_map_size(&mini.map_height, &mini.map_width);
	mini.player_x = g_game()->info.px;
	mini.player_y = g_game()->info.py;
	draw_minimap_rows(&mini);
	draw_square(mini.center_x - MINIMAP_SCALE / 2,
		mini.center_y - MINIMAP_SCALE / 2, 0xFF0000);
}

void	cast_ray(int i)
{
	g_game()->info.hit = 0;
	g_game()->info.side = -1;
	side_step();
	while(g_game()->info.hit != 1)
	{
		// printf("map = | %c |\n",map[g_game()->info.mapY][g_game()->info.mapY]);
		if (g_game()->info.sideDistx < g_game()->info.sideDisty)
		{
			g_game()->info.side = 0;
			if (content()->map[g_game()->info.mapY][g_game()->info.mapX] == '1')
			g_game()->info.hit = 1;
			else
			{
				g_game()->info.mapX += g_game()->info.step_x;
				g_game()->info.sideDistx += g_game()->info.delta_x;
			}
		}
		else
		{
			g_game()->info.side = 1;
			if (content()->map[g_game()->info.mapY][g_game()->info.mapX] == '1')
				g_game()->info.hit = 1;
			else
			{
				g_game()->info.mapY += g_game()->info.step_y;
				g_game()->info.sideDisty += g_game()->info.delta_y;
			}
			// g_game()->info.sideDisty += g_game()->info.delta_y;
			// g_game()->info.mapY += g_game()->info.step_y;
			// // ("map y => %d\n",g_game()->info.mapY);
			// g_game()->info.side = 1;
			// // ("%d\n",g_game()->info.side);
		}
		if ((g_game()->info.mapY < 0  || g_game()->info.mapX < 0) || content()->map[g_game()->info.mapY][g_game()->info.mapX] == '1')
			g_game()->info.hit = 1;		
	}
	draw_wall(i);
}

void	prepare_data()
{
	load_texture(&g_game()->textures[0], content()->no_texture);
	load_texture(&g_game()->textures[1], content()->so_texture);
	load_texture(&g_game()->textures[2], content()->ea_texture);
	load_texture(&g_game()->textures[3], content()->we_texture);
	load_gun_texture();
	g_game()->info.angle = 270;
	find_player_position(content()->map);
	// g_game()->info.px = 2.0;
	// g_game()->info.py = 2.0;
	g_game()->info.pov = 60.0;
	g_game()->info.step_x = 1;
	g_game()->info.step_y = 1;
	g_game()->keys.arrow_right = 0;
	g_game()->keys.arrow_left = 0;	
	g_game()->keys.up = 0;	
	g_game()->keys.down = 0;
	g_game()->keys.right = 0;
	g_game()->keys.left = 0;
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
		g_game()->info.delta_x = fabs(1.0 / g_game()->info.raydirx);
		g_game()->info.delta_y = fabs(1.0 / g_game()->info.raydiry);
		// ("px => %f | py => %f | map_x => %d | map_y => %d | ray_angle => %f | angle_rad => %f | raydirx => %f | raydiry => %f \n",g_game()->info.px,g_game()->info.py,g_game()->info.mapX,g_game()->info.mapY,
		// 	g_game()->info.ray_angle,g_game()->info.angle_rad,g_game()->info.raydirx,g_game()->info.raydiry);
		cast_ray(i);
		i++;
	}
}
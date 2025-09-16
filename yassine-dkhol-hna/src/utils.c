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
	// if (!map)
	// 	return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || 
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

// void load_gun_texture()
// {
//     int bpp;
//     int size_line;
//     int endian;

//     g_game()->gun_img = mlx_xpm_file_to_image(g_game()->mlx, "textures/tile000.xpm", 
//                                              &g_game()->gun_width, &g_game()->gun_height);
//     if (!g_game()->gun_img)
//     {
//         printf("Error: Could not load gun texture\n");
//         exit(33);
//     }
//     g_game()->gun_pixels = (int *)mlx_get_data_addr(g_game()->gun_img, &bpp, &size_line, &endian);
//     g_game()->gun_scale = 2.0;
//     int scaled_width = g_game()->gun_width * g_game()->gun_scale;
//     int scaled_height = g_game()->gun_height * g_game()->gun_scale;
//     g_game()->gun_x = (WIDTH - scaled_width) / 2;
//     g_game()->gun_y = HEIGHT - scaled_height;
// }
void load_texture(t_texture *tex, char *path)
{
    int bpp;
	int size_line;
	int endian;

    if (!path)
        error("Error: texture path is NULL\n");
    tex->img = mlx_xpm_file_to_image(g_game()->mlx, path, &tex->width, &tex->height);
    if (!tex->img)
	{
        printf("Error: Failed to load texture: %s\n", path);
		gc_collect();
        exit(10);
	}
    tex->pixels = (int *)mlx_get_data_addr(tex->img, &bpp, &size_line, &endian);
}

void	draw_wall(int i)
{
	double drawStart;
	double drawEnd;
	double lineHeight;
	double perpDist;
	double angle_diff;
	double correctedDist;
	if (g_game()->info.side == 0)
		perpDist = (g_game()->info.sideDistx - g_game()->info.delta_x);
	else
		perpDist = (g_game()->info.sideDisty - g_game()->info.delta_y);
	angle_diff = (g_game()->info.ray_angle - g_game()->info.angle) * (M_PI / 180);
	correctedDist = perpDist * cos(angle_diff);
	lineHeight = HEIGHT / correctedDist;
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	drawEnd   =  lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0) drawStart = 0;
	if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
    int texNum;
    if (g_game()->info.side == 0)
    {
        if (g_game()->info.raydirx > 0)
            texNum = 2;
        else
            texNum = 3;
    }
    else
    {
        if (g_game()->info.raydiry > 0)
            texNum = 1;
        else
            texNum = 0;
    }

    t_texture *tex = &g_game()->textures[texNum];
    double wallX;
    if (g_game()->info.side == 0)
        wallX = g_game()->info.py + correctedDist * g_game()->info.raydiry;
    else
        wallX = g_game()->info.px + correctedDist * g_game()->info.raydirx;
    wallX -= floor(wallX);
    int texX = (int)(wallX * tex->width);
    // if ((g_game()->info.side == 0 && g_game()->info.raydirx > 0) ||
    //     (g_game()->info.side == 1 && g_game()->info.raydiry < 0))
    //     texX = tex->width - texX - 1;
    double step = tex->height / lineHeight;
    double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
	int y = drawStart;
	int k = drawEnd;
	int f = 0;
	while (y < drawEnd)
	{
        int texY = (int)texPos;
        if (texY < 0) texY = 0;
        if (texY >= tex->height) texY = tex->height - 1;
        texPos += step;

        unsigned int color = tex->pixels[texY * tex->width + texX];
        pixel_put(i, y, color);
		y++;
    }
	while (k < HEIGHT)
	{
        pixel_put(i, k, content()->floor_color);
		k++;
	}
	while (f < drawStart)
	{
        pixel_put(i, f, content()->ceiling_color);
		f++;	
	}
}

// void draw_gun()
// {
//     int orig_x, orig_y;
//     int screen_x, screen_y;
//     int color;

//     int scaled_width = g_game()->gun_width * g_game()->gun_scale;
//     int scaled_height = g_game()->gun_height * g_game()->gun_scale;
    
//     for (screen_y = 0; screen_y < scaled_height; screen_y++)
//     {
//         for (screen_x = 0; screen_x < scaled_width; screen_x++)
//         {
//             // Map screen coordinates back to original texture coordinates
//             orig_x = screen_x / g_game()->gun_scale;
//             orig_y = screen_y / g_game()->gun_scale;
            
//             // Make sure we don't go out of bounds
//             if (orig_x < g_game()->gun_width && orig_y < g_game()->gun_height)
//             {
//                 color = g_game()->gun_pixels[orig_y * g_game()->gun_width + orig_x];
//                 if ((color & 0x00FFFFFF) != 0)
//                 {
//                     int final_x = g_game()->gun_x + screen_x;
//                     int final_y = g_game()->gun_y + screen_y;
                    
//                     // Only draw if within screen bounds
//                     if (final_x >= 0 && final_x < WIDTH && final_y >= 0 && final_y < HEIGHT)
//                     {
//                         pixel_put(final_x, final_y, color);
//                     }
//                 }
//             }
//         }
//     }
// }


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

void draw_square(int x, int y, int color)
{
    int i, j;
    for (i = 0; i < MINIMAP_SCALE; i++)
    {
        for (j = 0; j < MINIMAP_SCALE; j++)
        {
            pixel_put(x + j, y + i, color);
        }
    }
}

// void draw_minimap()
// {
//     // Calculate map dimensions (if not already stored)
//     int map_height = 0;
//     int map_width = 0;
    
//     // Find map height by counting rows until NULL
//     while (map[map_height] != NULL)
//         map_height++;
    
//     // Find map width by checking length of first row
//     if (map_height > 0)
//         while (map[0][map_width] != '\0')
//             map_width++;

//     int player_map_x = (int)g_game()->info.px; // Player's current X cell
//     int player_map_y = (int)g_game()->info.py; // Player's current Y cell

//     // Calculate the starting and ending indices for the 3x3 area
//     int start_i = player_map_y - 1;
//     int end_i = player_map_y + 1;
//     int start_j = player_map_x - 1;
//     int end_j = player_map_x + 1;

//     // Ensure we don't go out of map bounds
//     if (start_i < 0) start_i = 0;
//     if (start_j < 0) start_j = 0;
//     if (end_i >= map_height) end_i = map_height - 1;
//     if (end_j >= map_width) end_j = map_width - 1;

//     // Draw only the 3x3 area around the player
//     for (int i = start_i; i <= end_i; i++)
//     {
//         for (int j = start_j; j <= end_j; j++)
//         {
//             if (i >= 0 && i < map_height && j >= 0 && j < map_width) // Double safety check
//             {
//                 if (map[i][j] == '1') 
//                     draw_square(j * MINIMAP_SCALE, i * MINIMAP_SCALE, 0xFFFFFF); // Wall
//                 else if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'E')
//                     draw_square(j * MINIMAP_SCALE, i * MINIMAP_SCALE, 0x000000); // Floor or player spawn
//             }
//         }
//     }

//     // Draw the player position (center of the minimap)
//     int px = (int)(g_game()->info.px * MINIMAP_SCALE);
//     int py = (int)(g_game()->info.py * MINIMAP_SCALE);
//     draw_square(px - MINIMAP_SCALE/2, py - MINIMAP_SCALE/2, 0xFF0000); // Player

//     // Optional: Draw player direction line
//     // int lineX = px + cos(g_game()->info.pa) * 15; // Use actual angle variable
//     // int lineY = py + sin(g_game()->info.pa) * 15;
//     // draw_line(px, py, lineX, lineY, 0xFF0000);
// }
void draw_minimap()
{
    int minimap_center_x = 100;
    int minimap_center_y = 100;
    int minimap_radius = 100;

    int map_height = 0;
    int map_width = 0;
    while (content()->map[map_height] != NULL)
        map_height++;
    if (map_height > 0)
        while (content()->map[0][map_width] != '\0')
            map_width++;

    double player_x = g_game()->info.px;
    double player_y = g_game()->info.py;

    double grid_radius = (double)minimap_radius / MINIMAP_SCALE;

    for (int map_y = player_y - grid_radius; map_y <= player_y + grid_radius; map_y++)
    {
        for (int map_x = player_x - grid_radius; map_x <= player_x + grid_radius; map_x++)
        {
            if (map_y >= 0 && map_y < map_height && map_x >= 0 && map_x < map_width)
            {
                int screen_x = minimap_center_x + (map_x - player_x) * MINIMAP_SCALE;
                int screen_y = minimap_center_y + (map_y - player_y) * MINIMAP_SCALE;

                 if (content()->map[map_y][map_x] == '1') 
                     draw_square(screen_x, screen_y, 0xFFFFFF);
                else if (content()->map[map_y][map_x] == '0' || content()->map[map_y][map_x] == 'N' || 
                        content()->map[map_y][map_x] == 'W' || content()->map[map_y][map_x] == 'S' || 
                        content()->map[map_y][map_x] == 'E')
                    draw_square(screen_x, screen_y, 0x000000);
            }
        }
    }
    draw_square(minimap_center_x - MINIMAP_SCALE/2, 
                minimap_center_y - MINIMAP_SCALE/2, 
                0xFF0000);

    // Draw player direction line (optional)
    // int lineX = minimap_center_x + cos(g_game()->info.px) * (minimap_radius * 0.8);
    // int lineY = minimap_center_y + sin(g_game()->info.py) * (minimap_radius * 0.8);
    // draw_line(minimap_center_x, minimap_center_y, lineX, lineY, 0xFF0000);

    // Draw minimap circle outline (optional)
    // draw_circle(minimap_center_x, minimap_center_y, minimap_radius, 0x00FF00);
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
	// load_gun_texture();
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

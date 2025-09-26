#include "../cub.h"

void	draw_gun_column(int screen_y, int scaled_width)
{
	int	screen_x;

	screen_x = 0;
	while (screen_x < scaled_width)
	{
		draw_gun_pixel(screen_x, screen_y);
		screen_x++;
	}
}

void	draw_gun(void)
{
	int	scaled_width;
	int	scaled_height;
	int	screen_y;

	scaled_width = g_game()->gun_width * g_game()->gun_scale;
	scaled_height = g_game()->gun_height * g_game()->gun_scale;
	screen_y = 0;
	while (screen_y < scaled_height)
	{
		draw_gun_column(screen_y, scaled_width);
		screen_y++;
	}
}

void	draw_gun_pixel(int screen_x, int screen_y)
{
	int	orig_x;
	int	orig_y;
	int	color;
	int	coords[2];

	orig_x = screen_x / g_game()->gun_scale;
	orig_y = screen_y / g_game()->gun_scale;
	if (orig_x < g_game()->gun_width && orig_y < g_game()->gun_height)
	{
		color = g_game()->gun_pixels[orig_y * g_game()->gun_width + orig_x];
		if ((color & 0x00FFFFFF) != 0)
		{
			coords[0] = g_game()->gun_x + screen_x;
			coords[1] = g_game()->gun_y + screen_y;
			if (coords[0] >= 0 && coords[0] < WIDTH && coords[1] >= 0 && coords[1] < HEIGHT)
			{
				pixel_put(coords[0], coords[1], color);
			}
		}
	}
}

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

#include "../cub.h"

void	get_map_size(int *height, int *width)
{
	*height = 0;
	*width = 0;
	while (content()->map[*height] != NULL)
		(*height)++;
	if (*height > 0)
		while (content()->map[0][*width] != '\0')
			(*width)++;
}

void	draw_minimap_cell(int map_x, int map_y, t_minimap *mini)
{
	int	screen_x;
	int	screen_y;

	if (map_y >= 0 && map_y < mini->map_height && map_x >= 0 && map_x < mini->map_width)
	{
		screen_x = mini->center_x + (map_x - mini->player_x) * MINIMAP_SCALE;
		screen_y = mini->center_y + (map_y - mini->player_y) * MINIMAP_SCALE;
		if (content()->map[map_y][map_x] == '1')
			draw_square(screen_x, screen_y, 0xFFFFFF);
		else if (content()->map[map_y][map_x] == '0' || content()->map[map_y][map_x] == 'N'
			|| content()->map[map_y][map_x] == 'W' || content()->map[map_y][map_x] == 'S'
			|| content()->map[map_y][map_x] == 'E' || content()->map[map_y][map_x] == ' ')
			draw_square(screen_x, screen_y, 0x000000);
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

void draw(int x,int start,int end,int color)
{
	while(start < end)
	{
		pixel_put(x,start,color);
		start++;
	}
}

void	draw_floor_ceiling(t_texture_params *params)
{
	double	k;
	double	f;

	k = params->draw_end;
	f = 0.0;
	while (k < HEIGHT)
	{
		pixel_put(params->i, k, content()->floor_color);
		k++;
	}
	while (f < params->draw_start)
	{
		pixel_put(params->i, f, content()->ceiling_color);
		f++;
	}
}

void	calculate_wall_x(double prep_dist, t_texture *tex, int *tex_x)
{
	double	wall_x;

	if (g_game()->info.side == 0)
		wall_x = g_game()->info.py + prep_dist * g_game()->info.raydiry;
	else
		wall_x = g_game()->info.px + prep_dist * g_game()->info.raydirx;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * tex->width);
}

int	ft_close(void)
{
	//NEED TO FREE DATA FIRST ABANA
	exit(1);
}
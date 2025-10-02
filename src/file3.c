#include "../cub.h"

void	add_textures(t_texture_params *params)
{
	int			tex_num;
	t_texture	*tex;
	int			tex_x;

	determine_texture(&tex_num);
	tex = &g_game()->textures[tex_num];
	calculate_wall_x(params->prep_dist, tex, &tex_x);
	draw_wall_texture(params, tex, tex_x);
	draw_floor_ceiling(params);
}

void	calculate_line_height(double *line_height, double *draw_start,
			double *draw_end)
{
	double	perp_dist;
	double	angle_diff;
	double	corrected_dist;

	if (g_game()->info.side == 0)
		perp_dist = (g_game()->info.sideDistx - g_game()->info.delta_x);
	else
		perp_dist = (g_game()->info.sideDisty - g_game()->info.delta_y);
	angle_diff = (g_game()->info.ray_angle - g_game()->info.angle)
		* (M_PI / 180);
	corrected_dist = perp_dist * cos(angle_diff);
	*line_height = HEIGHT / corrected_dist;
	*draw_start = -*line_height / 2 + HEIGHT / 2;
	*draw_end = *line_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

void	draw_wall(int i)
{
	double				line_height;
	double				draw_start;
	double				draw_end;
	t_texture_params	params;

	if (g_game()->info.side == 0)
		params.prep_dist = (g_game()->info.sideDistx - g_game()->info.delta_x);
	else
		params.prep_dist = (g_game()->info.sideDisty - g_game()->info.delta_y);
	calculate_line_height(&line_height, &draw_start, &draw_end);
	params.i = i;
	params.line_height = line_height;
	params.draw_start = draw_start;
	params.draw_end = draw_end;
	add_textures(&params);
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

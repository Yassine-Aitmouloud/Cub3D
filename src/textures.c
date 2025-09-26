#include "../cub.h"

void load_texture(t_texture *tex, char *path)
{
    int bpp;
	int size_line;
	int endian;

    if (!path)
        error("Error\ntexture path is NULL\n");
    tex->img = mlx_xpm_file_to_image(g_game()->mlx, path, &tex->width, &tex->height);
    if (!tex->img)
	{
        printf("Error\nFailed to load texture: %s\n", path);
		gc_collect();
        exit(10);
	}
    tex->pixels = (int *)mlx_get_data_addr(tex->img, &bpp, &size_line, &endian);
}

void	determine_texture(int *tex_num)
{
	if (g_game()->info.side == 0)
	{
		if (g_game()->info.raydirx > 0)
			*tex_num = 2;  // EAST
		else
			*tex_num = 3;  // WEST
	}
	else
	{
		if (g_game()->info.raydiry > 0)
			*tex_num = 1;  // SOUTH  
		else
			*tex_num = 0;  // NORTH
	}
}

void	draw_wall_texture(t_texture_params *params, t_texture *tex, int tex_x)
{
	double	tex_pos;
	double	y;
	double	step;
	int		tex_y;

	step = tex->height / params->line_height;
	tex_pos = 0.0;
	y = params->draw_start;
	if (tex_x < 0 || tex_x >= tex->width)
		return;
	while (y < params->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		tex_pos += step;
		pixel_put(params->i, y, tex->pixels[tex_y * tex->width + tex_x]);
		y++;
	}
}

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

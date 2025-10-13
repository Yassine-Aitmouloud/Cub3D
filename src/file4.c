/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:29:08 by anas              #+#    #+#             */
/*   Updated: 2025/10/03 15:43:18 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	load_texture(t_texture *tex, char *path)
{
	int	bpp;
	int	size_line;
	int	endian;

	if (!path)
		error("Error\ntexture path is NULL\n");
	tex->img = mlx_xpm_file_to_image(g_game()->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("Error\nFailed to load texture: %s\n", path);
		gc_collect();
		clear_mlx();
		exit(EXIT_FAILURE);
	}
	tex->pixels = (int *)mlx_get_data_addr(tex->img, &bpp, &size_line, &endian);
}

void	determine_texture(int *tex_num)
{
	if (g_game()->info.side == 0)
	{
		if (g_game()->info.raydirx > 0)
			*tex_num = 2;
		else
			*tex_num = 3;
	}
	else
	{
		if (g_game()->info.raydiry > 0)
			*tex_num = 1;
		else
			*tex_num = 0;
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
		return ;
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

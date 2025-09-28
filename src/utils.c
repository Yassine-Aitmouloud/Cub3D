/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:09:00 by aniki             #+#    #+#             */
/*   Updated: 2025/09/28 21:59:35 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_the_vue(char **map, int i, int j)
{
	if (!map)
		return (1);
	if (map[i][j] == 'S')
		return (g_game()->info.angle = 90);
	if (map[i][j] == 'N')
		return (g_game()->info.angle = 270, 0);
	if (map[i][j] == 'W')
		return (g_game()->info.angle = 180, 0);
	if (map[i][j] == 'E')
		return (g_game()->info.angle = 0, 0);
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
			if (map[i][j] == 'N' ||
						map[i][j] == 'W' || map[i][j] == 'S' ||
						map[i][j] == 'E')
			{
				get_the_vue(map, i, j);
				g_game()->info.px = j + 0.5;
				g_game()->info.py = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
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

void	cast_rays(void)
{
	// double	angle;
	int		i;

	i = 0;
	// angle = g_game()->info.angle - (g_game()->info.pov / 2);
	while (i < WIDTH)
	{
		g_game()->info.mapX = (int)g_game()->info.px;
		g_game()->info.mapY = (int)g_game()->info.py;
		g_game()->info.ray_angle = (g_game()->info.pov * i / WIDTH);
		g_game()->info.angle_rad = g_game()->info.ray_angle * (M_PI / 180);
		g_game()->info.raydirx = cos(g_game()->info.angle_rad);
		g_game()->info.raydiry = sin(g_game()->info.angle_rad);
		g_game()->info.delta_x = fabs(1.0 / g_game()->info.raydirx);
		g_game()->info.delta_y = fabs(1.0 / g_game()->info.raydiry);
		cast_ray(i);
		i++;
	}
}

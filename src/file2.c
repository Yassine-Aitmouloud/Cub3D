/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:28:59 by anas              #+#    #+#             */
/*   Updated: 2025/10/03 15:36:54 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h" 

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

void	side_step(void)
{
	if (g_game()->info.raydirx < 0)
	{
		g_game()->info.step_x = -1;
		g_game()->info.side_distx = (g_game()->info.px - g_game()->info.map_x
			) * g_game()->info.delta_x;
	}
	else
	{
		g_game()->info.step_x = 1;
		g_game()->info.side_distx = (g_game()->info
			.map_x + 1.0 - g_game()->info.px) * g_game()->info.delta_x;
	}
	if (g_game()->info.raydiry < 0)
	{
		g_game()->info.step_y = -1;
		g_game()->info.side_disty = (g_game()->info.py - g_game()->info.map_y
			) * g_game()->info.delta_y;
	}
	else
	{
		g_game()->info.step_y = 1;
		g_game()->info.side_disty = (g_game()->info
			.map_y + 1.0 - g_game()->info.py) * g_game()->info.delta_y;
	}
}

void	draw_square(int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			pixel_put(x + j, y + i, color);
			j++;
		}
		i++;
	}
}

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

	if (map_y >= 0 && map_y < mini->map_height
		&& map_x >= 0 && map_x < mini->map_width)
	{
		screen_x = mini->center_x + (map_x - mini->player_x) * MINIMAP_SCALE;
		screen_y = mini->center_y + (map_y - mini->player_y) * MINIMAP_SCALE;
		if (content()->map[map_y][map_x] == '1'
			|| content()->map[map_y][map_x] == 's')
			draw_square(screen_x, screen_y, 0xFFFFFF);
		else if (content()->map[map_y][map_x] == '0'
			|| content()->map[map_y][map_x] == 'N'
			|| content()->map[map_y][map_x] == 'W'
			|| content()->map[map_y][map_x] == 'S'
			|| content()->map[map_y][map_x] == 'E'
			|| content()->map[map_y][map_x] == ' ')
			draw_square(screen_x, screen_y, 0x000000);
	}
}

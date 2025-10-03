/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:30:59 by aniki             #+#    #+#             */
/*   Updated: 2025/10/03 17:31:43 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

int	redraw(void)
{
	if (g_game()->keys.needs_redraw || g_game()->keys.mouse_moved)
	{
		mlx_clear_window(g_game()->mlx, g_game()->win);
		cast_rays();
		mlx_put_image_to_window(g_game()->mlx,
			g_game()->win, g_game()->img, 0, 0);
		draw_minimap();
		draw_gun();
		g_game()->keys.needs_redraw = 0;
		g_game()->keys.mouse_moved = 0;
	}
	return (0);
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	gc_collect();
	exit(EXIT_FAILURE);
}

int	ft_close(void)
{
	exit(1);
}

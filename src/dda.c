/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:34:38 by aniki             #+#    #+#             */
/*   Updated: 2025/09/26 20:36:02 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	step_ray_x(void)
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

void	step_ray_y(void)
{
	g_game()->info.side = 1;
	if (content()->map[g_game()->info.mapY][g_game()->info.mapX] == '1')
		g_game()->info.hit = 1;
	else
	{
		g_game()->info.mapY += g_game()->info.step_y;
		g_game()->info.sideDisty += g_game()->info.delta_y;
	}
}

void	cast_ray(int i)
{
	g_game()->info.hit = 0;
	g_game()->info.side = -1;
	side_step();
	while (g_game()->info.hit != 1)
	{
		if (g_game()->info.sideDistx < g_game()->info.sideDisty)
			step_ray_x();
		else
			step_ray_y();
		if (g_game()->info.mapY < 0 || g_game()->info.mapX < 0)
			g_game()->info.hit = 1;
		if (content()->map[g_game()->info.mapY][g_game()->info.mapX] == '1')
			g_game()->info.hit = 1;
	}
	draw_wall(i);
}

void	side_step(void)
{
	if (g_game()->info.raydirx < 0)
	{
		g_game()->info.step_x = -1;
		g_game()->info.sideDistx = (g_game()->info.px - g_game()->info.mapX
			) * g_game()->info.delta_x;
	}
	else
	{
		g_game()->info.step_x = 1;
		g_game()->info.sideDistx = (g_game()->info
			.mapX + 1.0 - g_game()->info.px) * g_game()->info.delta_x;
	}
	if (g_game()->info.raydiry < 0)
	{
		g_game()->info.step_y = -1;
		g_game()->info.sideDisty = (g_game()->info.py - g_game()->info.mapY
			) * g_game()->info.delta_y;
	}
	else
	{
		g_game()->info.step_y = 1;
		g_game()->info.sideDisty = (g_game()->info
			.mapY + 1.0 - g_game()->info.py) * g_game()->info.delta_y;
	}
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	gc_collect();
	exit(EXIT_FAILURE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:41:53 by aniki             #+#    #+#             */
/*   Updated: 2025/10/03 15:50:17 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	moves(void)
{
	if (g_game()->keys.up)
		ft_up();
	if (g_game()->keys.down)
		ft_down();
	if (g_game()->keys.right)
		ft_right();
	if (g_game()->keys.left)
		ft_left();
	if (g_game()->keys.arrow_left)
	{
		g_game()->info.angle -= 3;
		mlx_clear_window(g_game()->mlx, g_game()->win);
		cast_rays();
		mlx_put_image_to_window(g_game()->mlx,
			g_game()->win, g_game()->img, 0, 0);
	}
	if (g_game()->keys.arrow_right)
	{
		g_game()->info.angle += 3;
		mlx_clear_window(g_game()->mlx, g_game()->win);
		cast_rays();
		mlx_put_image_to_window(g_game()->mlx, g_game()->win,
			g_game()->img, 0, 0);
	}
	draw_minimap();
	draw_gun();
	return (0);
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

void	ft_up(void)
{
	double (nextx) = g_game()->info.px;
	double (nexty) = g_game()->info.py;
	double (moveSpeed) = 0.3;
	double (rad) = g_game()->info.angle * M_PI / 180;
	nextx += cos(rad) * moveSpeed;
	nexty += sin(rad) * moveSpeed;
	if (!is_wall(nextx, g_game()->info.py))
		g_game()->info.px = nextx;
	if (!is_wall(g_game()->info.px, nexty))
		g_game()->info.py = nexty;
	g_game()->keys.needs_redraw = 1;
	redraw();
}

void	ft_down(void)
{
	double (nextx) = g_game()->info.px;
	double (nexty) = g_game()->info.py;
	double (moveSpeed) = 0.3;
	double (rad) = g_game()->info.angle * M_PI / 180;
	nextx -= cos(rad) * moveSpeed;
	nexty -= sin(rad) * moveSpeed;
	if (!is_wall(nextx, g_game()->info.py))
		g_game()->info.px = nextx;
	if (!is_wall(g_game()->info.px, nexty))
		g_game()->info.py = nexty;
	g_game()->keys.needs_redraw = 1;
	redraw();
}

void	ft_right(void)
{
	double (nextx) = g_game()->info.px;
	double (nexty) = g_game()->info.py;
	double (moveSpeed) = 0.3;
	double (rad) = (g_game()->info.angle + 90) * M_PI / 180;
	nextx += cos(rad) * moveSpeed;
	nexty += sin(rad) * moveSpeed;
	if (!is_wall(nextx, g_game()->info.py))
		g_game()->info.px = nextx;
	if (!is_wall(g_game()->info.px, nexty))
		g_game()->info.py = nexty;
	g_game()->keys.needs_redraw = 1;
	redraw();
}

void	ft_left(void)
{
	double (nextx) = g_game()->info.px;
	double (nexty) = g_game()->info.py;
	double (moveSpeed) = 0.3;
	double (rad) = (g_game()->info.angle + 90) * M_PI / 180;
	nextx -= cos(rad) * moveSpeed;
	nexty -= sin(rad) * moveSpeed;
	if (!is_wall(nextx, g_game()->info.py))
		g_game()->info.px = nextx;
	if (!is_wall(g_game()->info.px, nexty))
		g_game()->info.py = nexty;
	g_game()->keys.needs_redraw = 1;
	redraw();
}

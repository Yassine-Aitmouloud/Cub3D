/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:53:30 by aniki             #+#    #+#             */
/*   Updated: 2025/09/26 21:21:52 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_wall(double x, double y)
{
	int		map_x;
	int		map_y;

	double (radius) = 0.3;
	map_x = (int)(x - radius);
	map_y = (int)(y - radius);
	if (map_y < 0 || map_x < 0 || !content()->map[map_y]
		|| !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + radius);
	map_y = (int)(y - radius);
	if (map_y < 0 || map_x < 0 || !content()->map[map_y]
		|| !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x - radius);
	map_y = (int)(y + radius);
	if (map_y < 0 || map_x < 0 || !content()->map[map_y]
		|| !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + radius);
	map_y = (int)(y + radius);
	if (map_y < 0 || map_x < 0 || !content()->map[map_y]
		|| !content()->map[map_y][map_x] || content()->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	pixel_put(int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = g_game()->addr + (y * g_game()->line_length + x
			* (g_game()->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_pressed(int key)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_UP)
		g_game()->keys.up = 1;
	if (key == KEY_DOWN)
		g_game()->keys.down = 1;
	if (key == KEY_RIGHT)
		g_game()->keys.right = 1;
	if (key == KEY_LEFT)
		g_game()->keys.left = 1;
	if (key == CAMERA_R)
		g_game()->keys.arrow_right = 1;
	if (key == CAMERA_L)
		g_game()->keys.arrow_left = 1;
	return (0);
}

int	key_unpressed(int key)
{
	if (key == KEY_UP)
		g_game()->keys.up = 0;
	if (key == KEY_DOWN)
		g_game()->keys.down = 0;
	if (key == KEY_RIGHT)
		g_game()->keys.right = 0;
	if (key == KEY_LEFT)
		g_game()->keys.left = 0;
	if (key == CAMERA_R)
		g_game()->keys.arrow_right = 0;
	if (key == CAMERA_L)
		g_game()->keys.arrow_left = 0;
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("[usage]: ./cub3D {file.cub}\n");
		return (1);
	}
	if (check_file(av[1]) == 0)
		error("Error\nInvalid file name or content\n");
	if (valid_map(av[1]) == 0 || valid_h_w_walls() == 0)
		error("Error\nInvalid Map\n");
	game_init();
	prepare_data();
	cast_rays();
	moves();
	mlx_hook (g_game()->win, CROSS, 0, ft_close, NULL);
	mlx_hook (g_game()->win, 2, 1L << 0, key_pressed, NULL);
	mlx_hook (g_game()->win, 3, 1L << 1, key_unpressed, NULL);
	mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->img, 0, 0);
	mlx_loop_hook(g_game()->mlx, moves, NULL);
	mlx_loop(g_game()->mlx);
	gc_collect();
	return (0);
}

#include "../cub.h"

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	gc_collect();
	exit(EXIT_FAILURE);
}

int	is_wall(double x, double y)
{
	int		map_x;
	int		map_y;

	double (radius) = 0.1;
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

int	ft_close(void)
{
	exit(175);
}

void	pixel_put(int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = g_game()->addr + (y * g_game()->line_length + x * (g_game()->bits_per_pixel / 8));
	*(unsigned int*) dst = color;
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

int mouse_move(int x)
{
	static int  (last_x) = -1;
	double 		sensitivity;
	int 		delta_x;

	sensitivity = 0.3;
	mlx_mouse_hide(g_game()->mlx, g_game()->win);
	if (last_x == -1)
		last_x = x;	
	delta_x = x - last_x;
	last_x = x;
	if (abs(delta_x) < 2)
	    return (0);
	if (abs(delta_x) > 10)
	    sensitivity = 0.6;
	g_game()->info.angle += (delta_x * sensitivity);
	g_game()->keys.mouse_moved = 1;
	g_game()->keys.needs_redraw = 1;
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
	mlx_hook(g_game()->win, CROSS, 0, ft_close, NULL);
	// mlx_hook(g_game()->win, 6, 1L << 6, mouse_move, NULL);
	mlx_hook(g_game()->win, 2, 1L << 0, key_pressed, NULL);
	mlx_hook(g_game()->win, 3, 1L << 1, key_unpressed, NULL);
	mlx_put_image_to_window(g_game()->mlx, g_game()->win, g_game()->img, 0, 0);
	mlx_loop_hook(g_game()->mlx, moves, NULL);
	mlx_loop(g_game()->mlx);
	gc_collect();
	return (0);
}

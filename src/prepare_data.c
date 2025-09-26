/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:50:15 by aniki             #+#    #+#             */
/*   Updated: 2025/09/26 21:22:56 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_content	*content(void)
{
	static t_content	c;

	return (&c);
}

t_parse	*parse(void)
{
	static t_parse	c;

	return (&c);
}

t_cup	*g_game(void)
{
	static t_cup	infos;

	return (&infos);
}

void	game_init(void)
{
	g_game()->mlx = mlx_init();
	g_game()->win = mlx_new_window(g_game()->mlx, WIDTH, HEIGHT, "GO GO GO");
	g_game()->img = mlx_new_image(g_game()->mlx, WIDTH, HEIGHT);
	g_game()->addr = mlx_get_data_addr(g_game()->img, &g_game()->bits_per_pixel,
		&g_game()->line_length, &g_game()->endian);
}

void	prepare_data(void)
{
	load_texture(&g_game()->textures[0], content()->no_texture);
	load_texture(&g_game()->textures[1], content()->so_texture);
	load_texture(&g_game()->textures[2], content()->ea_texture);
	load_texture(&g_game()->textures[3], content()->we_texture);
	load_gun_texture();
	find_player_position(content()->map);
	g_game()->info.pov = 60.0;
	g_game()->info.step_x = 1;
	g_game()->info.step_y = 1;
	g_game()->keys.arrow_right = 0;
	g_game()->keys.arrow_left = 0;
	g_game()->keys.up = 0;
	g_game()->keys.down = 0;
	g_game()->keys.right = 0;
	g_game()->keys.left = 0;
}

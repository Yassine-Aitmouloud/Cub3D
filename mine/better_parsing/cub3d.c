/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:07:29 by abenba            #+#    #+#             */
/*   Updated: 2025/08/03 14:52:33 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_content *content()
{
	static t_content c;
	return (&c);
}
t_parse *parse()
{
	static t_parse c;
	return (&c);
}

void	error(char *msg)
{
	write (2, msg, ft_strlen(msg));
	gc_collect();
	exit (EXIT_FAILURE);
}

void print_content()
{
	int (i) = 0;
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", content()->no_texture, content()->so_texture, content()->we_texture, content()->ea_texture);
	printf("red: %d\ngreen: %d\nblue: %d\n", content()->red, content()->green, content()->blue);
	printf("ceiling_color: %d\nfloor_color: %d\n", content()->ceiling_color, content()->floor_color);
	printf("map_height: %d\nmap_width: %d\n", content()->map_height, content()->map_width);
	while (content()->map[i])
	{
		printf("%s\n", content()->map[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	if (ac != 2)
	{
		printf("[usage]: ./cub3D {file.cub}\n");
		return (1);
	}
	if (check_file(av[1]) == 0)
		error("Error\nInvalid file name or content\n");
	if (valid_map(av[1]) == 0 || valid_H_W_walls() == 0)
		error("Error\nInvalid Map\n");
	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window(mlx, 2560, 1440, "Cub3D");
	if (!mlx_win)
		return (0);
	mlx_loop(mlx);
	print_content();
	gc_collect();
}
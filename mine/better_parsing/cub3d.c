/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:07:29 by abenba            #+#    #+#             */
/*   Updated: 2025/07/26 11:41:22 by abenba           ###   ########.fr       */
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
	exit (EXIT_FAILURE);
}

void print_content()
{
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", content()->no_texture, content()->so_texture, content()->we_texture, content()->ea_texture);
	printf("red: %d\ngreen: %d\nblue: %d\n", content()->red, content()->green, content()->blue);
	printf("ceiling_color: %d\nfloor_color: %d\n", content()->ceiling_color, content()->floor_color);
	printf("map_height: %d\nmap_width: %d\n", content()->map_height, content()->map_width);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("[usage]: ./cub3D {file.cub}\n");
		return (1);
	}
	if (check_file(av[1]) == 0)
		error("Error\nInvalid file name or content\n");
	if (valid_map(av[1]) == 0)
		error("Error\nInvalid Map\n");
	print_content();
	gc_collect();
}
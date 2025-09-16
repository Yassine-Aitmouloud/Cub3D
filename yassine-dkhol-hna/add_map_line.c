/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:24:05 by abenba            #+#    #+#             */
/*   Updated: 2025/09/16 19:42:25 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	add_line(char *line)
{
	int	y;
	int	line_len;

	static int (i) = 1;
	int (j) = 1;
	y = 0;
	line_len = ft_strlen(line);
	while (j < line_len + 1)
	{
		content()->map[i][j] = line[y];
		j++;
		y++;
	}
	i++;
}

int	process_line(char *line)
{
	if (valid_map_line(line) == 0)
		return (0);
	add_line(line);
	return (1);
}

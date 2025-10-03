/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:09 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:10:18 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	valid_map_line(char *line)
{
	int (i) = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}

int	valid(char *line, int *i)
{
	char	*tmp;
	int		key;

	tmp = ft_strtrim(line, " \n");
	key = add_key(tmp);
	if (key == 0)
	{
		line = ft_strtrim(line, "\n");
		content()->map[(*i)] = gc_malloc((content()->map_width + 3)
			* sizeof(char));
		if (!content()->map[(*i)])
			return (0);
		ft_memset(content()->map[(*i)], 32, (content()->map_width + 3)
			* sizeof(char));
		content()->map[(*i)][content()->map_width + 2] = '\0';
		if (process_line(line) == 0)
			return (0);
		(*i)++;
	}
	return (1);
}

int	valid_map(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1 || !init_map())
		return (0);
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		if (empty_line(line) == 0)
		{
			if (valid(line, &i) == 0)
				return (0);
		}
		line = get_next_line(fd);
	}
	content()->map[i] = gc_malloc((content()->map_width + 3) * sizeof(char));
	if (!content()->map[i])
		return (0);
	ft_memset(content()->map[i], 32, (content()->map_width + 3) * sizeof(char));
	content()->map[i][content()->map_width + 2] = '\0';
	return (1);
}

int	valid_h_w_walls(void)
{
	if (content()->map_height <= 2 || content()->map_width <= 2)
		return (0);
	if (player_number() == 0)
		return (0);
	if (change_space(0, 0, content()->map_height + 2, content()->map_width
			+ 2) == 0)
		return (0);
	if (closed() == 0)
		return (0);
	return (1);
}

int	player_number(void)
{
	int (i) = 0;
	int (y);
	int (player) = 0;
	while (content()->map[i])
	{
		y = 0;
		while (content()->map[i][y])
		{
			if (content()->map[i][y] != '1' && content()->map[i][y] != '0'
				&& content()->map[i][y] != ' ')
				player++;
			y++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:13:04 by abenba            #+#    #+#             */
/*   Updated: 2025/09/16 19:42:43 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	empty_line(char *line)
{
	int (i) = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	number_of_content(void)
{
	int (a) = parse()->no + parse()->so + parse()->we;
	int (b) = parse()->ea + parse()->c + parse()->f;
	return (a + b);
}

int	texturs_or_colors(int key, char *tmp)
{
	if (key == 1 && parse()->map_flag == 0)
	{
		if (check_texturs(tmp) == 0)
			return (0);
	}
	else if (key == 2 && parse()->map_flag == 0)
	{
		if (check_colors(tmp) == 0)
			return (0);
	}
	return (1);
}

int	map_lines(char *line)
{
	if (number_of_content() != 6)
		return (0);
	if (empty_line(line) == 1)
		parse()->map_end = 1;
	else if (parse()->map_end == 0)
	{
		parse()->map_flag = 1;
		content()->map_height++;
		line = ft_strtrim(line, "\n");
		if ((size_t)content()->map_width < ft_strlen(line))
			content()->map_width = ft_strlen(line);
	}
	else
		return (0);
	return (1);
}

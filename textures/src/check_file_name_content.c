/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:41:01 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:10:05 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	valid_name(char *file, char *extention)
{
	int		i;
	char	*ext;

	i = 0;
	while (file[i])
		i++;
	if (i <= 4)
		return (0);
	i -= 5;
	ext = ft_substr(file, i + 1, ft_strlen(file));
	if (ft_strcmp(ext, extention) != 0)
	{
		return (0);
	}
	if (file[i] == '/' || file[i] == ' ')
	{
		return (0);
	}
	return (1);
}

int	add_key(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
	{
		parse()->tex_num++;
		return (1);
	}
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		parse()->colors_num++;
		return (2);
	}
	else if (ft_strchr(" 01NEWS", line[0]))
		return (0);
	else
		return (3);
}

int	for_norm(int key, char *tmp, char *line)
{
	if (texturs_or_colors(key, tmp) == 0)
		return (0);
	else if (key == 0)
	{
		if (map_lines(line) == 0)
			return (0);
	}
	else if (key == 3)
		return (0);
	return (1);
}

int	valid_content(int fd)
{
	char	*line;
	int		key;
	char	*tmp;

	tmp = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (empty_line(line) == 1 && parse()->map_flag == 0)
		{
			line = get_next_line(fd);
			continue ;
		}
		else
		{
			tmp = ft_strtrim(line, " \n");
			key = add_key(tmp);
			if (for_norm(key, tmp, line) == 0)
				return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}

int	check_file(char *file)
{
	int	fd;

	if (valid_name(file, ".cub") == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (valid_content(fd) == 0)
		return (0);
	close(fd);
	return (1);
}

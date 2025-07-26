/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:13:04 by abenba            #+#    #+#             */
/*   Updated: 2025/07/26 11:39:15 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_name(char *file , char *extention)
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

int add_key(char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0
        || ft_strncmp(line, "SO ", 3) == 0
        || ft_strncmp(line, "WE ", 3) == 0
        || ft_strncmp(line, "EA ", 3) == 0)
    {
        parse()->tex_num++;
        return (1);
    }
    else if (ft_strncmp(line, "F ", 2) == 0
        || ft_strncmp(line, "C ", 2) == 0)
    {
        parse()->colors_num++;
        return (2);
    }
    else if (ft_strchr(" 01NEWS", line[0]))
        return (0);
    else
        return (3);
}

int empty_line(char *line)
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

int number_of_content()
{
    int (a) = parse()->no + parse()->so + parse()->we;
    int (b) = parse()->ea + parse()->c + parse()->f;
    return(a + b);
}

int valid_content(char *file)
{
    int fd;
    char *line;
    int key;
    char *tmp;

    tmp = NULL;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
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
            else if (key == 0)
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
            }
            else if (key == 3)
		        return (0);
        }
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}

int check_file(char *file)
{
    if (valid_name(file, ".cub") == 0)
        return (0);
    if (valid_content(file) == 0)   
        return (0);
    return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:30:16 by abenba            #+#    #+#             */
/*   Updated: 2025/07/22 11:20:34 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int fill_up_and_down()
{
    content()->map[0] = ft_calloc(content()->map_width + 3, sizeof(char));
    if (!content()->map[0])
        return (1);
    content()->map[content()->map_height + 1] = ft_calloc(content()->map_width + 3, sizeof(char));
    if (!content()->map[content()->map_height + 1])
        return (1);
    content()->map[0][content()->map_width + 2] = '\0';
    content()->map[content()->map_height + 1][content()->map_width + 2] = '\0';
    content()->map[content()->map_height + 2] = NULL;
    return (0);
}

void add_line(char *line, int *i)
{
    int (j) = 0;
    int (line_len) = ft_strlen(line);
    while (j < content()->map_width)
    {
        if (j < line_len && line[j])
        {
            if (line[j] == ' ')
                content()->map[(*i)][j] = '1';
            else
                content()->map[(*i)][j] = line[j];
        }
        j++;
    }
    // content()->map[(*i)][y] = 'K';
}

int parse_map(int fd)
{
    (void) fd;
    char (*line) = get_next_line(fd);
    int (key) = 0;
    int (i) = 1;
    content()->map = gc_malloc(sizeof(char *) * (content()->map_height + 1));
    if (!content()->map)
        return (1);
    content()->map[content()->map_height] = NULL;
    content()->map_flag = 0;
    content()->invalid = 0;
    if (!content()->map)
        return (1);
    // if (fill_up_and_down() == 1)
    //     return (1);
    while (line)
    {
        line[ft_strlen(line) - 1] = '\0';
        if (ft_empty_line(line, 'N') && content()->map_flag == 0)
		{
			line = get_next_line(fd);
			continue;
		}
        key = add_key(line);
        if (key == 0)
        {
            if (ft_empty_line(line, 'M'))
                content()->invalid = 1;
            else if (content()->invalid == 0)
            {
                content()->map_flag = 1;
                content()->map[i] = gc_malloc(content()->map_width + 1);
                if (!content()->map[i])
                    return (1);
                content()->map[i][content()->map_width] = '\0';
                add_line(line, &i);
            }
            if (!ft_empty_line(line, 'M') && content()->invalid == 1)
                return (1);
            i++;
        }
        else if (key == 3)
            return (1);
        line = get_next_line(fd);
    }
    return (0);
}
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
    content()->map[0] = ft_calloc(content()->map_width + 1, sizeof(char));
    if (!content()->map[0])
        return (1);
    content()->map[content()->map_height + 1] = ft_calloc(content()->map_width + 1, sizeof(char));
    if (!content()->map[content()->map_height + 1])
        return (1);
    content()->map[0][content()->map_width] = '\0';
    content()->map[content()->map_height + 1][content()->map_width] = '\0';
    content()->map[content()->map_height + 2] = NULL;
    return (0);
}

void add_line(char *line, int *i)
{
    int (j) = 0;
    int (line_len) = ft_strlen(line);
    while (j < content()->map_width)
    {
        if (j < line_len && ft_strchr(" NSEW10", line[j]))
            content()->map[(*i)][j] = line[j];
        j++;
    }
}

int parse_map(int fd)
{
    (void) fd;
    char (*line) = get_next_line(fd);
    int (key) = 0;
    int (i) = 1;
    content()->map = gc_malloc(sizeof(char *) * (content()->map_height + 3));
    if (!content()->map)
        return (1);
    if (fill_up_and_down() == 1)
        return (1);
    while (line)
    {
        key = add_key(line);
        if (key == 0)
        {
            content()->map[i] = ft_calloc(content()->map_width + 1 , sizeof(char));
            content()->map[i][content()->map_width] = '\0';
            if (!content()->map[i])
                return (1);
            add_line(line, &i);
            i++;
        }
        else if (key == 3)
            return (1);
        line = get_next_line(fd);
    }
    return (0);
}
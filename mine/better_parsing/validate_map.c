/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:09 by abenba            #+#    #+#             */
/*   Updated: 2025/07/26 12:00:09 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_map_line(char *line)
{
    int (i) = 0;
    while (line[i])
    {
        if (line)
    }
}

int add_line(char *line)
{
    if (valid_map_line(line) == 0)
        return (0);
}

int valid_map(char *file)
{
    int (key) = 0;
    int (fd) = open(file, O_RDONLY);
    char **l;
    int i;
    if (fd == -1)
        return (0);
    char (*line) = get_next_line(fd);
    l = gc_malloc((content()->map_height + 1) * sizeof(char *));
    if (!l)
        return (0);
    l[content()->map_height] = NULL;
    i = 0;
    while (line)
    {
        key = add_key(line);
        line = ft_strtrim(line, "\n");
        if (key == 0)
        {
            l[i] = ft_calloc(content()->map_width + 1, sizeof(char));
            if (!l[i])
                return (0);
            l[i][content()->map_width] = '\0';
            if (add_line(line) == 0)
                return (0);
            i++;
        }
        line = get_next_line(fd);
    }
    return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:09 by abenba            #+#    #+#             */
/*   Updated: 2025/07/27 15:15:01 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_map_line(char *line)
{
    int (i) = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '1'
            && line[i] != '0' && line[i] != 'N'
            && line[i] != 'S' && line[i] != 'W'
            && line[i] != 'E')
            return (0);
        i++;
    }
    return (1);
}

void add_line(char *line)
{
    static int (i) = 0;
    int (y) = 0;
    int (j) = 0;
    while (content()->map[i][j])
    {
        if (line[y] == ' ')
            content()->map[i][j] = '1';
        else
            content()->map[i][j] = line[y]; 
        y++;
        j++;
    }
    i++;
}

int process_line(char *line)
{
    if (valid_map_line(line) == 0)
        return (0);
    add_line(line);
    return (1);
}

int valid_map(char *file)
{
    int (key) = 0;
    int (fd) = open(file, O_RDONLY);
    int i;
    if (fd == -1)
        return (0);
    char (*line) = get_next_line(fd);
    char *tmp = NULL;
    content()->map = gc_malloc((content()->map_height + 1) * sizeof(char *));
    if (!content()->map)
        return (0);
    content()->map[content()->map_height] = NULL;
    i = 0;
    while (line)
    {
        if (empty_line(line) == 0)
        {
            tmp = ft_strtrim(line, " \n");
            key = add_key(tmp);
            if (key == 0)
            {
                line = ft_strtrim(line, "\n");
                content()->map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
                if (!content()->map[i])
                    return (0);
                content()->map[i][ft_strlen(line)] = '\0';
                if (process_line(line) == 0)
                    return (0);
                i++;
            }
        }
        line = get_next_line(fd);
    }
    return (1);
}

int wall_up_down()
{
    int (i) = 0;
    while (content()->map[0][i])
    {
        if (content()->map[0][i] != '1')
            return (0);  
        i++;
    }
    i = 0;
    while (content()->map[content()->map_height - 1][i])
    {
        if (content()->map[content()->map_height - 1][i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int wall_left_right()
{
    int line_len;
    
    int (i) = 1;
    while (i < content()->map_height - 1)
    {
        line_len = ft_strlen(content()->map[i]);
        if (content()->map[i][0] != '1'
            || content()->map[i][line_len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int valid_H_W_walls()
{
    if (content()->map_height <= 2
        || content()->map_width <= 2)
        return (0);
    if (wall_up_down() == 0)
        return (0);
    if (wall_left_right() == 0)
        return (0);
    return (1);
}

int player_number()
{
    int (i) = 0;
    int (y);
    int (player) = 0;
    while (content()->map[i])
    {
        y = 0;
        while (content()->map[i][y])
        {
            if (content()->map[i][y] != '1'
                && content()->map[i][y] != '0'
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

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

void fill_up_and_down()
{
    int (i) = 0;
    content()->map[0] = malloc(content()->map_width + 1);
    content()->map[content()->map_height + 1] = malloc(content()->map_width + 1);
    while ( i < content()->map_width)
    {
        content()->map[0][i] = 'k';
        content()->map[content()->map_height + 1][i] = 'k';
        i++;
    }
    content()->map[0][i] = '\0';
    content()->map[content()->map_height][i] = '\0';
}

// void fill_with_k(char *line, int *i)
// {
//     int (y) = 0;
//     while (y < content()->map_width)
//     {
//         if (!ft_strchr(" 01NSEW", line))
//         content()->map[(*i)][y] = 'k';
//     }
// }

int parse_map(int fd)
{
    char (*line) = get_next_line(fd);
    int (key) = 0;
    int (i) = 1;
    content()->map = malloc(sizeof(char *) * (content()->map_height + 3));
    fill_up_and_down();
    while (line)
    {
        key = add_key(line);
        if (key == 0)
        {
            content()->map[i] = ft_calloc(sizeof(char), content()->map_width + 1);
            content()->map[i][content()->map_width] = '\0';
            // fill_with_k(line, &i);
            i++;
        }
        line = get_next_line(fd);
    }
}
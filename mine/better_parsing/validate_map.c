/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:48:09 by abenba            #+#    #+#             */
/*   Updated: 2025/07/30 17:06:30 by anas             ###   ########.fr       */
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

int check_space_inside(int i, int j)
{
	int y = j;
	int k = i;
	int flag  = 0;
	while (content()->map[i][y])
	{
		if (content()->map[i][y] == '0'
			|| content()->map[i][y] == 'W'
			|| content()->map[i][y] == 'N'
			|| content()->map[i][y] == 'S'
			|| content()->map[i][y] == 'E')
			{
				flag += 1;
				break ;
			}
		else if (content()->map[i][y] == '1')
		{
			if (content()->map[i][y + 1] == '\0')
			{
				flag += 1;
				break;
			}
		}
		y++;
	}
	y = j;
	while (y > 0)
	{
		if (content()->map[i][y] == '0'
			|| content()->map[i][y] == 'W'
			|| content()->map[i][y] == 'N'
			|| content()->map[i][y] == 'S'
			|| content()->map[i][y] == 'E')
			{
				flag += 1;
				break ;
			}
		else if (content()->map[i][y] == '1')
		{
			if (content()->map[i][y + 1] == '\0')
			{
				flag += 1;
				break;
			}
		}
		y--;
	}
	y = j;
	while (content()->map[k][y])
	{
		if (content()->map[k][y] == '0'
			|| content()->map[k][y] == 'W'
			|| content()->map[k][y] == 'N'
			|| content()->map[k][y] == 'S'
			|| content()->map[k][y] == 'E')
			{
				flag += 1;
				break ;
			}
		else if (content()->map[k][y] == '1')
		{
			if (content()->map[k][y + 1] == '\0')
			{
				flag += 1;
				break;
			}
		}
		k++;
	}
	k = i;
	while (k > 0)
	{
		if (content()->map[k][y] == '0'
			|| content()->map[k][y] == 'W'
			|| content()->map[k][y] == 'N'
			|| content()->map[k][y] == 'S'
			|| content()->map[k][y] == 'E')
			{
				flag += 1;
				break ;
			}
		else if (content()->map[k][y] == '1')
		{
			if (content()->map[k][y + 1] == '\0')
			{
				flag += 1;
				break;
			}
		}
		k--;
	}
	if (flag == 4)
		return (0);
	return (1);
}

int init_queue(t_queue *q, int capacity)
{
	q->data = gc_malloc(capacity * sizeof(t_point));
	if (!q->data)
		return (0);
	q->front = 0;
	q->back = -1;
	q->capacity = capacity;
	return (1);
}

void add_in_queue(t_queue *q, t_point point)
{
	if (q->back == q->capacity - 1)
		return ;
	q->data[++q->back] = point;
}

t_point out_of_queue(t_queue *q)
{
	return (q->data[q->front++]);
}

int is_empty(t_queue *q)
{
	return (q->front > q->back);
}

int change_space(int X, int Y, int height, int width)
{
    const t_point directions[] =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    t_point point;
    t_point curr;
    int i = 0;
    int sx;
    int sy;
    char c;
    point.x = X;
    point.y = Y;
    t_queue q;
    bool **visited = gc_malloc(sizeof(bool*) * (height));
    if (!visited)
        return (0);
    while (i < (height))
    {
        visited[i] = ft_calloc_algo(width, sizeof(bool));
        if (!visited[i])
            return (0);
        i++;
    }
    if (init_queue(&q, (height * width)) == 0)
        return (0);
    add_in_queue(&q, point);
    visited[X][Y] = true;
    
    while (!is_empty(&q))
    {
        curr = out_of_queue(&q);
        if (content()->map[curr.x][curr.y] == ' ')
            content()->map[curr.x][curr.y] = 's';
        
        i = 0;
        while (i < 4)
        {
            sx = curr.x + directions[i].x;
            sy = curr.y + directions[i].y;
            if (sx >= 0 && sx < height && sy >= 0 && sy < width)
            {
                c = content()->map[sx][sy];
                if (!visited[sx][sy] && c != '1' && c != '0' && 
                    c != 'N' && c != 'E' && c != 'W' && c != 'S')
                {
                    visited[sx][sy] = true;
                    point.x = sx;
                    point.y = sy;
                    add_in_queue(&q, point);
                }
            }
            i++;
        }
    }
    return (1);
}

void add_line(char *line)
{
	static int (i) = 1;
	int (j) = 1;
	int y = 0;
	int line_len = ft_strlen(line);
	while (j < line_len + 1)
	{
		content()->map[i][j] = line[y];
		j++;
		y++;
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
	content()->map = gc_malloc((content()->map_height + 3) * sizeof(char *));
	if (!content()->map)
		return (0);
	content()->map[content()->map_height + 2] = NULL;
	content()->map[0] = ft_calloc(content()->map_width + 3, sizeof(char));
	content()->map[0][content()->map_width + 2] = '\0';
	i = 1;
	while (line)
	{
		if (empty_line(line) == 0)
		{
			tmp = ft_strtrim(line, " \n");
			key = add_key(tmp);
			if (key == 0)
			{
				line = ft_strtrim(line, "\n");
				content()->map[i] = ft_calloc(content()->map_width + 3, sizeof(char));
				if (!content()->map[i])
					return (0);
				content()->map[i][content()->map_width + 2] = '\0';
				if (process_line(line) == 0)
					return (0);
				i++;
			}
		}
		line = get_next_line(fd);
	}
	content()->map[i] = ft_calloc(content()->map_width + 3, sizeof(char));
	content()->map[i][content()->map_width + 2] = '\0';
	return (1);
}

int wall_up_down()
{
	int (i) = 0;
	parse()->len_up = ft_strlen(content()->map[0]) - 1;
	parse()->len_down = ft_strlen(content()->map[content()->map_height - 1]) - 1;
	while (content()->map[1][i])
	{
		if (content()->map[1][i] == ' ')
			i++;
		else if (content()->map[1][i] != '1')
			return (0);
		else
			i++;
	}
	i = 0;
	while (content()->map[content()->map_height + 1][i])
	{
		if (content()->map[content()->map_height + 1][i] == ' ')
			i++;
		else if (content()->map[content()->map_height + 1][i] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}

int skip_space(char *line)
{
	int (i) = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int skip_last_spaces(char *line)
{
	int (i) = ft_strlen(line) - 1;
	while (i > 0 && line[i] == ' ')
		i--;
	return (i);
}

int wall_left_right()
{	
	int (i) = 1;
	int (first); 
	int (last);
	while (i < content()->map_height + 1)
	{
		last = skip_last_spaces(content()->map[i]);

		first = skip_space(content()->map[i]);
		if (content()->map[i][first] != '1'
			|| content()->map[i][last] != '1')
			return (0);
		i++;
	}
	return (1);
}

// int get_last_zero(char *line)
// {
//     int i = ft_strlen(line) - 1;
//     while (i > 0)
//     {
//         if (line[i] == '0')
//             return (i);
//         i--;
//     }
//     return (i);
// }
// int get_len(int i, char *str)
// {
//     int y;

//     if (ft_strcmp(str, "UP"))
//         y = ft_strlen(content()->map[i]) - ft_strlen(content()->map[i - 1]);
//     else
//         y = ft_strlen(content()->map[i]) - ft_strlen(content()->map[i + 1]);
//     return (y); 
// }

// int zero_inside()
// {
//     int (i) = 1;
//     int zero_position;
//     int valid_len_u;
//     int valid_len_d;
//     while (i < content()->map_height - 1)
//     {
//         zero_position = get_last_zero(content()->map[i]);
//         valid_len_u = get_len(i, "UP");
//         valid_len_d = get_len(i, "DOWN");
//         if (zero_position > 0)
//         {
//             if (zero_position > parse()->len_down
//                 && zero_position > parse()->len_up)
//                 {
//                     if (content()->map[i - 1][zero_position] != '1'
//                         && content()->map[i + 1][zero_position] != '1')
//                         if (((valid_len_u != 1 && valid_len_u != -1)
//                             && (valid_len_d != 1 && valid_len_d != -1))
//                             || (valid_len_d == 0 && valid_len_u != 1 && valid_len_u != -1)
//                             || (valid_len_u == 0 && valid_len_d != 1 && valid_len_d != -1))
//                             return (0);
//                 }
//             if (zero_position > ((int)ft_strlen(content()->map[i + 1]) - 1))
//                 return (0);
//         }
//         i++;
//     }
//     return (1);
// }

int up(int i, int y)
{
	int (j) = i - 1;
	if (content()->map[j][y] == 's')
		return (0);
	return (1);
}

int left(int i, int y)
{
	int (j) = y - 1;
	if (content()->map[i][j] == 's')
		return (0);
	return (1);
}

int right(int i, int y)
{
	int (j) = y + 1;
	if (content()->map[i][j] == 's')
		return (0);
	return (1);
}

int down(int i, int y)
{
	int (j) = i + 1;
	if (content()->map[j][y] == 's')
		return (0);
	return (1);
}

int closed()
{
	int (i) = 1;
	
	int (j);
	while (i < content()->map_height + 1)
	{
		j = 1;
		while (content()->map[i][j])
		{
			if (content()->map[i][j] == '0'
				|| content()->map[i][j] == 'N'
				|| content()->map[i][j] == 'S'
				|| content()->map[i][j] == 'E'
				|| content()->map[i][j] == 'W')
			{
				if (up(i, j) == 0)
					return (0);
				if (left(i, j) == 0)
					return (0);
				if (right(i, j) == 0)
					return (0);
				if (down(i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int valid_H_W_walls()
{
	if (content()->map_height <= 2
		|| content()->map_width <= 2)
		return (0);
	if (player_number() == 0)
		return (0);
	if (change_space(0, 0, content()->map_height + 2, content()->map_width + 2) == 0)
		return (0);
	if (closed() == 0)
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
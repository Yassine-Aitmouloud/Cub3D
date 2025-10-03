/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_spaces_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:24:30 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:09:48 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_empty(t_queue *q)
{
	return (q->front > q->back);
}

static bool	**alloc_visited(int height, int width)
{
	bool	**visited;
	int		i;

	visited = gc_malloc(sizeof(bool *) * height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc_algo(width, sizeof(bool));
		if (!visited[i])
			return (NULL);
		i++;
	}
	return (visited);
}

static void	add_if_valid(t_queue *q, bool **visited, int sx, int sy)
{
	t_point	point;

	visited[sx][sy] = true;
	point.x = sx;
	point.y = sy;
	add_in_queue(q, point);
}

static void	process_neighbors(t_queue *q, t_point curr, bool **visited)
{
	const t_point	dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int				i;
	int				sx;
	int				sy;
	char			c;

	i = 0;
	while (i < 4)
	{
		sx = curr.x + dirs[i].x;
		sy = curr.y + dirs[i].y;
		if (sx >= 0 && sx < content()->map_height + 2 && sy >= 0
			&& sy < content()->map_width + 2)
		{
			c = content()->map[sx][sy];
			if (!visited[sx][sy] && c != '1' && c != '0' && c != 'N' && c != 'E'
				&& c != 'W' && c != 'S')
				add_if_valid(q, visited, sx, sy);
		}
		i++;
	}
}

int	change_space(int X, int Y, int height, int width)
{
	t_queue	q;
	t_point	point;
	t_point	curr;
	bool	**visited;

	visited = alloc_visited(height, width);
	if (!visited || init_queue(&q, height * width) == 0)
		return (0);
	point.x = X;
	point.y = Y;
	add_in_queue(&q, point);
	visited[X][Y] = true;
	while (!is_empty(&q))
	{
		curr = out_of_queue(&q);
		if (content()->map[curr.x][curr.y] == ' ')
			content()->map[curr.x][curr.y] = 's';
		process_neighbors(&q, curr, visited);
	}
	return (1);
}

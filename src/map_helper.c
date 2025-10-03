/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:24:39 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:10:14 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	init_map(void)
{
	content()->map = gc_malloc((content()->map_height + 3) * sizeof(char *));
	if (!content()->map)
		return (0);
	content()->map[content()->map_height + 2] = NULL;
	content()->map[0] = gc_malloc((content()->map_width + 3) * sizeof(char));
	if (!content()->map[0])
		return (0);
	ft_memset(content()->map[0], 32, (content()->map_width + 3) * sizeof(char));
	content()->map[0][content()->map_width + 2] = '\0';
	return (1);
}

int	up(int i, int y)
{
	int (j) = i - 1;
	if (content()->map[j][y] == 's')
		return (0);
	return (1);
}

int	init_queue(t_queue *q, int capacity)
{
	q->data = gc_malloc(capacity * sizeof(t_point));
	if (!q->data)
		return (0);
	q->front = 0;
	q->back = -1;
	q->capacity = capacity;
	return (1);
}

void	add_in_queue(t_queue *q, t_point point)
{
	if (q->back == q->capacity - 1)
		return ;
	q->data[++q->back] = point;
}

t_point	out_of_queue(t_queue *q)
{
	return (q->data[q->front++]);
}

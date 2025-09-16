/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:24:20 by abenba            #+#    #+#             */
/*   Updated: 2025/09/16 19:42:34 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	left(int i, int y)
{
	int (j) = y - 1;
	if (content()->map[i][j] == 's')
		return (0);
	return (1);
}

int	right(int i, int y)
{
	int (j) = y + 1;
	if (content()->map[i][j] == 's')
		return (0);
	return (1);
}

int	down(int i, int y)
{
	int (j) = i + 1;
	if (content()->map[j][y] == 's')
		return (0);
	return (1);
}

int	checks(int i, int j)
{
	if (up(i, j) == 0)
		return (0);
	if (left(i, j) == 0)
		return (0);
	if (right(i, j) == 0)
		return (0);
	if (down(i, j) == 0)
		return (0);
	return (1);
}

int	closed(void)
{
	int (i) = 1;
	int (j);
	while (i < content()->map_height + 1)
	{
		j = 1;
		while (content()->map[i][j])
		{
			if (content()->map[i][j] == '0' || content()->map[i][j] == 'N'
				|| content()->map[i][j] == 'S' || content()->map[i][j] == 'E'
				|| content()->map[i][j] == 'W')
			{
				if (checks(i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

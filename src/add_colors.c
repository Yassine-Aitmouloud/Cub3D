/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:48:32 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:09:35 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	count_commas(char *color, int *i)
{
	int (commas) = 0;
	int (digit) = 0;
	while (color[(*i)])
	{
		if (color[(*i)] == ',' && color[(*i) + 1] != '\0')
		{
			if (!digit)
				return (0);
			digit = 0;
			commas++;
			(*i)++;
		}
		else
		{
			if (color[(*i)] != ' ')
				digit = 1;
			(*i)++;
		}
	}
	return (commas);
}

int	add_colors(void)
{
	int (r) = 0;
	int (g) = 0;
	int (b) = 0;
	r = content()->red << 16;
	g = content()->green << 8;
	b = content()->blue;
	return (r | g | b);
}

void	all_colors(char *identifier)
{
	if (!ft_strcmp(identifier, "C"))
		parse()->c++;
	else if (!ft_strcmp(identifier, "F"))
		parse()->f++;
}

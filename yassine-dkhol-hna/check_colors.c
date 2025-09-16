/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:41:12 by abenba            #+#    #+#             */
/*   Updated: 2025/09/16 19:42:39 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	floor_color(char **str)
{
	int (i) = 1;
	while (str[i])
	{
		if (i == 1)
			content()->red = ft_atoi(str[i]);
		else if (i == 2)
			content()->green = ft_atoi(str[i]);
		else if (i == 3)
			content()->blue = ft_atoi(str[i]);
		i++;
	}
	content()->floor_color = add_colors();
}

void	ceiling_color(char **str)
{
	int (i) = 1;
	while (str[i])
	{
		if (i == 1)
			content()->red = ft_atoi(str[i]);
		else if (i == 2)
			content()->green = ft_atoi(str[i]);
		else if (i == 3)
			content()->blue = ft_atoi(str[i]);
		i++;
	}
	content()->ceiling_color = add_colors();
}

int	valid_number(char *color)
{
	int	num;

	int (i) = 0;
	num = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (0);
		i++;
	}
	num = ft_atoi(color);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

int	number_of_commas(char *color, int *commas)
{
	int	i;
	int	len;

	i = 0;
	*commas = 0;
	len = ft_strlen(color);
	if (color[len - 1] == ',')
		return (0);
	while (color[i] == ' ')
		i++;
	if (color[i] == 'C' || color[i] == 'F')
		i++;
	*commas = count_commas(color, &i);
	if (*commas == 0)
		return (0);
	return (*commas);
}

int	check_colors(char *line)
{
	char	**str;
	int		commas;
	int		i;

	i = 1;
	str = NULL;
	number_of_commas(line, &commas);
	if (commas != 2)
		return (0);
	str = ft_split(line, " ,");
	if (!str || ft_arrlen(str) != 4)
		return (0);
	i = 1;
	while (str[i])
	{
		if (valid_number(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_strcmp(str[0], "C") == 0)
		ceiling_color(str);
	else
		floor_color(str);
	all_colors(str[0]);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texturs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:43:34 by abenba            #+#    #+#             */
/*   Updated: 2025/10/03 16:10:23 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_tex(char **tex)
{
	if (!ft_strcmp(tex[0], "NO"))
	{
		content()->no_texture = ft_strdup(tex[1]);
		if (!content()->no_texture)
			return (0);
	}
	else if (!ft_strcmp(tex[0], "SO"))
	{
		content()->so_texture = ft_strdup(tex[1]);
		if (!content()->so_texture)
			return (0);
	}
	else if (!ft_strcmp(tex[0], "WE"))
	{
		content()->we_texture = ft_strdup(tex[1]);
		if (!content()->we_texture)
			return (0);
	}
	else if (!ft_strcmp(tex[0], "EA"))
	{
		content()->ea_texture = ft_strdup(tex[1]);
		if (!content()->ea_texture)
			return (0);
	}
	return (1);
}

void	all_texturs(char *identifier)
{
	if (!ft_strcmp(identifier, "NO"))
		parse()->no++;
	else if (!ft_strcmp(identifier, "SO"))
		parse()->so++;
	else if (!ft_strcmp(identifier, "WE"))
		parse()->we++;
	else if (!ft_strcmp(identifier, "EA"))
		parse()->ea++;
}

int	check_texturs(char *line)
{
	char	**str;

	str = ft_split(line, " ");
	if (!str)
		return (0);
	if (ft_arrlen(str) != 2)
		return (0);
	if (get_tex(str) == 0)
		return (0);
	all_texturs(str[0]);
	return (1);
}

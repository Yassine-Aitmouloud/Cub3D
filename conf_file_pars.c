/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_file_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:22:23 by abenba            #+#    #+#             */
/*   Updated: 2025/07/22 09:42:00 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int check_file_name(char *argv , char *extention)
{
    int		i;
	char	*ext;

	i = 0;
	while (argv[i])
		i++;
	if (i <= 4)
		return (1);
	i -= 5;
	ext = ft_substr(argv, i + 1, ft_strlen(argv));
	if (ft_strcmp(ext, extention) != 0)
	{
		return (1);
	}
	if (argv[i] == '/' || argv[i] == ' ')
	{
		return (1);
	}
	return (0);
}
int get_texture_no(char **str)
{
	if (!str || ft_arrlen(str) != 2)
		return (1);
	content()->no_texture = ft_trim_whitespace(ft_strdup(str[1]));
	if (!content()->no_texture)
	{
		return (1);
	}
	return (0);
}

int get_texture_so(char **str)
{
	if (!str || ft_arrlen(str) != 2)
		return (1);
	content()->so_texture = ft_trim_whitespace(ft_strdup(str[1]));
	if (!content()->so_texture)
	{
		return (1);
	}
	return (0);
}

int get_texture_we(char **str)
{
	if (!str || ft_arrlen(str) != 2)
		return (1);
	content()->we_texture = ft_trim_whitespace(ft_strdup(str[1]));
	if (!content()->we_texture)
	{
		return (1);
	}
	return (0);
}

int get_texture_ea(char **str)
{
	if (!str || ft_arrlen(str) != 2)
		return (1);
	content()->ea_texture = ft_trim_whitespace(ft_strdup(str[1]));
	if (!content()->ea_texture)
	{
		return (1);
	}
	return (0);
}

int check_textures(char *line)
{
	char (**str) = NULL;
	char (*s) = ft_strdup(line);
	if (parse()->flag == 0)
	{
		parse()->no = 0;
		parse()->so = 0;
		parse()->we = 0;
		parse()->ea = 0;
		parse()->flag = 1;
	}
	if (!s)
		return (1);
	char (*tmp) = ft_trim_whitespace(s);
	if (ft_strncmp(tmp, "NO ", 3) == 0)
	{
		parse()->no = 1;
		str = ft_split(tmp, " ");
		if (get_texture_no(str))
			return (1);
	}
	else if (ft_strncmp(tmp, "SO ", 3) == 0)
	{
		parse()->so = 1;
		str = ft_split(tmp, " ");
		if (get_texture_so(str))
			return (1);
	}
	else if (ft_strncmp(tmp, "WE ", 3) == 0)
	{
		parse()->we = 1;
		str = ft_split(tmp, " ");
		if (get_texture_we(str))
			return (1);
	}
	else if (ft_strncmp(tmp, "EA ", 3) == 0)
	{
		parse()->ea = 1;
		str = ft_split(tmp, " ");
		if (get_texture_ea(str))
			return (1); 
	}
	return (0);
}

int get_colors(int *i, char **s)
{
	int (y) = 0;
	char (**str) = ft_split(s[(*i)], ",");
	if (!str)
		return (1);
	while (str[y])
	{
		if (is_num(str[y]))
			return (1);
		if (y == 0)
		{
			content()->red = ft_atoi(str[y]);
			if (content()->red < 0 || content()->red > 255)
				return (1);
		}
		else if (y ==  1)
		{
			content()->green = ft_atoi(str[y]);
			if (content()->green < 0 || content()->green > 255)
				return (1);
		}
		else if (y ==  2)
		{
			content()->blue = ft_atoi(str[y]);
			if (content()->blue < 0 || content()->blue > 255)
				return (1);
		}
		y++;
	}
	return (0);
}
void get_ceiling_color()
{
	int (r) = content()->red << 16;
	int (g) = content()->green << 8;
	int (b) = content()->blue;
	content()->ceiling_color = r | g | b;
}

void get_floor_color()
{
	int (r) = content()->red << 16;
	int (g) = content()->green << 8;
	int (b) = content()->blue;
	content()->floor_color = r | g | b;
}

int check_colors(char *line)
{
	// char (*tmp) = ft_trim_whitespace(line);
	// char (*tmp) = ft_strtrim(line, " ");
	char (**s) = ft_split(line, " ");
	int (i) = 0;
	parse()->flag_c_f = 0;
	if (parse()->flag == 0)
	{
		parse()->c = 0;
		parse()->f = 0;
		parse()->flag_c_f = 1;
	}
	if (s == NULL)
		return (1);
	if ()
	// if (ft_arrlen(s) != 2)
	// 	return (1);
	if (ft_strcmp(s[i] , "C"))
	{
		i++;
		if (get_colors(&i, s))
			return (1);
		parse()->c++;
		get_ceiling_color();
	}
	else if (ft_strcmp(s[i], "F"))
	{
		i++;
		if (get_colors(&i, s))
			return (1);
		parse()->f++;
		get_floor_color();
	}
	return (0);
}

int number_of_commas(char *line)
{
	int (i) = 0;
	int (y) = 0;
	while (line[i])
	{
		if (line[i] == ',' && ft_isdigit(line[i + 1]))
			y++;
		else if (line[i] == ',' && line[i + 1] == '\0')
			return (1);
		else if (line[i] == ',' && line[i + 1] == ',')
			return (1);
		i++;
	}
	if (y != 2)
		return (1);
	return (0);
}

int check_content(int fd)
{
    char (*line) = get_next_line(fd);
	int (key) = 0;
	content()->map_flag = 0;
	parse()->flag = 0;
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		if (ft_empty_line(line, 'N') && content()->map_flag == 0)
		{
			line = get_next_line(fd);
			continue;
		}
		else
		{
			key = add_key(line);
			if (key ==  1 && content()->map_flag == 0)
			{
				if (check_textures(line) == 1)
					return (1);
			}
			else if (key == 2 && content()->map_flag == 0)
			{
				if (number_of_commas(line) == 1 || check_colors(line) == 1)
					return (1);
			}
			else if (key == 0)
			{
				if (content()->tex_num != 4 || content()->colors_num != 2)
					return (1);
				if (!ft_empty_line(line, 'M'))
				{
					content()->map_height++;
					if ((size_t)content()->map_width < (ft_strlen(line)))
						content()->map_width = ft_strlen(line);
				}
				content()->map_flag = 1;
			}
			else
				return (1);
		}
		line = get_next_line(fd);
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:22:10 by abenba            #+#    #+#             */
/*   Updated: 2025/07/22 10:49:50 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
t_content   *content(void)
{
    static t_content content;
    return (&content);
}

t_parse   *parse(void)
{
    static t_parse parse;
    return (&parse);
}

int ft_isspace(int c)
{
    return (c == ' ' || c == '\n');
}

int ft_isspace_n(int c, char d)
{
    if (d == 'M')
        return (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
    else
    return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

char *ft_trim_whitespace(char *str)
{
    char *end;
    
    while (ft_isspace(*str))
        str++;
    end = str + strlen(str) - 1;
    while (end > str && ft_isspace(*end))
        end--;
    *(end + 1) = '\0';
    return (str);
}

int ft_empty_line(const char *line, char c)
{
	int (i) = 0;
    if (line == NULL)
        return (1);
        
    while (line[i])
    {
        if (!ft_isspace_n(line[i], c))
            return (0);
        i++;
    }
    return (1);
}

int add_key(char *line)
{
	char (*str) = ft_strdup(line);
	if (!str)
		return (3);
	char (*tmp) = ft_trim_whitespace(str);
    if (!ft_strncmp(tmp, "NO ", 3) ||
        !ft_strncmp(tmp, "SO ", 3) ||
        !ft_strncmp(tmp, "WE ", 3) ||
        !ft_strncmp(tmp, "EA ", 3))
    {
        content()->tex_num += 1;
        return (1);
    }
    else if (!ft_strncmp(tmp, "F ", 2) ||
        !ft_strncmp(tmp, "C ", 2))
    {
        content()->colors_num += 1; 
        return (2);
    }
    else if (ft_strchr(" 01NSEW", *tmp))
        return (0);
    return (3);
}

size_t ft_arrlen(char **str)
{
    size_t (i) = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int	is_num(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (1);
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void error(char *msg)
{
    write(2, msg, ft_strlen(msg));
    gc_collect();
    exit(1);
}

void print_map()
{
    int (i) = 0;
    while (content()->map[i])
    {
        printf("%s\n", content()->map[i]);
        i++;
    }
}

int ft_rep_tex()
{
    if (parse()->no != 1
        || parse()->so != 1
        || parse()->we != 1
        || parse()->ea != 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
    {
        printf("cub3D [map]\n");
        return (1);
    }
    if (check_file_name(av[1], ".cub") == 1)
        error("Error\nmust end with .cub\n");
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (1); 
    if (check_content(fd) == 1)
        error("Error\nNot a valid content\n");
    if (ft_rep_tex())
        error("Error\nNot a valid content\n");
    if (content()->map_height <= 2 || content()->map_width <= 2)
        error("Error\nNot a valid map\n");
    close(fd);
    fd = open(av[1], O_RDONLY);
    if (parse_map(fd) == 1)
        error("Error\nNot a valid map\n");
    // if (valid_map() == 1)
    //     error("Error\nNot a valid map\n");
    // printf("height: %d, width: %d\n", content()->map_height, content()->map_width);
    // printf("%s, %s, %s, %s\n", content()->no_texture, content()->so_texture, content()->ea_texture, content()->we_texture);
    // printf("%d, %d\n", content()->ceiling_color, content()->floor_color);
    print_map();
    close(fd);
    gc_collect();
    return (0);
}
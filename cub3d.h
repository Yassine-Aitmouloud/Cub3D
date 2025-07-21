/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:22:06 by abenba            #+#    #+#             */
/*   Updated: 2025/07/21 14:40:41 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"

typedef struct file_content
{
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    int floor_color;
    int ceiling_color;
    char **map;
    int map_width;
    int map_height;
    int map_flag;
    int tex_num;
    int colors_num;
    int red;
    int green;
    int blue;
} t_content;

int check_file_name(char *argv , char *extention);
void error(char *msg);
int check_content(int fd);
int ft_empty_line(const char *line);
t_content   *content(void);
int add_key(char *line);
char *ft_trim_whitespace(char *str);
void free_split_array(char **arr);
size_t ft_arrlen(char **str);
int	is_num(char *arg);
int ft_isspace_not(int c);


# endif
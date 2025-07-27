/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:22:06 by abenba            #+#    #+#             */
/*   Updated: 2025/07/27 14:47:56 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"

typedef struct t_GC
{
    void *ptr;
    struct t_GC *next;
} t_garcol;


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
    int red;
    int green;
    int blue;
    t_garcol *g_head;
    int x;
    int y;
} t_content;

typedef struct s_parse 
{
    int no;
    int so;
    int we;
    int ea;
    int c;
    int f;
    int map_flag;
    int flag_c_f;
    int flag;
	int tex_num;
    int colors_num;
    int map_end;
    int wall_len;
    int len_up;
    int len_down;
} t_parse;

// int check_file_name(char *argv , char *extention);
void		error(char *msg);
int			check_file(char *file);
int			valid_name(char *file , char *extention);
t_content	*content();
t_parse 	*parse();
void		*gc_malloc(size_t size);
void		gc_collect(void);
int			check_texturs(char *line);
int			empty_line(char *line);
int			add_key(char *line);
int			valid_content(char *file);
int			check_texturs(char *line);
int         check_colors(char *line);
void        floor_color(char **str);
int         valid_map(char *file);
int         player_number();
int         valid_H_W_walls();
// int check_content(int fd);
// int ft_empty_line(const char *line, char c);
// t_content   *content(void);
// int add_key(char *line);
// char *ft_trim_whitespace(char *str);
// size_t ft_arrlen(char **str);
// int	is_num(char *arg);
// int parse_map(int fd);
// void	gc_register(void *ptr);
// void	*gc_malloc(size_t size);
// void	gc_collect(void);
// t_parse   *parse(void);
// int invalid_char();
// int valid_map();

# endif
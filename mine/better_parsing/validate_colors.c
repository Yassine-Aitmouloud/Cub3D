/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:48:32 by abenba            #+#    #+#             */
/*   Updated: 2025/07/27 14:23:36 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int number_of_commas(char *color)
{
    int i;
    int commas;
    int digit;
    int len;
    int end_with_comma;

    i = 0;
    commas = 0;
    digit = 0;
    end_with_comma = 0;
    len = ft_strlen(color);
    if (color[len - 1] == ',')
        end_with_comma = 1;
    while (color[i] == ' ')
        i++;
    if (color[i] == 'C' || color[i] == 'F')
        i++;
    while (color[i])
    {
        if (color[i] == ',' && color[i + 1] != '\0')
        {
            if (!digit)
                return (0);
            digit = 0;
            commas++;
            i++;
        }
        else
        {
            if (color[i] != ' ')
                digit = 1;
            i++;
        }
    }
    return (commas + end_with_comma);
}

int valid_number(char *color)
{
    int (i) = 0;
    int num;

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
int add_colors()
{
    int (r) = 0;
    int (g) = 0;
    int (b) = 0;
    
    r = content()->red << 16;
    g = content()->green << 8;
    b = content()->blue;
    return (r | g | b);
}

void ceiling_color(char **str)
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

void floor_color(char **str)
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

void all_colors(char *identifier)
{
    if (!ft_strcmp(identifier, "C"))
        parse()->c++;
    else if (!ft_strcmp(identifier, "F"))
        parse()->f++;
}

int check_colors(char *line)
{
    int commas;
    int i;
    
    commas = 0;
    i = 1;
    char (**str) = NULL;
    commas = number_of_commas(line);
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

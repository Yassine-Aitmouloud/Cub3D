/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:13:58 by abenba            #+#    #+#             */
/*   Updated: 2024/12/18 17:51:50 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*fill_buffer(int fd, char *left, char *buffer)
{
	int		chr_read;
	char	*tmp;

	chr_read = 1;
	while ((chr_read))
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read == -1)
		{
			left = NULL;
			break ;
		}
		if (chr_read == 0)
			break ;
		buffer[chr_read] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(tmp, buffer);
		if (ft_strchr(left, '\n'))
			break ;
	}
	return (buffer = NULL, left);
}

char	*make_line(char *left, char **line)
{
	int		i;

	i = 0;
	while (left[i] != '\n' && left[i] != '\0')
		i++;
	if (left && left[i] == '\0')
	{
		if (left[0] == '\0')
			*line = NULL;
		else
			*line = ft_strdup(left);
		left = NULL;
	}
	else if (left)
	{
		*line = ft_substr(left, 0, i + 1);
		left = ft_substr(left, i + 1, ft_strlen(left) - i);
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (left = NULL, NULL);
	buffer = (char *)gc_malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	left = fill_buffer(fd, left, buffer);
	if (!left)
		return (NULL);
	left = make_line(left, &line);
	return (line);
}

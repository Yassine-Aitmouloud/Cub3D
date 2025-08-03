/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:58:19 by abenba            #+#    #+#             */
/*   Updated: 2025/08/03 14:52:54 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_word(char const *s, char *c, size_t *i)
{
	size_t	word;
	size_t	y;
    size_t  t;
	char	*ptr;

	word = 0;
    while (s[(*i)])
	{
        t = 0;
		while (c[t])
        {
            if (s[(*i)] != c[t])
            {
                t++;
            }
            else
                break ;
        }
        if (ft_strlen(c) != t)
            break;
        (*i)++;
        word++;
    }
	*i = *i - word;
	y = 0;
	ptr = (char *)gc_malloc(word + 1);
	if (!ptr)
		return (NULL);
    while (s[(*i)])
	{
        t = 0;
		while (c[t])
        {
            if (s[(*i)] != c[t])
            {
                t++;
            }
            else
                break ;
        }
        if (ft_strlen(c) != t)
            break;
        ptr[y] = s[(*i)];
		(*i)++;
		y++;
    }
	ptr[y] = '\0';
	(*i)++;
	return (ptr);
}

size_t	ft_count_word(char const *s, char *c)
{
	size_t	i;
	size_t	count;
	size_t j;
	int		in_word;
	int is_delimiter;

	i = 0;
	count = 0;
	in_word = 0;
	is_delimiter = 0;
	
	while (s[i])
	{
		j = 0;
		while (c[j])
		{
			if (s[i] == c[j])
			{
				is_delimiter = 1;
				break;
			}
			j++;
		}
		
		if (!is_delimiter && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_delimiter)
		{
			in_word = 0;
			is_delimiter = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_make(char const *s, char *c, char **ptr, size_t len)
{
	size_t	y;
	size_t	i;
    size_t  t;

	y = 0;
	i = 0;
	while (y < len)
	{
        t = 0;
		while (c[t])
        {
            if (s[i] == c[t])
            {
                t = 0;
                i++;
            }
            else
                t++;
        }
		ptr[y] = ft_word(s, c, &i);
		if (ptr[y] == NULL)
		{
			return (NULL);
		}
		y++;
	}
	ptr[y] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char *c)
{
	size_t	len;
	char	**ptr;

	if (!s)
		return (NULL);
	len = ft_count_word(s, c);
	ptr = (char **)gc_malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	return (ft_make(s, c, ptr, len));
}

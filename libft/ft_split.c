/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:58:19 by abenba            #+#    #+#             */
/*   Updated: 2025/09/15 15:41:01 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_word_count(int *in_word, int *is_delimiter, size_t *count)
{
	if (!(*is_delimiter) && !(*in_word))
	{
		(*count)++;
		*in_word = 1;
	}
	else if (*is_delimiter)
	{
		*in_word = 0;
		*is_delimiter = 0;
	}
}

size_t	ft_count_word(char const *s, char *c)
{
	size_t	i;
	size_t	count;
	int		in_word;
	int		is_deli;

	i = 0;
	count = 0;
	in_word = 0;
	is_deli = 0;
	while (s[i])
	{
		is_deli = is_delimiter(s[i], c);
		update_word_count(&in_word, &is_deli, &count);
		i++;
	}
	return (count);
}

static void	skip_delimiters(char const *s, char *c, size_t *i)
{
	size_t	t;

	while (s[*i])
	{
		t = 0;
		while (c[t])
		{
			if (s[*i] == c[t])
			{
				t = 0;
				(*i)++;
			}
			else
				t++;
		}
		if (!is_delimiter(s[*i], c))
			break ;
	}
}

char	**ft_make(char const *s, char *c, char **ptr, size_t len)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	while (y < len)
	{
		skip_delimiters(s, c, &i);
		ptr[y] = ft_word(s, c, &i);
		if (ptr[y] == NULL)
			return (NULL);
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

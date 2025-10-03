/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:40:23 by abenba            #+#    #+#             */
/*   Updated: 2025/09/15 15:40:25 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_delimiter(char ch, char *c)
{
	size_t	t;

	t = 0;
	while (c[t])
	{
		if (ch == c[t])
			return (1);
		t++;
	}
	return (0);
}

size_t	find_word_length(char const *s, char *c, size_t *i)
{
	size_t	word;

	word = 0;
	while (s[(*i)])
	{
		if (is_delimiter(s[(*i)], c))
			break ;
		(*i)++;
		word++;
	}
	return (word);
}

char	*extract_word(char const *s, char *c, size_t *i, size_t word_len)
{
	size_t	y;
	char	*ptr;

	*i = *i - word_len;
	y = 0;
	ptr = (char *)gc_malloc(word_len + 1);
	if (!ptr)
		return (NULL);
	while (s[(*i)] && !is_delimiter(s[(*i)], c))
	{
		ptr[y] = s[(*i)];
		(*i)++;
		y++;
	}
	ptr[y] = '\0';
	(*i)++;
	return (ptr);
}

char	*ft_word(char const *s, char *c, size_t *i)
{
	size_t	word_len;

	word_len = find_word_length(s, c, i);
	return (extract_word(s, c, i, word_len));
}

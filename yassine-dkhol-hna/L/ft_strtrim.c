/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:28 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/09 18:07:51 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	endstr(const char *s1, char const *set)
{
	size_t	end;
	int		i;

	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[end])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		end--;
	}
	return (end);
}

static size_t	startstr(const char *s1, char const *set)
{
	size_t	start;
	int		i;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[start])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		start++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = startstr(s1, set);
	end = endstr(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	len = (end - start) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s1[start++];
	str[len] = '\0';
	return (str);
}

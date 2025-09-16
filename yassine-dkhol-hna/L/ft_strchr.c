/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:20:38 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/10 20:18:14 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

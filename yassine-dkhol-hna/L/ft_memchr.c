/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:21:33 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/09 23:18:21 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*f;

	i = 0;
	f = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == (unsigned char)f[i])
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:17:50 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/10 03:17:35 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p1;

	p1 = (unsigned char *)s2;
	p = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)p[i] != (unsigned char)p1[i])
			return (p[i] - p1[i]);
		i++;
	}
	return (0);
}

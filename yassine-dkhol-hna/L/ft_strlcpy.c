/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:20 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/10 20:24:07 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lensrc);
	if (dstsize <= lensrc)
		dstsize = dstsize - 1;
	while (i < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lensrc);
}

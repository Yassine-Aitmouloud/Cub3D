/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:16 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/10 18:23:15 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;
	size_t	dstsa;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (dstsize <= lendst)
		return (dstsize + lensrc);
	i = 0;
	dstsa = dstsize - lendst - 1;
	while (i < dstsa && src[i])
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}

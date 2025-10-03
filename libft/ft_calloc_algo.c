/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <abenba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:12:33 by anas              #+#    #+#             */
/*   Updated: 2025/09/15 15:13:53 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_algo(size_t count, size_t size)
{
	size_t	s;
	void	*ptr;

	if (count != 0 && (__SIZE_MAX__ / count < size))
		return (NULL);
	s = count * size;
	ptr = gc_malloc(s);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, s);
	return (ptr);
}

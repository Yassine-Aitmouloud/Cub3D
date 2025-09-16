/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:13 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/11/10 17:37:40 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	lenmalloc;
	size_t	lenfors2;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	i = 0;
	lenfors2 = 0;
	lenmalloc = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(sizeof(char) * (lenmalloc + 1));
	if (!string)
		return (NULL);
	while (i < lenmalloc && s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[lenfors2] != '\0' && i < lenmalloc)
		string[i++] = s2[lenfors2++];
	string[lenmalloc] = '\0';
	return (string);
}

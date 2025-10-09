/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniki <aniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:23:01 by abenba            #+#    #+#             */
/*   Updated: 2025/10/09 19:52:38 by aniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	gc_register(void *ptr)
{
	t_garcol	*node;

	if (!ptr)
		return ;
	node = malloc(sizeof(t_garcol));
	if (!node)
		return ;
	node->ptr = ptr;
	node->next = content()->g_head;
	content()->g_head = node;
}

void	*gc_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc((size_t)size);
	if (!ptr)
		return (NULL);
	gc_register(ptr);
	return (ptr);
}

void	gc_collect(void)
{
	t_garcol	*current;
	t_garcol	*next;

	current = content()->g_head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	content()->g_head = NULL;
}

void	clear_textures(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_game()->textures[i].img)
		{
			mlx_destroy_image(g_game()->mlx, g_game()->textures[i].img);
			g_game()->textures[i].img = NULL;
			g_game()->textures[i].pixels = NULL;
		}
		i++;
	}
}

#include "../includes/cub.h"


int get_the_vue(char **map,int i, int j)
{
    if (!map)
        return (1);
    if (map[i][j] == 'S')
        return (g_game()->player.vue = SOUTH, 0);
    if (map[i][j] == 'N')
        return(g_game()->player.vue = NORTH, 0);
    if (map[i][j] == 'W')
        return (g_game()->player.vue = WEST, 0);
    if (map[i][j] == 'E')
        return (g_game()->player.vue = EAST, 0);
    return (1);
}

void	find_player_position(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (get_the_vue(map,i,j) == 0)
			{
				g_game()->player.x = j;
				g_game()->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

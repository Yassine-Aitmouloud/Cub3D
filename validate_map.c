#include "cub3d.h"

int invalid_char()
{
    int (player_flag) = 0;
    int (i) = 0;
    int y;
    while (content()->map[i])
    {
        y = 0;
        while (content()->map[i][y])
        {
            if (content()->map[i][y] == 'S'
                || content()->map[i][y] == 'N'
                || content()->map[i][y] == 'W'
                || content()->map[i][y] == 'E')
                player_flag++;
            else if (!ft_strchr(" 01", content()->map[i][y]))
                return (1);
            y++;
        }
        i++;
    }
    if (player_flag != 1)
        return (1);
    return (0);
}

void player_position()
{
    content()->y = 0;
    while (content()->map[content()->y])
    {
        content()->x = 0;
        while (content()->map[content()->y][content()->x])
        {
            if (content()->map[content()->y][content()->x] == 'S'
                || content()->map[content()->y][content()->x] == 'N'
                || content()->map[content()->y][content()->x] == 'W'
                || content()->map[content()->y][content()->x] == 'E')
                break ;
            content()->x++;
        }
        if (content()->map[content()->y][content()->x] == 'S'
                || content()->map[content()->y][content()->x] == 'N'
                || content()->map[content()->y][content()->x] == 'W'
                || content()->map[content()->y][content()->x] == 'E')
                break ;
        content()->y++;
    }
}

void flood_fill(int x, int y)
{
    if (x < 0 || y < 0 || x > content()->map_width + 2 || y > content()->map_height + 2)
        return ;
    if (content()->map[y][x] == 'K'
        || content()->map[y][x] == '1'
        || content()->map[y][x] == ' '
        || content()->map[y][x] == 'f')
        return ;
    content()->map[y][x] = 'f';
    flood_fill((x - 1), y);
    flood_fill(x, (y - 1));
    flood_fill((x + 1), y);
    flood_fill(x, (y + 1));
}

// int check_map_bounds()
// {
//     int (i) = 0;
//     while (content()->map[1][i])
//     {

//     }
// }

int valid_map()
{
    player_position();
    // if (check_map_bounds() == 1)
    //     return (1);
    // flood_fill(content()->x, content()->y);
    return (0);
}
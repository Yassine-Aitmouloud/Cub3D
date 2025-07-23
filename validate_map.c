#include "cub3d.h"

int invalid_char(char *line)
{
    char *str = ft_trim_whitespace(line);
    printf("%s\n", str);
    int (player_flag) = 0;
    int (i) = 0;
    while (str[i])
    {
        if (str[i] == 'S'
            || str[i] == 'N'
            || str[i] == 'W'
            || str[i] == 'E')
            player_flag++;
        else if (!ft_strchr("01", str[i]))
            return (1);
        i++;
    }
    if (player_flag != 1)
        return (1);
    return (0);
    // int (player_flag) = 0;
    // int (i) = 0;
    // int y;
    // while (content()->map[i])
    // {
    //     y = 0;
    //     while (content()->map[i][y])
    //     {
    //         if (content()->map[i][y] == 'S'
    //             || content()->map[i][y] == 'N'
    //             || content()->map[i][y] == 'W'
    //             || content()->map[i][y] == 'E')
    //             player_flag++;
    //         else if (!ft_strchr(" 01", content()->map[i][y]))
    //             return (1);
    //         y++;
    //     }
    //     i++;
    // }
    // if (player_flag != 1)
    //     return (1);
    // return (0);
}

// int valid_map()
// {
//     int (x);
//     int (y) = 0;

//     while (content()->map[y])
//     {
//         x = 0;
//         while (content()->map[y][x])
//         {

//         }
//     }
// }
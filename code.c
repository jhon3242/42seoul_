/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bsqMain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:20:47 by kipark            #+#    #+#             */
/*   Updated: 2021/09/28 18:38:54 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"utility.h"

typedef struct t_board_values {
	int	size_y;
	int	size_x;
	int	max_y;
	int	max_x;
	int	answer;
}	t_board_values;

char char_board[100][100] = {
      "i...i"
};

int	vm(int a, int b, int c)
{
	int	min;

	min = 99999999;
	if (min > a)
		min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	set_dp_board(char **in_board, int **dp, t_board_values bv, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < bv.size_y)
		while (++j < bv.size_x)
			dp[i][j] = 0;
	i = 0;
	while (i < bv.size_y - 1)
	{
		j = 0;
		while (j < bv.size_x - 1)
		{
			if (in_board[i][j] == map->empty)
			{
				dp[i + 1][j + 1] = 1;
			}
			++j;
		}
		++i;
	}
}

struct t_board_values	play_dp(int **db, t_board_values bv)
{
	int	i;
	int	j;

	i = 1;
	while (i < bv.size_y)
	{
		j = 1;
		while (j < bv.size_x)
		{
			if (db[i][j] == 1)
			{
				db[i][j] = 1 + vm(db[i - 1][j - 1], db[i - 1][j], db[i][j - 1]);
				if (bv.answer < db[i][j])
				{
					bv.answer = db[i][j];
					bv.max_y = i;
					bv.max_x = j;
				}
			}
			++j;
		}
		++i;
	}
	return (bv);
}

char	**solution(char **in_board, int **db, t_board_values bv, t_map *mapinfo)
{
	int	i;
	int	j;

	set_dp_board(in_board, db, bv, mapinfo);
	bv = play_dp(db, bv);
	i = 0;
	while (i < bv.answer)
	{
		j = 0;
		while (j < bv.answer)
		{
			in_board[bv.max_y - i - 1][bv.max_x - j - 1] = mapinfo->area;
			++j;
		}
		++i;
	}
	return (in_board);
}

void	find_square(char **map, t_map *mapinfo)
{
	t_board_values	bv;
	int				**dp_board;
	int				i;

	bv.size_y = mapinfo -> height + 1;
	bv.size_x = mapinfo -> width + 1;
	dp_board = (int **)malloc(sizeof(int *) * (bv.size_y));
	if (!dp_board)
		return ;
	i = 0;
	while (i < bv.size_y)
	{
		dp_board[i] = (int *)malloc(sizeof(int) * (bv.size_x));
		if (!dp_board[i])
			return ;
		++i;
	}
	solution(map, dp_board, bv, mapinfo);
	i = -1;
	while (++i < bv.size_y)
		free(dp_board[i]);
	free(dp_board);
}

int main()
{
    char** input_char_board;
    int i;

    t_map mapinfo;
    mapinfo.height = 1;
    mapinfo.width = 6;
    mapinfo.empty = '.';
    mapinfo.obstacle = 'o';
    mapinfo.area = 'x';
    t_map* mamae = &mapinfo;
    input_char_board = (char**)malloc(sizeof(char*) * (mapinfo.height));
    if (!input_char_board)
    {
        return (0);
    }
    i = 0;
    while (i < mapinfo.height)
    {
        input_char_board[i] = (char*)malloc(sizeof(char) * (mapinfo.width));
        ++i;
    }

    for (int i = 0; i < mapinfo.height; ++i) {
        for (int j = 0; j < mapinfo.width; ++j) {
            printf("%c", char_board[i][j]);
            input_char_board[i][j] = char_board[i][j];
        }
        printf("\n");
    }

    find_square(input_char_board, mamae);


    for (int i = 0; i < mapinfo.height; ++i) {
        for (int j = 0; j < mapinfo.width; ++j) {
            printf("%c", input_char_board[i][j]);
        }
        printf("\n");
    }

}
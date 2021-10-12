#include<stdlib.h>

typedef struct t_board_values {
	int	size_y;
	int	size_x;
	int	max_y;
	int	max_x;
	int	answer;
}	t_board_values;

typedef struct s_map {
	int 	height;
	int		width;
	char	empty;
	char	obstacle;
	char	area;
}	t_map;

void	find_square(char **map, t_map *map)
{
	t_board_values	bv;
	int				**dp_board;
	int				i;


}

int main()
{
	char** input_char_board;
	int i;
	int	j;

	t_map map;
	map.height = 1;
	map.width = 6;
	map.empty = '.';
	map.obstacle = 'o';
	map.area = 'x';
	t_map* mamae = &map;
	input_char_board = (char**)malloc(sizeof(char*) * (map.height));
	if (!input_char_board)
		return (0);
	i = 0;
	while (i < map.height)
	{
		input_char_board[i] = (char*)malloc(sizeof(char) * (map.width));
		++i;
	}
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			write(1, &char_board[i][j], 1);
			input_char_board[i][j] = char_board[i][j];
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

	find_square(input_char_board, mamae);

}

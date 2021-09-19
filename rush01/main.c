#include <stdlib.h>
#include <stdio.h>
int	*g_list;
int	g_size;
int	g_count;

void	permutation(int n1, int now);
int	**f(int a1, int a2);
int	main(void)
{
	int	**cor_arr;
	g_size = 0;
	g_list = (int *)malloc(sizeof(int) * 24);
	permutation(1234, 0); // g_list에 24개의 숫자를 넣어줌
	cor_arr = f(2, 3); // 조건에 맞는 숫자를 담고 있는 배열
	int	i = 1;
	int	j = 0;
	while (i <= g_count)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", cor_arr[i][j++]);
		}
		i++;
		printf("\n");
	}
	return (0);
}

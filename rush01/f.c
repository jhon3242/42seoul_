//function.c
#include <stdlib.h>
#include <stdio.h>

extern int	*g_list;
extern int	g_size;
extern int	g_count;

char	*nb_to_arr(int nb)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * 5);
	while (nb)
	{
		p[i] = (nb % 10) + '0' ;
		i++;
		nb /= 10;
	}
	p[i] = 0;
	return (p);
}

void	permutation(int n1, int now)
{
	int	a;
	int	tic;

	a = 1;
	tic = 0;
	while (n1 / a > 0)
	{
		if (n1 / a % 10)
		{
			permutation(n1 - (n1 / a % 10) * a, 10 * now + (n1 / a % 10));
			tic = 1;
		}
		a = a * 10;
	}
	if (!tic)
	{
		g_list[g_size] = now;
		g_size++;
	}

	return ;
}

int	*look(int n1)
{
	int	a1;
	int	a2;
	int	a;
	int	c;
	int	max;
	int	*arr;

	a = 1;
	max = 0;
	c = 0;
	while (n1 / a > 0)
	{
		if ((n1 / a % 10) > max)
			max = (n1 / a % 10), c++;
		a *= 10;
	}
	a2 = c;
	max = 0;
	c = 0;
	while (a > 0)
	{
		if ((n1 / a % 10) > max)
			max = (n1 / a % 10), c++;
		a /= 10;
	}
	a1 = c;
	arr = malloc(sizeof(int) * 2);
	arr[0] = a1;
	arr[1] = a2;
	return (arr);
}

int	* make_list(int a1, int a2) // {1234,1243} 과 같이 조건에 맞는 숫자 배열을 리턴
{
	int i;
	int *tmp;
	int *ret;
	int count;

	ret = (int *)malloc(sizeof(int) * 24); // 몇개가 들어갈지 모르는데 최대 24개이니까 24라고 넣어줌
	i = 0;
	count = 0; // 조건에 맞는 숫자 개수
	while (i < g_size)
	{
		tmp = look(g_list[i]);
		if (tmp[0] == a1 && tmp[1] == a2)
			ret[count++] = g_list[i];//조건에 맞는 g_list[i] 를 넣어줌
		i++;
	}
	g_count = count;
	return (ret);
}

int	**f(int a1, int a2)
{
	int *list;
	int **ret;
	int *arr;
	int i;

	list = make_list(a1, a2);
	ret = (int **)malloc(sizeof(int *) * (g_count + 1));
	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = 1;
	arr[1] = 4; // 4~9
	arr[2] = g_count; // 케이스 수
	arr[3] = 0;
	ret[0] = arr;
	i = 0;
	while (++i <= g_count)
	{
		arr = malloc(sizeof(int) * 4);
		ret[i] = arr;
		ret[i][0] = list[i - 1] / 1000;
		ret[i][1] = list[i - 1] / 100 % 10;
		ret[i][2] = list[i - 1] / 10 % 10;
		ret[i][3] = list[i - 1] % 10;
	}
	return (ret);
}
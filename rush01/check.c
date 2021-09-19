#include<stdlib.h>
#include<stdio.h>

char	g_argv[16];
int		*g_list;
int		g_size;
int		g_count;
int		**f(int a1, int a2);

char	*check(char *bo);

char	*init_board(int n)
{
	int		a;
	char	*board;

	board = (char *) malloc(sizeof(char) * 100);
	board[0] = '1';
	board[1] = n + '0';
	board[2] = '0';
	board[3] = '0';
	a = 3;
	while (a++ < 100)
	{
		board[a] = '0';
	}
	return (board);
}

int	cal(int w, int c, int n)
{
	if (n == 1)
	{
		c -= '0';
		w -= '0';
		return (g_argv[(c % 2 * 2 * w) + (c / 2)] - '0');
	}
	else if (n == 2)
	{
		c -= '0';
		w -= '0';
		return (g_argv[(c % 2 * 2 * w) + (c / 2) + w] - '0');
	}
	else if (n == 3)
	{
		c -= '0';
		return (w * (1 + (c + 1) % 2 * 3) + (c / 2) * 4 + 4);
	}
	return (0);
}

char	*ft_strcpy(char *d, char *s)
{
	if (*s == 0)
	{
		*d = *s;
		return (d);
	}
	else
	{
		*d = *s;
		ft_strcpy(d + 1, s + 1);
	}
	return (d);
}

char	*go_check(int *p, char *bo)
{
	int		b;
	char	*s;
	char	*rst;

	printf("go_check_%d", bo[2] - '0');
	s = (char *) malloc(sizeof(char) * 100);
	ft_strcpy(s, bo);
	b = -1;
	while (b++ < 3)
		s[cal(b, s[2], 3)] = p[b];
	s[2] += 1;
	rst = check(s);
	free(s);
	if (rst[3])
		return (rst);
	else
		return (bo);
}

char	*check(char *bo)
{
	int		**p;
	char	*rst;
	int		a;
	int		b;
	int		t;

	printf("check_%d", bo[2] - '0');
	p = f(cal(bo[1], bo[2], 1), cal(bo[1], bo[2], 2));
	a = -1;
	t = 1;
	while (a++ < p[0][2])
	{
		b = -1;
		while (b++ < 3)
			if (p[a][b] != bo[cal(b, bo[2], 3)] && bo[cal(b, bo[2], 3)])
				t = 0;
		if (t)
			rst = go_check(p[a], bo);
		if (rst[3])
			return (rst);
	}
	return (bo);
}

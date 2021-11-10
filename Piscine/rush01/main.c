//main.c

#include <stdlib.h>

char	g_argv[16] = "4321122243211222";
int		*g_list;
int		g_size;
int		g_count;

void	permutation(int n1, int now);
int		**f(int a1, int a2);
char	*init_board(int n);
char	*check(char *board);

void	init()
{
	g_size = 0;
	g_list = (int *)malloc(sizeof(int) * 24);
	permutation(1234, 0); // g_list에 24개의 숫자를 넣어줌
}

int	main(void)
{
	init();
	char *s;
	s = check("140012340000000000000000");
	printf("%s", s);
	printf("qwe");
	return (0);
	
}
	
